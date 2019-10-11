#include <iostream>
#include <vector>
#include <numeric>

class AverageOfSubarrayOfSizeK
{
public:
    template <typename T>
    static std::vector<double> findAverages(int K, const std::vector<T> &arr)
    {
        int numElements = arr.size() - K + 1;
        std::vector<double> result(numElements);
        for (int i = 0; i < numElements; ++i)
        {
            // find sum of next 'K' elements
            /**
            double sum = 0;
            for (int j = i; j < i + K; ++j)
            {
                sum += arr[j];
            }
            result[i] = sum / K; // calculate average
            */

            // 优化如下：
            result[i] = std::accumulate(arr.cbegin() + i, arr.cbegin() + i + K, 0.d) / K;
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    int K = 5;
    auto result =
        AverageOfSubarrayOfSizeK::findAverages(K, std::vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
    std::cout << "Averages of subarrays of size " << K << ": ";
    for (double d : result)
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}
