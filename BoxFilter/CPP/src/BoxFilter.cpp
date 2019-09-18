#include <iostream>
#include "BoxFilter.hpp"
#include "numeric"

BoxFilter::BoxFilter(size_t s) : m_deque(s, 0.0)
{
    // nothing needs to be done here
}

void BoxFilter::add(float value)
{
    m_deque.pop_front();
    m_deque.push_back(value);
}

float BoxFilter::update(float value)
{
    add(value);

    if (m_filledSize < m_deque.size())
    {
        ++m_filledSize;
    }

    auto sum = std::accumulate(m_deque.rbegin(),
                               m_deque.rbegin() + m_filledSize, 0.0);

    return sum / m_filledSize;
}
