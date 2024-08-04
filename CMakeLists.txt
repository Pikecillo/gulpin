cmake_minimum_required(VERSION 3.10)
project(Gulpin VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "Project source dir ${PROJECT_SOURCE_DIR}")

set(GULPIN_DIR "${PROJECT_SOURCE_DIR}/gulpin")

add_subdirectory(gulpin)
add_subdirectory(sample-app)