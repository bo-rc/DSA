# Copyleft

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)

project(Util)

add_library(${PROJECT_NAME} SHARED
  Output.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PRIVATE .)

install(
    TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/build/install/lib 
    PUBLIC_HEADER DESTINATION ${CMAKE_SOURCE_DIR}/build/install/include}
)