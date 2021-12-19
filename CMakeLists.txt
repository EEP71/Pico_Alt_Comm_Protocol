cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)


project(main_test C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(FAMILY rp2040)
set(BOARD pico_sdk)
pico_sdk_init()

if (TARGET tinyusb_device)

add_executable(main)
add_library(kiss_fft ${CMAKE_CURRENT_LIST_DIR}/src/kiss_fft/kiss_fft.c)
add_library(kiss_fftr ${CMAKE_CURRENT_LIST_DIR}/src/kiss_fft/kiss_fftr.c)
target_link_libraries(kiss_fftr kiss_fft)

target_sources(main PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/src/Communication.c
		${CMAKE_CURRENT_LIST_DIR}/src/Settings.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ADC.c
		${CMAKE_CURRENT_LIST_DIR}/src/DAC.c
        ${CMAKE_CURRENT_LIST_DIR}/src/Analyzer.c
        ${CMAKE_CURRENT_LIST_DIR}/src/Scope.c
        ${CMAKE_CURRENT_LIST_DIR}/src/AWG.c
		${CMAKE_CURRENT_LIST_DIR}/src/Error.c
		${CMAKE_CURRENT_LIST_DIR}/src/LIA.c
		${CMAKE_CURRENT_LIST_DIR}/src/Main.c
        )

add_compile_options(-Wall
	-Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
	-Wno-unused-function # we have some for the docs that aren't called
	-Wno-maybe-uninitialized
)
target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src)


target_link_libraries(  main PUBLIC
                        pico_runtime
                        pico_standard_link
                        pico_stdlib
                        hardware_adc
                        hardware_dma
                        kiss_fftr
                        )

pico_add_extra_outputs(main)
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()