include_guard()
message("driver_phy-common component is included.")


target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/.
)

include(driver_mdio-common_MIMXRT1176_cm4)
