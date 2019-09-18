# Copyleft

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 14)

project(PQueue)

add_library(heapq_lib STATIC
  src/Heap.cpp
)

include_directories(heapq_lib
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE heapq_lib)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install/bin)