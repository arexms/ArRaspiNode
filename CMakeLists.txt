cmake_minimum_required(VERSION 2.8)
project(ArRaspiNode)

#-------------------------------------------------------------------------------
#
# Configuration
#
#-------------------------------------------------------------------------------

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_definitions("-g -O0 -Wall -W -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -pthread -std=c++14")
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    message(STATUS "Compile with gcov (only with gcc)")
    add_definitions("-fprofile-arcs -ftest-coverage")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(STATUS "Compile with -stdlib=libc++ (only with clang)")
    add_definitions("-stdlib=libc++")
endif()

#-------------------------------------------------------------------------------
#
# ArRaspiNode
#
#-------------------------------------------------------------------------------

include_directories(src)
FILE(GLOB_RECURSE SOURCES_LIST src/*.cpp)
add_library(arraspinode ${SOURCES_LIST})

#-------------------------------------------------------------------------------
#
# Tests
#
#-------------------------------------------------------------------------------

add_subdirectory(googletest)
FILE(GLOB_RECURSE TESTS_LIST tests/*.cpp)
include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)
set(TEST_LIBS gmock_main)
add_executable(ArRaspiNode_tests ${TESTS_LIST})
target_link_libraries(ArRaspiNode_tests gcov arraspinode ${TEST_LIBS})

#-------------------------------------------------------------------------------
#
# Custom targets
#
#-------------------------------------------------------------------------------

ADD_CUSTOM_TARGET(
    runTests
    ${EXECUTABLE_OUTPUT_PATH}/./ArRaspiNode_tests --gtest_output="xml:gtest.xml"
)