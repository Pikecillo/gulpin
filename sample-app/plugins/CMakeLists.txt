cmake_minimum_required(VERSION 3.10)

project(GulpinSampleAppPlugins VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(HelloWorldPlugin SHARED HelloWorldPlugin.cpp)

include_directories(${GULPIN_DIR}/include)

set_target_properties(HelloWorldPlugin PROPERTIES
    OUTPUT_NAME "helloworldplugin"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/sample-app/plugins
)
