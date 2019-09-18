#include <iostream>
#include <numeric>
#include "KernelFilter.hpp"

KernelFilter::KernelFilter(const std::vector<float> &kernel) : m_kernel(kernel),
                                                               m_deque(kernel.size(), 0.0)
{
    // nothing needs to be done here
}

void KernelFilter::add(float value)
{
    m_deque.pop_front();
    m_deque.push_back(value);
}

float KernelFilter::update(float value)
{

    add(value);

    return std::inner_product(m_deque.begin(),
                              m_deque.end(), m_kernel.begin(), 0.0);
}
