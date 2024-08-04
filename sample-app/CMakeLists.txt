cmake_minimum_required(VERSION 3.10)
project(GulpinSampleApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "Project source dir ${PROJECT_SOURCE_DIR}")

include_directories(${GULPIN_DIR}/include)

link_directories(${CMAKE_BINARY_DIR}/lib)

add_executable(SampleApp ${PROJECT_SOURCE_DIR}/Main.cpp)

target_link_libraries(SampleApp PRIVATE Gulpin)

set_target_properties(SampleApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/sample-app
)

add_subdirectory(plugins)
