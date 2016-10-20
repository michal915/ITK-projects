project(ITK_tests CXX)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

# ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_subdirectory(HelloWorld)
