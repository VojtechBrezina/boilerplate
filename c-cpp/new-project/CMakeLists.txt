cmake_minimum_required(VERSION ...)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(%project_name% VERSION 0.1.0)

add_executable(%target_name%
    src/main.cpp

    # ...
)

target_include_directories(%target_name% PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

set_property(TARGET %target_name% PROPERTY CXX_STANDARD 23)

target_precompile_headers(%target_name% PRIVATE
    <print>

    # ...
)
