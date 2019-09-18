#include <vector>
#include <iostream>
#include "HeapSort.hpp"

void test_heapSort()
{
    // test 1
    std::vector<int> iArray{3, 5, 2, 7, 6, 6, 9, 12};
    heapSort(iArray);

    std::cout << "test1 - should increase: \n";
    for (auto x : iArray)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;

    // test 2
    std::vector<float> fArray{1.4, 5.3, 2.2, 2.7, 6.9, 0.6, 9., 12.};
    heapSort(fArray, std::greater<float>());

    std::cout << "test2 - should decrease: \n";
    for (auto x : fArray)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;

    // test 3
    heapSort(fArray.begin(), fArray.end());
    std::cout << "test3 - should increase: \n";
    for (auto x : fArray)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;
}

int main()
{
    test_heapSort();
    return 0;
}