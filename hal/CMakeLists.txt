if(NOT "${TARGET}" STREQUAL "Native")
    add_library(stm_hal STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_adc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_adc_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_cortex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_crc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_crc_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_dma.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_dma_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_exti.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_fdcan.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_flash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_flash_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_gpio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_hcd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_i2c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_i2c_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_i2s.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_irda.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_iwdg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_pcd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_pcd_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_pwr.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_pwr_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_rcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_rcc_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_rtc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_rtc_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_smartcard.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_smartcard_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_smbus.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_smbus_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_spi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_spi_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_tim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_tim_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_uart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_uart_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_usart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_usart_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_hal_wwdg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_adc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_crc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_crs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_dma.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_exti.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_gpio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_i2c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_pwr.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_rcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_rtc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_spi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_tim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_usart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_usb.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Src/stm32c0xx_ll_utils.c
        # Startup + system init for the STM32C031
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/stm32c031/startup_stm32c031xx.s
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/stm32c031/system_stm32c0xx.c
    )

    target_include_directories(stm_hal PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32c0xx_hal/Inc/Legacy
        ${CMAKE_CURRENT_SOURCE_DIR}/config
    )

    target_compile_definitions(stm_hal PUBLIC
        USE_HAL_DRIVER
        STM32C031xx
    )

    target_link_libraries(stm_hal
        PRIVATE cmsis
        PUBLIC  m
    )
endif()
