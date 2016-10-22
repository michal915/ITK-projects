project(ITK_tests CXX)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -std=gnu++11")

find_package(ITK)
if (ITK_FOUND)
  include(${ITK_USE_FILE})
endif(ITK_FOUND)

find_package(VTK)
if(VTK_FOUND)
  include(${VTK_USE_FILE})
endif(VTK_FOUND)

# Projects
add_subdirectory(HelloWorld)
add_subdirectory(FilterGradientMagnitude)