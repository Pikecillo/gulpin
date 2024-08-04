cmake_minimum_required(VERSION 3.10)
project(Gulpin VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "Build directory: ${CMAKE_BINARY_DIR}")

message(STATUS "Gulpin DIR: ${GULPIN_DIR}")

include_directories(${GULPIN_DIR}/include)

add_library(Gulpin SHARED ${PROJECT_SOURCE_DIR}/src/PluginManager.cpp)

set_target_properties(Gulpin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)