include_guard()
message("device_MIMXRT1176_startup component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/gcc/startup_MIMXRT1176_cm7.S
)


include(device_MIMXRT1176_system_MIMXRT1176_cm7)

