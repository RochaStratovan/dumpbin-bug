cmake_minimum_required (VERSION 3.15)

set(TARGET ${TARGET_LIB2})

set(LIB_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
cmake_print_variables(LIB_ROOT_DIR)

project(${TARGET})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

add_library(${TARGET} SHARED)

set(ALL_BUILD_FILES
    include/GrandChild/main_lib.h
    source/GrandChild/main_lib.cpp)

target_sources(${TARGET} PRIVATE ${ALL_BUILD_FILES})

target_include_directories(${TARGET} PUBLIC include)
