/**
 * Given an array of positive numbers and a positive number ‘S’, 
 * find the length of the smallest contiguous subarray 
 * whose sum is greater than or equal to ‘S’. 
 * Return 0, if no such subarray exists.
 * 
 * Example 1:
 *  Input: [2, 1, 5, 2, 3, 2], S=7 
 *  Output: 2
 *  Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].
 */

#include <iostream>
#include <limits>
#include <vector>
#include "Output.hpp"

class MinSizeSubArraySum
{
public:
    static int findMinSubArray(int S, const std::vector<int> &arr)
    {
        int windowSum = 0, minLength = std::numeric_limits<int>::max();
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd)
        {
            windowSum += arr[windowEnd]; // add the next element
            // shrink the window as small as possible until the 'windowSum' is smaller than 'S'
            while (windowSum >= S)
            {
                minLength = std::min(minLength, windowEnd - windowStart + 1);
                windowSum -= arr[windowStart]; // subtract the element going out
                windowStart++;                 // slide the window ahead
            }
        }

        return minLength == std::numeric_limits<int>::max() ? 0 : minLength;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> arr1{2, 1, 5, 2, 3, 2};
    int result = MinSizeSubArraySum::findMinSubArray(7, arr1);
    std::cout << arr1;
    std::cout << "Given sum 7, Smallest subarray length: " << result << std::endl;
    result = MinSizeSubArraySum::findMinSubArray(7, std::vector<int>{2, 1, 5, 2, 8});
    std::cout << "Given sum 7, Smallest subarray length: " << result << std::endl;
    result = MinSizeSubArraySum::findMinSubArray(8, std::vector<int>{3, 4, 1, 1, 6});
    std::cout << "Given sum 7, Smallest subarray length: " << result << std::endl;
}
