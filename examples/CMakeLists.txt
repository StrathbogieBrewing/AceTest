cmake_minimum_required(VERSION 3.18)

project(demo)

include_directories(demo ../include)
add_compile_options( -DACETEST_ENABLED)
add_executable(demo demo.c)

enable_testing()
add_test(NAME demo COMMAND demo)
