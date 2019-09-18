# Copyleft

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 14)

project(test_boxfilter)

add_library(boxfilter_lib STATIC
  CPP/src/BoxFilter.cpp
)

include_directories(boxfilter_lib
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/CPP/include"
)

add_executable(${PROJECT_NAME} CPP/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE boxfilter_lib)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install/bin)