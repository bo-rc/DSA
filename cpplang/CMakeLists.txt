#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# File: CMakeLists.txt
#
# Brief: Cmake list file.
#
# Author: Bo Liu (bo.robotics@gmail.com)
#
# Copyleft
#
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
cmake_minimum_required(VERSION 3.5)
#-------------------------------------------------------------------------------
# cmake project
#-------------------------------------------------------------------------------
project(cpplang)

#-------------------------------------------------------------------------------
# Sources
#-------------------------------------------------------------------------------
#
# Add Library dependencies
add_subdirectory(PerfectForwarding)
add_subdirectory(threads)
add_subdirectory(Singleton)
add_subdirectory(STL)