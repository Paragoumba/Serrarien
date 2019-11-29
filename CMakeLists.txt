cmake_minimum_required(VERSION 3.0)
project(Serrarien)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src "${PROJECT_SOURCE_DIR}/src/cmake-build-debug")
add_subdirectory(tests "${PROJECT_SOURCE_DIR}/tests/cmake-build-debug")