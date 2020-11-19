#include <iostream>
#include "KernelFilter.hpp"
#include <vector>

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

void test_offline()
{
    std::cout << "offline test started: \n";
    std::vector<float> myArray {1,1,1,1,1,1,1};
    std::vector<float> k{0.1, 0.25, 0.3, 0.25, 0.1};
    KernelFilter myFilter(k);
    
    std::vector<float> filteredArray {};

    for (const auto& element: myArray)
    {
        std::cout << myFilter.update(element) << ", ";
    }
    std::cout << std::endl;

    std::cout << "offline test ended \n";
}

int main()
{
    // test_online();
    test_offline();
    return 0;
}