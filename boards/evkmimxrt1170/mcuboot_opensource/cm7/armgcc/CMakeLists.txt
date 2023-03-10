# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(mcuboot_opensource)

set(MCUX_SDK_PROJECT_NAME mcuboot_opensource.elf)

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../boot.c"
"${ProjDirPath}/../boot.h"
"${ProjDirPath}/../keys.c"
"${ProjDirPath}/../os.c"
"${ProjDirPath}/../sbl_boot.c"
"${ProjDirPath}/../include/mbedtls_config.h"
"${ProjDirPath}/../include/mcuboot_config/mcuboot_config.h"
"${ProjDirPath}/../include/mcuboot_config/mcuboot_logging.h"
"${ProjDirPath}/../include/sbl.h"
"${ProjDirPath}/../include/sbldef.h"
"${ProjDirPath}/../include/flash_map.h"
"${ProjDirPath}/../include/flash_map_backend/flash_map_backend.h"
"${ProjDirPath}/../include/os/os_malloc.h"
"${ProjDirPath}/../include/sysflash/sysflash.h"
"${ProjDirPath}/../flashiap/flash_api.c"
"${ProjDirPath}/../flashiap/flash_info.h"
"${ProjDirPath}/../main.c"
"${ProjDirPath}/../sblconfig.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../flash_partitioning.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${ProjDirPath}/../dcd.c"
"${ProjDirPath}/../dcd.h"
"${ProjDirPath}/../evkmimxrt1170_connect_cm4_cm7side.jlinkscript"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${ProjDirPath}/..
    ${ProjDirPath}/../include
    ${ProjDirPath}/../include/mcuboot_config
    ${ProjDirPath}/../include/sysflash
    ${ProjDirPath}/../flashiap
    ${ProjDirPath}/../secure
)

if(CMAKE_BUILD_TYPE STREQUAL flexspi_nor_debug)
     target_compile_definitions(${MCUX_SDK_PROJECT_NAME}  PRIVATE MBEDTLS_CONFIG_FILE="mbedtls_config.h")
endif(CMAKE_BUILD_TYPE STREQUAL flexspi_nor_debug)

if(CMAKE_BUILD_TYPE STREQUAL flexspi_nor_release)
     target_compile_definitions(${MCUX_SDK_PROJECT_NAME}  PRIVATE MBEDTLS_CONFIG_FILE="mbedtls_config.h")
endif(CMAKE_BUILD_TYPE STREQUAL flexspi_nor_release)

set(CMAKE_MODULE_PATH
    ${ProjDirPath}/../../../../../devices/MIMXRT1176/drivers/cm7
    ${ProjDirPath}/../../../../../middleware/mbedtls
    ${ProjDirPath}/../../../../../components/flash/mflash/mimxrt1170
    ${ProjDirPath}/../../../../../components/flash/mflash
    ${ProjDirPath}/../../../../../devices/MIMXRT1176/drivers
    ${ProjDirPath}/../../../../../middleware/mcuboot_opensource/boot/bootutil
    ${ProjDirPath}/../../../../../devices/MIMXRT1176
    ${ProjDirPath}/../../../../../devices/MIMXRT1176/utilities
    ${ProjDirPath}/../../../../../components/uart
    ${ProjDirPath}/../../../../../components/serial_manager
    ${ProjDirPath}/../../../../../components/lists
    ${ProjDirPath}/../../../../../devices/MIMXRT1176/xip
    ${ProjDirPath}/../../../xip
    ${ProjDirPath}/../../../../../components/silicon_id
    ${ProjDirPath}/../../../../../CMSIS/Core/Include
)

# include modules
include(driver_cache_armv7_m7_MIMXRT1176_cm7)

include(middleware_mbedtls_port_ksdk_MIMXRT1176_cm7)

include(middleware_mbedtls_MIMXRT1176_cm7)

include(middleware_mbedtls_rt2_MIMXRT1176_cm7)

include(component_mflash_rt1170_MIMXRT1176_cm7)

include(component_mflash_common_MIMXRT1176_cm7)

include(driver_flexspi_MIMXRT1176_cm7)

include(middleware_mcuboot_bootutil_MIMXRT1176_cm7)

include(driver_clock_MIMXRT1176_cm7)

include(driver_common_MIMXRT1176_cm7)

include(device_MIMXRT1176_CMSIS_MIMXRT1176_cm7)

include(utility_debug_console_MIMXRT1176_cm7)

include(component_lpuart_adapter_MIMXRT1176_cm7)

include(component_serial_manager_MIMXRT1176_cm7)

include(component_lists_MIMXRT1176_cm7)

include(component_serial_manager_uart_MIMXRT1176_cm7)

include(driver_lpuart_MIMXRT1176_cm7)

include(device_MIMXRT1176_startup_MIMXRT1176_cm7)

include(driver_iomuxc_MIMXRT1176_cm7)

include(utility_assert_MIMXRT1176_cm7)

include(driver_igpio_MIMXRT1176_cm7)

include(driver_xip_device_MIMXRT1176_cm7)

include(driver_xip_board_evkmimxrt1170_MIMXRT1176_cm7)

include(driver_pmu_1_MIMXRT1176_cm7)

include(driver_dcdc_soc_MIMXRT1176_cm7)

include(component_silicon_id_MIMXRT1176_cm7)

include(driver_anatop_ai_MIMXRT1176_cm7)

include(CMSIS_Include_core_cm_MIMXRT1176_cm7)

include(driver_caam_MIMXRT1176_cm7)

include(driver_memory_MIMXRT1176_cm7)

include(utilities_misc_utilities_MIMXRT1176_cm7)

include(device_MIMXRT1176_system_MIMXRT1176_cm7)


TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE m)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE c)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE gcc)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE nosys)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


