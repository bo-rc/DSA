#pragma once

#include <algorithm>
#include <functional>
#include <vector>

template <typename RandomIt, typename Compare = std::less<>>
void heapSort(RandomIt first, RandomIt last, Compare comp = Compare())
{
    std::make_heap(first, last, comp);
    while (first != last)
    {
        std::pop_heap(first, last--, comp);
    }
}

template <typename T, typename Compare = std::less<>>
void heapSort(std::vector<T> &container, Compare comp = Compare())
{
    heapSort(container.begin(), container.end(), comp);
}