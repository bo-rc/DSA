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
project(DSA)

#-------------------------------------------------------------------------------
# Sources
#-------------------------------------------------------------------------------
#
# Add Library dependencies
add_subdirectory(BoxFilter)
add_subdirectory(DynamicArray)
add_subdirectory(Graph-Algorithms)
add_subdirectory(Heap)
add_subdirectory(HeapSort)
add_subdirectory(KernelFilter)
add_subdirectory(PairMatches)
add_subdirectory(Permutations)
add_subdirectory(PQueue)
add_subdirectory(Sort)
add_subdirectory(SubsetPermutation)
add_subdirectory(cpplang)