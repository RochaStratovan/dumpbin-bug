cmake_minimum_required (VERSION 3.15)

set(TARGET ${TARGET_BASE})

set(APP_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
cmake_print_variables(APP_ROOT_DIR)

project(${TARGET})

add_executable(${TARGET})

set(ALL_BUILD_FILES "source/TheProgram/main.cpp")

target_sources(${TARGET} PRIVATE ${ALL_BUILD_FILES})

target_include_directories(${TARGET} PUBLIC include)

# Add library dependencies
target_link_libraries(${TARGET} PRIVATE ${TARGET_LIB1})
cmake_print_properties(TARGETS ${TARGET} PROPERTIES LINK_LIBRARIES)
