# Copyleft

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)

project(scratch)

add_library($PROJECT STATIC
  src/*.cpp
)

include_directories($PROJECT
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(run-${PROJECT_NAME} PRIVATE $PROJECT)
install(TARGETS run-${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install/bin)