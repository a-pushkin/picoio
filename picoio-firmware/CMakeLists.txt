cmake_minimum_required(VERSION 3.12)

include(../cmake/pico_sdk_import.cmake)

project(picoio C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(../libpicoiomsg libpicoiomsg)

add_executable(picoio
    src/picoio_bin.cpp
)

pico_enable_stdio_usb(picoio 1)
pico_enable_stdio_uart(picoio 0)

target_link_libraries(picoio
        pico_stdlib
        hardware_spi
        libpicoiomsg
)

pico_add_extra_outputs(picoio)

