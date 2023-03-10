/*
 * Copyright 2020-2022 NXP.
 * This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * license terms that accompany it. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms. If you do not agree to be bound by the
 * applicable license terms, then you may not retain, install, activate or otherwise use the software.
 */

#include <hal_static_image.h>
#include "hal.h"

hal_image_status_t HAL_Image_Init(static_image_t *elt, mpp_img_params_t *config, void *param)
{
    hal_image_status_t ret = MPP_kStatus_HAL_ImageSuccess;
    HAL_LOGD("++HAL_STATIC_Image_Init\n");

    elt->config.width = config->width;
    elt->config.height = config->height;
    elt->config.format = config->format;
    elt->buffer = param ;
    HAL_LOGD("--HAL_STATIC_Image_Init\n");
    return ret;
}

hal_image_status_t HAL_Image_Dequeue(const static_image_t *elt, void **data, mpp_pixel_format_t *format)
{
    hal_image_status_t ret = MPP_kStatus_HAL_ImageSuccess;
    HAL_LOGI("++HAL_IMAGE_Dequeue\n");

    *data   = (void *)elt->buffer;
    *format = elt->config.format;
    HAL_LOGI("--HAL_IMAGE_Dequeue\n");
    return ret;
}

const static static_image_operator_t static_image_ops = {
    .init        = HAL_Image_Init,
    .dequeue     = HAL_Image_Dequeue,
};

int setup_static_image(static_image_t *elt)
{
    elt->ops = &static_image_ops;
    return 0;
}

