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
project(SlidingWindow)

#-------------------------------------------------------------------------------
# Sources
#-------------------------------------------------------------------------------
#
add_subdirectory(AvgSubArray)
add_subdirectory(MaxSubArraySum)
add_subdirectory(MinSubArrayGivenSum)
add_subdirectory(LongestSubstringKDistinct)
add_subdirectory(NoRepeatSubstring)
add_subdirectory(LongestSubstringWithSameLettersAfterReplacement)
add_subdirectory(LongestSubarrayWithOnesAfterReplacement)
add_subdirectory(PermutationInString)