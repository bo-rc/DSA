#include <iostream>
#include "BoxFilter.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cassert>

void test_offline()
{
    std::cout << "offline test started." << std::endl;
    BoxFilter bf(5);
    std::vector<float> test_array{1, 3, 4, 5, 6, 12, 6, 15, 6, 9, 22, 23, 34, 43, 13, 54};
    std::vector<float> filtered_array;
    std::vector<float> result_array{1.0, 2.0, 2.6666666666666665, 3.25, 3.8, 6.0, 6.6, 8.8, 9.0, 9.6, 11.6, 15.0, 18.8, 26.2, 27.0, 33.4};

    for (const auto &x : test_array)
    {
        filtered_array.push_back(bf.update(x));
    }

    auto float_equal = [](float a, float b) -> bool {
        return std::abs(a - b) < std::numeric_limits<float>::epsilon();
    };

    assert(std::equal(result_array.begin(), result_array.end(), filtered_array.begin(), float_equal));

    std::cout << "offline test passed." << std::endl;
}

void test_online()
{
    std::cout << "online test started: type non-numeric values to end \n";
    BoxFilter bf(5);
    float n = 0.0;

    while (std::cin >> n)
    {
        std::cout << n << " --> " << bf.update(n) << std::endl;
    }

    std::cout << "online test ended \n";
}

int main()
{
    test_offline();
    test_online();

    return 0;
}