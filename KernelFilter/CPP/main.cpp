#include <iostream>
#include "KernelFilter.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cassert>

void test_online()
{
    std::cout << "online test started: type non-numeric values to end \n";
    std::vector<float> k{0.1, 0.25, 0.3, 0.25, 0.1};
    KernelFilter bf(k);
    float n = 0.0;

    while (std::cin >> n)
    {
        std::cout << n << " --> " << bf.update(n) << std::endl;
    }

    std::cout << "online test ended \n";
}

int main()
{
    test_online();
    return 0;
}