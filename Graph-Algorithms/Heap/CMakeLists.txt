# Copyleft

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 14)
project(Heaplib)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Create shared library
add_library(${PROJECT_NAME} 
    SHARED 
        ${SOURCES}
    )
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
      "include"
    )