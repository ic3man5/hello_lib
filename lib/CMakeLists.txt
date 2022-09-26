cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(libhello VERSION 0.0.1 DESCRIPTION "Hello library")

option(HELLO_BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" OFF)

set(SourceList src/hello.cpp)

if (HELLO_BUILD_SHARED_LIBS)
   add_library(libhello SHARED ${SourceList})
else()
   add_library(libhello STATIC ${SourceList})
endif()

set_target_properties(libhello PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/hello.h)

target_include_directories(libhello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
