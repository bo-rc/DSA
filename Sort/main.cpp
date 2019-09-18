#include <vector>
#include <iostream>
#include <random>
#include "sort.hpp"

void test_insertionSort_small()
{
    std::cout << "insertionSort: small test starts.\n";

    std::vector<int> array{1, 3, 2, 4, 7, 5, 6};
    insertionSort(array.begin(), array.end());
    std::cout << "should be a sorted array, increasing values:\n";
    for (auto x : array)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;

    std::cout << "small test ends.\n";
}

void test_insertionSort_large()
{
    std::cout << "insertionSort: large test starts.\n";

    std::random_device rd{};
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> d(0, 1000);
    std::vector<int> large_array;
    large_array.reserve(100000);
    for (size_t i = 0; i < 100000; ++i)
    {
        large_array.push_back(d(gen));
    }

    auto copy_large_array = large_array;
    std::sort(copy_large_array.begin(), copy_large_array.end());

    insertionSort(large_array.begin(), large_array.end());

    if (std::equal(large_array.begin(), large_array.end(), copy_large_array.begin()))
    {
        std::cout << "large array test passed.\n";
    }

    std::cout << "large array test ends.\n";
}

void test_quickSort_small()
{
    std::cout << "quickSort: small test starts.\n";

    std::vector<int> array{7, 3, 2, 4, 1, 5, 6};
    //std::vector<int> array {3,2,1};
    quickSort(array.begin(), array.end(), array);
    std::cout << "should be a sorted array, increasing values:\n";
    for (auto x : array)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;

    std::cout << "small test ends.\n";
}

void test_quickSort_large()
{
    std::cout << "quickSort: large test starts.\n";

    std::random_device rd{};
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> d(0, 1000);
    std::vector<int> large_array;
    large_array.reserve(100000);
    for (size_t i = 0; i < 100000; ++i)
    {
        large_array.push_back(d(gen));
    }

    auto copy_large_array = large_array;
    std::sort(copy_large_array.begin(), copy_large_array.end());

    quickSort(large_array.begin(), large_array.end(), large_array);

    if (std::equal(large_array.begin(), large_array.end(), copy_large_array.begin()))
    {
        std::cout << "large array test passed.\n";
    }

    std::cout << "large array test ends.\n";
}

int main()
{
    test_insertionSort_small();
    test_insertionSort_large();
    test_quickSort_small();
    test_quickSort_large();
    return 0;
}