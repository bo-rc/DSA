# Copyleft
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 17)

project(CVTest)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
target_link_libraries(${PROJECT_NAME} Threads::Threads)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install/bin)