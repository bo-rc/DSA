#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

template <typename ForwardIt, typename Compare = std::less<>>
void insertionSort(ForwardIt first, ForwardIt last, Compare comp = Compare())
{
    for (auto i = first; i != last; ++i)
    {
        // 1 2 ^ 4 5 _3_ 2 <- upper_bound finds the position
        // 1 2 _3_ 4 5 2   <- rotate with single-element tail does the insertion
        std::rotate(std::upper_bound(first, i, *i, comp), i, i + 1);
    }
}

// helper
template <typename ForwardIt>
ForwardIt selectPivot(ForwardIt first, ForwardIt last)
{
    auto range = std::distance(first, last);

    std::random_device rd{};                        // seed
    std::mt19937 gen(rd());                         // the generator using the seed
    std::uniform_int_distribution<> dist(0, range); // the distribution using the generator

    auto offset = dist(gen);

    return first + offset;
}

template <typename ForwardIt, typename Compare = std::less<>>
void quickSort(ForwardIt first, ForwardIt last, const std::vector<int> &v, Compare comp = Compare())
{
    // return until single element array
    if (std::distance(first, last) < 2)
    {
        return;
    }

    // select a pivot
    auto nth_pivot = selectPivot(first, last);

    // partition by pivot
    std::nth_element(first, nth_pivot, last, comp);

    quickSort(first, nth_pivot, v);
    quickSort(nth_pivot, last, v);
}