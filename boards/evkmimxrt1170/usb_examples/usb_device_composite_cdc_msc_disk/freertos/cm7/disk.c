/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2017, 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdlib.h>
/*${standard_header_anchor}*/
#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"

#include "usb_device_class.h"
#include "usb_device_msc.h"
#include "usb_device_ch9.h"
#include "usb_device_descriptor.h"
#include "disk.h"

#include "usb_disk_adapter.h"
#include "fsl_device_registers.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "composite.h"

#if (USB_DEVICE_CONFIG_USE_TASK < 1)
#error This application requires USB_DEVICE_CONFIG_USE_TASK value defined > 0 in usb_device_config.h. Please recompile with this option.
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static usb_device_composite_struct_t *g_deviceComposite;
USB_DMA_INIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
usb_device_inquiry_data_fromat_struct_t g_InquiryInfo = {
    (USB_DEVICE_MSC_UFI_PERIPHERAL_QUALIFIER << USB_DEVICE_MSC_UFI_PERIPHERAL_QUALIFIER_SHIFT) |
        USB_DEVICE_MSC_UFI_PERIPHERAL_DEVICE_TYPE,
    (uint8_t)(USB_DEVICE_MSC_UFI_REMOVABLE_MEDIUM_BIT << USB_DEVICE_MSC_UFI_REMOVABLE_MEDIUM_BIT_SHIFT),
    USB_DEVICE_MSC_UFI_VERSIONS,
    0x02,
    USB_DEVICE_MSC_UFI_ADDITIONAL_LENGTH,
    {0x00, 0x00, 0x00},
    {'N', 'X', 'P', ' ', 'S', 'E', 'M', 'I'},
    {'N', 'X', 'P', ' ', 'M', 'A', 'S', 'S', ' ', 'S', 'T', 'O', 'R', 'A', 'G', 'E'},
    {'0', '0', '0', '1'}};
USB_DMA_INIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
usb_device_mode_parameters_header_struct_t g_ModeParametersHeader = {
    /*refer to ufi spec mode parameter header*/
    0x0000, /*!< Mode Data Length*/
    0x00,   /*!<Default medium type (current mounted medium type)*/
    0x00,   /*!MODE SENSE command, a Write Protected bit of zero indicates the medium is write enabled*/
    {0x00, 0x00, 0x00, 0x00} /*!<This bit should be set to zero*/
};

USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE) uint32_t g_mscReadRequestBuffer[USB_DEVICE_MSC_READ_BUFF_SIZE >> 2];
#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))

USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
uint32_t g_mscWriteRequestBuffer[USB_DEVICE_MSC_WRITE_BUFF_NUM][USB_DEVICE_MSC_WRITE_BUFF_SIZE >> 2];
#else

USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE) uint32_t g_mscWriteRequestBuffer[USB_DEVICE_MSC_WRITE_BUFF_SIZE >> 2];

#endif

#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))
void *g_writeBufferHandle;
void *g_writeTaskHandle;
TaskHandle_t g_usbWriteTaskHandle;
SemaphoreHandle_t g_xMutex;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))
/*!
 * @brief device msc write task function.
 *
 * This function write data to the sdcard.
 * @param handle          The write task parameter.
 */
void USB_DeviceMscWriteTask(void *Handle)
{
    uint32_t writeInformationa[3];
    status_t errorCode;
    while (1)
    {
        xQueueReceive(g_writeTaskHandle, &writeInformationa, portMAX_DELAY);
        xSemaphoreTake(g_xMutex, portMAX_DELAY);
        errorCode = USB_Disk_WriteBlocks((uint8_t *)writeInformationa[0], writeInformationa[1],
                                         writeInformationa[2] >> USB_DEVICE_SDCARD_BLOCK_SIZE_POWER);
        xSemaphoreGive(g_xMutex);
        if (kStatus_Success != errorCode)
        {
            g_deviceComposite->mscDisk.readWriteError = 1;
            usb_echo(
                "Write error, error = 0xx%x \t Please check write request buffer size(must be less than 128 "
                "sectors)\r\n",
                errorCode);
        }
        xQueueSend(g_writeBufferHandle, &writeInformationa[0], 0U);
    }
}

#endif
/*!
 * @brief device msc callback function.
 *
 * This function handle the disk class specified event.
 * @param handle          The USB class  handle.
 * @param event           The USB device event type.
 * @param param           The parameter of the class specific event.
 * @return kStatus_USB_Success or error.
 */
usb_status_t USB_DeviceMscCallback(class_handle_t handle, uint32_t event, void *param)
{
    usb_status_t error = kStatus_USB_Success;
    status_t errorCode = kStatus_Success;
    usb_device_lba_information_struct_t *lbaInformation;
    usb_device_lba_app_struct_t *lba;
    usb_device_ufi_app_struct_t *ufi;
    usb_device_capacity_information_struct_t *capacityInformation;

#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))
    uint32_t writeInformation[3];
    uint32_t tempbuffer;
#endif
    switch (event)
    {
        case kUSB_DeviceMscEventReadResponse:
            lba = (usb_device_lba_app_struct_t *)param;
            break;
        case kUSB_DeviceMscEventWriteResponse:
            lba = (usb_device_lba_app_struct_t *)param;
/*write the data to sd card*/
#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))
            writeInformation[0] = (uint32_t)lba->buffer;
            writeInformation[1] = lba->offset;
            writeInformation[2] = lba->size;
            if (0 == lba->size)
            {
                xQueueSend(g_writeBufferHandle, &writeInformation[0], 0U);
            }
            else
            {
                xQueueSend(g_writeTaskHandle, &writeInformation, 0U);
            }
#else
            /*write the data to sd card*/
            if (0 != lba->size)
            {
                errorCode =
                    USB_Disk_WriteBlocks(lba->buffer, lba->offset, lba->size >> USB_DEVICE_SDCARD_BLOCK_SIZE_POWER);
                if (kStatus_Success != errorCode)
                {
                    g_deviceComposite->mscDisk.readWriteError = 1;
                    usb_echo(
                        "Write error, error = 0xx%x \t Please check write request buffer size(must be less than 128 "
                        "sectors)\r\n",
                        error);
                    error = kStatus_USB_Error;
                }
            }
#endif
            break;
        case kUSB_DeviceMscEventWriteRequest:
            lba = (usb_device_lba_app_struct_t *)param;
/*get a buffer to store the data from host*/
#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))

            xQueueReceive(g_writeBufferHandle, (void *)&tempbuffer, portMAX_DELAY);
            lba->buffer = (uint8_t *)tempbuffer;
#else
            lba->buffer = (uint8_t *)&g_mscWriteRequestBuffer[0];
#endif
            break;
        case kUSB_DeviceMscEventReadRequest:
            lba         = (usb_device_lba_app_struct_t *)param;
            lba->buffer = (uint8_t *)&g_mscReadRequestBuffer[0];

/*read the data from sd card, then store these data to the read buffer*/
#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))
            xSemaphoreTake(g_xMutex, portMAX_DELAY);
#endif
            errorCode = USB_Disk_ReadBlocks(lba->buffer, lba->offset, lba->size >> USB_DEVICE_SDCARD_BLOCK_SIZE_POWER);
#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))
            xSemaphoreGive(g_xMutex);
#endif
            if (kStatus_Success != errorCode)
            {
                g_deviceComposite->mscDisk.readWriteError = 1;
                usb_echo(
                    "Read error, error = 0xx%x \t Please check read request buffer size(must be less than 128 "
                    "sectors)\r\n",
                    error);
                error = kStatus_USB_Error;
            }
            break;
        case kUSB_DeviceMscEventGetLbaInformation:
            lbaInformation                                             = (usb_device_lba_information_struct_t *)param;
            lbaInformation->logicalUnitNumberSupported                 = LOGICAL_UNIT_SUPPORTED;
            lbaInformation->logicalUnitInformations[0].lengthOfEachLba = USB_Disk_GetBlockSize();
            lbaInformation->logicalUnitInformations[0].totalLbaNumberSupports = USB_Disk_GetBlockCount();
            lbaInformation->logicalUnitInformations[0].bulkInBufferSize       = USB_DEVICE_MSC_READ_BUFF_SIZE;
            lbaInformation->logicalUnitInformations[0].bulkOutBufferSize      = USB_DEVICE_MSC_WRITE_BUFF_SIZE;
            break;
        case kUSB_DeviceMscEventTestUnitReady:
            /*change the test unit ready command's sense data if need, be careful to modify*/
            if (1U == g_deviceComposite->mscDisk.stop)
            {
                ufi                                    = (usb_device_ufi_app_struct_t *)param;
                ufi->requestSense->senseKey            = USB_DEVICE_MSC_UFI_NOT_READY;
                ufi->requestSense->additionalSenseCode = USB_DEVICE_MSC_UFI_ASC_MEDIUM_NOT_PRESENT;
            }
            break;
        case kUSB_DeviceMscEventInquiry:
            ufi         = (usb_device_ufi_app_struct_t *)param;
            ufi->size   = sizeof(usb_device_inquiry_data_fromat_struct_t);
            ufi->buffer = (uint8_t *)&g_InquiryInfo;
            break;
        case kUSB_DeviceMscEventModeSense:
            ufi         = (usb_device_ufi_app_struct_t *)param;
            ufi->size   = sizeof(usb_device_mode_parameters_header_struct_t);
            ufi->buffer = (uint8_t *)&g_ModeParametersHeader;
            break;
        case kUSB_DeviceMscEventModeSelectResponse:
            ufi = (usb_device_ufi_app_struct_t *)param;
            break;
        case kUSB_DeviceMscEventModeSelect:
        case kUSB_DeviceMscEventFormatComplete:
        case kUSB_DeviceMscEventRemovalRequest:
            error = kStatus_USB_InvalidRequest;
            break;
        case kUSB_DeviceMscEventRequestSense:
            break;
        case kUSB_DeviceMscEventReadCapacity:
            capacityInformation                         = (usb_device_capacity_information_struct_t *)param;
            capacityInformation->lengthOfEachLba        = USB_Disk_GetBlockSize();
            capacityInformation->totalLbaNumberSupports = USB_Disk_GetBlockCount();
            break;
        case kUSB_DeviceMscEventReadFormatCapacity:
            capacityInformation                         = (usb_device_capacity_information_struct_t *)param;
            capacityInformation->lengthOfEachLba        = USB_Disk_GetBlockSize();
            capacityInformation->totalLbaNumberSupports = USB_Disk_GetBlockCount();
            break;
        case kUSB_DeviceMscEventStopEjectMedia:
            ufi = (usb_device_ufi_app_struct_t *)param;
            if (0x00U == (ufi->cbwcb[4] & 0x01U)) /* check start bit */
            {
                g_deviceComposite->mscDisk.stop = 1U; /* stop command */
            }
            break;
        default:
            error = kStatus_USB_InvalidRequest;
            break;
    }
    return error;
}
/*!
 * @brief msc device set configuration function.
 *
 * This function sets configuration for msc class.
 *
 * @param handle The msc class handle.
 * @param configure The msc class configure index.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceMscDiskSetConfigure(class_handle_t handle, uint8_t configure)
{
    return kStatus_USB_Error;
}
/*!
 * @brief device msc init function.
 *
 * This function initializes the device with the composite device class information.
 *
 * @param deviceComposite          The pointer to the composite device structure.
 * @return kStatus_USB_Success .
 */
usb_status_t USB_DeviceMscDiskInit(usb_device_composite_struct_t *deviceComposite)
{
    g_deviceComposite = deviceComposite;

#if (defined(USB_DEVICE_MSC_USE_WRITE_TASK) && (USB_DEVICE_MSC_USE_WRITE_TASK > 0))

    g_xMutex            = xSemaphoreCreateMutex();
    g_writeBufferHandle = xQueueCreate(USB_DEVICE_MSC_WRITE_BUFF_NUM, sizeof(uint32_t *));
    for (int i = 0; i < USB_DEVICE_MSC_WRITE_BUFF_NUM; i++)
    {
        uint8_t *bufferAddress = (uint8_t *)&g_mscWriteRequestBuffer[i][0];
        xQueueSend(g_writeBufferHandle, &bufferAddress, 0);
    }
    g_writeTaskHandle = xQueueCreate(USB_DEVICE_MSC_WRITE_BUFF_NUM, sizeof(usb_device_lba_app_struct_t));
#endif

    return kStatus_USB_Success;
}
