# ETL
add_library(etl INTERFACE)
target_include_directories(etl INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/etl/include
)

if(NOT "${TARGET}" STREQUAL "Native")
# CMSIS
    add_library(cmsis INTERFACE)
    target_include_directories(cmsis INTERFACE 
        ${CMAKE_CURRENT_SOURCE_DIR}/stm_device_cmsis/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/cmsis/CMSIS/Core/Include
    )
endif()

# FreeRTOS
set(FREERTOS_HEAP 1 CACHE STRING "" FORCE)

if("${TARGET}" STREQUAL "STM32C031")
    set(FREERTOS_PORT "GCC_ARM_CM0" CACHE STRING "" FORCE)
elseif("${TARGET}" STREQUAL "Native")
    set(FREERTOS_PORT "GCC_POSIX" CACHE STRING "" FORCE)
endif()


add_library(freertos_config INTERFACE)
target_include_directories(freertos_config SYSTEM 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/config
    # FreeRTOSConfig.h includes the device header via CMSIS_device_header
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/stm_device_cmsis/Include
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/cmsis/CMSIS/Core/Include
)
target_compile_definitions(freertos_config INTERFACE
    projCOVERAGE_TEST=0
)

add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos 
)
target_link_libraries(freertos_kernel INTERFACE 
    freertos_config
)
