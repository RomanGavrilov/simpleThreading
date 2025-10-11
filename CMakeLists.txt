cmake_minimum_required(VERSION 3.16)
project(SimpleThreading LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS "Build libs shared instead of static" OFF)
option(USE_VENDORED_BOOST "Build and use Boost from libs/boost" ON)

add_subdirectory(common)
add_subdirectory(datastructures)
add_subdirectory(src)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
