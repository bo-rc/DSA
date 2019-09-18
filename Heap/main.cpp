/**
 * Heap Testing Code
 */

#include <vector>
#include <iostream>
#include "Heap.hpp"

void test_heap_offline()
{
    //test 1
    std::cout << "Offline test started." << std::endl;
    std::cout << "Test min heap." << std::endl;
    std::vector<int> iArray{5, 8, 5, 3, 7, 6, 9, 3, 5, 2, 7, 4, 1};
    Heap<int> heapob(iArray);
    std::cout << "Heap of an vector:" << std::endl;
    std::cout << heapob;
    std::cout << "Use heap to sort this vector:" << std::endl;
    while (!heapob.empty())
    {
        heapob.pop();
        std::cout << " ";
    }
    std::cout << std::endl
              << std::endl
              << std::endl;

    //test 2
    std::cout << "Test max heap:" << std::endl;
    Heap<int, std::greater<int>> heapob2(iArray);
    std::cout << "Heap of an vector:" << std::endl;
    std::cout << heapob2;
    std::cout << "Use heap to sort this vector:" << std::endl;
    while (!heapob2.empty())
    {
        heapob2.pop();
        std::cout << " ";
    }
    std::cout << std::endl
              << "Offline test passed.";
    std::cout << std::endl
              << std::endl
              << std::endl;
}

void test_heap_online()
{
    std::cout << "online test started: type non-numeric values to end \n";
    Heap<int> heapob(0);
    int n = 0.0;
    while (std::cin >> n)
    {
        heapob.push(n);
    }
    std::cout << "Heap of input numbers:" << std::endl;
    std::cout << heapob;
    std::cout << "Use heap to sort this vector:" << std::endl;
    while (!heapob.empty())
    {
        heapob.pop();
        std::cout << " ";
    }
    std::cout << std::endl
              << "Online test passed.";
    std::cout << std::endl
              << std::endl
              << std::endl;
}

int main()
{
    test_heap_offline();
    test_heap_online();

    return 0;
}
