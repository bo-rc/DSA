# Copyleft

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 14)
project(ShortestPath)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Create shared library
add_library(${PROJECT_NAME}lib 
    SHARED 
        ${SOURCES}
    )
target_link_libraries(${PROJECT_NAME}lib
    PUBLIC
        Graphlib
        Heaplib
)
target_include_directories(${PROJECT_NAME}lib
    PUBLIC 
      "include"
    )

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_NAME}lib
)