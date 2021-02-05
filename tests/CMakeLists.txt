cmake_minimum_required(VERSION 3.12)

project(picoio)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(../libpicoiomsg libpicoiomsg)

add_executable(picoio_tests
    src/TestParser.cpp
)

target_link_libraries(picoio_tests
        gtest
        gtest_main
        libpicoiomsg
        pthread
)

