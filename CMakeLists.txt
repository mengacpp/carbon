cmake_minimum_required(VERSION 3.15)

project(carbon VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

if(SOURCES)
  add_library(carbon STATIC ${SOURCES})
else()
  message(FATAL_ERROR "No source files found in src/")
endif()


target_include_directories(carbon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
