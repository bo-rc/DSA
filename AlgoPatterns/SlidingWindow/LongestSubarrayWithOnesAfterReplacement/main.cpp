/**
 * Problem Statement
 * Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, 
 * find the length of the longest contiguous subarray having all 1s.
 * Example 1:
 * Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
 * Output: 6
 * Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
 */

#include <iostream>
#include <limits>
#include <vector>
#include <deque>
#include <map>
#include "Output.hpp"

class LongestSubarrayWithOnesAfterReplacement
{
public:
    static size_t findLength(const std::vector<int> &arr, size_t k)
    {
        size_t maxLen{0};
        size_t winStart{0};
        size_t winEnd{0};
        size_t replaceCount{0};

        for (const auto &ele : arr)
        {
            ++winEnd;

            // only occasion we need to update replaceCount and winStart is
            // when we encounter '0'
            if (ele == 0)
            {
                ++replaceCount;
                if (replaceCount > k)
                {
                    // need to shrink until the previous '0' before the new '0'
                    while (arr[winStart] != 0)
                    {
                        ++winStart;
                    }
                    ++winStart;
                    --replaceCount;
                }
            }
            else
            {
                // update result
                size_t len = winEnd - winStart;
                maxLen = (len > maxLen) ? len : maxLen;
            }
        }
        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> vec1{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
    std::cout << vec1;

    std::cout << LongestSubarrayWithOnesAfterReplacement::findLength(vec1, 2) << std::endl;

    std::vector<int> vec2{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    std::cout << vec2;

    std::cout << LongestSubarrayWithOnesAfterReplacement::findLength(vec2, 3) << std::endl;
}