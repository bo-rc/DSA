#ifndef BOXFILTER_H
#define BOXFILTER_H

#include <cstddef>
#include <deque>

class BoxFilter
{
public:
    BoxFilter(size_t s);
    float update(float value);

private:
    size_t m_filledSize = 0;
    std::deque<float> m_deque;

    /* helpers */
    void add(float value);
};

#endif