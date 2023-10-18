cmake_minimum_required (VERSION 3.23)

include(CMakePrintHelpers)

set(PROJECT_NAME_STR "Dependency Bug")

set(TARGET_BASE      TheProgram)
set(TARGET_LIB1      Child)
set(TARGET_LIB2      GrandChild)
set(PROJ_ROOT_DIR    ${CMAKE_CURRENT_LIST_DIR})

project(${TARGET_BASE})


# We typically only deploy the library and its include files to the install
# folder if the project is a library. Apps rarely if ever need to deploy their
# associated library.
set(INSTALL_LIB True)
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/app")
    set(INSTALL_LIB False)
endif()


#
# Only add the expected project directories if they exist
set(SUBDIRS
    app
    lib1
    lib2
    tests)
foreach(ENTRY IN LISTS SUBDIRS)
    if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${ENTRY}")
        add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/${ENTRY}")
    else()
        message(STATUS "Folder ${ENTRY} not present. Skipping.")
    endif()
endforeach()
