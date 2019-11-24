/**
 * Maximum Sum Subarray of Size K
 */

#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <deque>
#include "Output.hpp"

class MaxSubArraySumOfSizeK
{
public:
    template <typename T>
    static T findMaxSubSum(int K, const std::vector<T> &arr, std::vector<T> &resArr)
    {
        T maxSubSum = std::numeric_limits<T>::min();

        // given window size K, need to do (arr.size() - K + 1) times compute
        for (size_t i = 0; i < arr.size() - K + 1; ++i)
        {
            T sum = std::accumulate(arr.cbegin() + i, arr.cbegin() + i + K, T(0));
            if (sum > maxSubSum)
            {
                maxSubSum = sum;
                std::copy(arr.cbegin() + i, arr.cbegin() + i + K, resArr.begin());
            }
        }
        return maxSubSum;
    }

    template <typename T>
    static T findMaxSubSumLinear(int K, const std::vector<T> &arr, std::vector<T> &resArr)
    {
        T maxSubSum = std::numeric_limits<T>::min();
        size_t maxIdx = 0;
        resArr.resize(K);
        std::deque<T> window;
        std::copy(arr.cbegin(), arr.cbegin() + K, std::back_inserter(window));

        for (size_t i = 0; i < arr.size() - K + 1; ++i)
        {
            T sum = std::accumulate(window.cbegin(), window.cend(), T(0));
            if (sum > maxSubSum)
            {
                maxSubSum = sum;
                maxIdx = i;
            }

            // last window do not pop and push_back
            if (i + K < arr.size())
            {
                window.pop_front();
                window.push_back(arr.at(i + K));
            }
        }
        std::copy(arr.cbegin() + maxIdx, arr.cbegin() + maxIdx + K, resArr.begin());
        return maxSubSum;
    }
};

int main(int argc, char *argv[])
{
    int K = 5;
    std::vector<int> res(K);
    auto result =
        MaxSubArraySumOfSizeK::findMaxSubSumLinear(K, std::vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2}, res);
    std::cout << "Averages of subarrays of size " << K << ": " << result << std::endl;

    std::cout << res;
    std::cout << std::endl;
}