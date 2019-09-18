#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

template <typename T>
int count(const std::vector<T> &a, const std::vector<T> &b)
{
    return std::inner_product(a.cbegin(), a.cend(), b.cbegin(), 0, std::plus<>(), std::equal_to<>());
}