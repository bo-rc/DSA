# Copyleft

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 14)

project(KernelFilter)

add_library(kernelfilter_lib STATIC
  CPP/src/KernelFilter.cpp
)

include_directories(kernelfilter_lib
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/CPP/include"
)

add_executable(${PROJECT_NAME} CPP/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE kernelfilter_lib)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install/bin)