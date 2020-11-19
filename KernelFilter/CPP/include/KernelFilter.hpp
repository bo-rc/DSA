#pragma once

#include <deque>
#include <vector>

class KernelFilter
{
public:
    KernelFilter(const std::vector<float> &kernel);
    float update(float value);

private:
    std::vector<float> m_kernel;
    std::deque<float> m_deque;

    /* helpers */
    void add(float value);
};