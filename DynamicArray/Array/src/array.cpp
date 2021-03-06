/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2018 by boliu                                           *
 *                                                                         *
 *   https://www.bo-liu.com                                                *
 *                                                                         *
 ***************************************************************************/

#include "array.h"
#include <utility>
#include <iostream>
#include <algorithm>

Array::Array() : m_cap(0),
                 m_size(0)
{
    // nothing needs to be done here.
}

Array::Array(size_t capacity) : m_cap(capacity),
                                m_size(0)
{
    m_arr = std::make_unique<int[]>(capacity);
}

Array::Array(const Array &other) : m_cap(other.m_cap),
                                   m_size(other.m_size)
{
    std::cout << "copy construction" << std::endl;
    m_arr = std::make_unique<int[]>(m_cap);

    std::copy(other.m_arr.get(), other.m_arr.get() + other.m_size, m_arr.get());
}

Array::Array(Array &&other) : m_cap(other.m_cap),
                              m_size(other.m_size),
                              m_arr(std::move(other.m_arr))
{
    std::cout << "move construction" << std::endl;
    other.m_cap = 0;
    other.m_size = 0;
    other.m_arr = nullptr;
}

Array::~Array()
{
    // nothing needs to be done here
}

size_t Array::size() const
{
    return m_size;
}

size_t Array::capacity() const
{
    return m_cap;
}

bool Array::empty() const
{
    return (m_size == 0);
}

int Array::front() const
{
    if (m_size == 0)
    {
        std::cout << "Array is empty! returns 0" << std::endl;
        return 0;
    }

    return m_arr[0];
}

int Array::back() const
{
    if (m_size == 0)
    {
        std::cout << "Array is empty! returns 0" << std::endl;
        return 0;
    }

    int copy = m_arr[m_size - 1];
    return copy;
}

int &Array::operator[](size_t pos)
{
    return m_arr[pos];
}

int Array::operator[](size_t pos) const
{
    int copy = m_arr[pos];
    return copy;
}

void Array::clear()
{
    std::fill_n(m_arr.get(), m_size, 0);
    m_size = 0;
}

void Array::push_back(int ele)
{
    if (m_cap - m_size < 1)
    {
        size_t new_cap = 2 * m_cap + 1;
        auto new_arr = std::make_unique<int[]>(new_cap);

        std::copy(m_arr.get(), m_arr.get() + m_size, new_arr.get());

        m_cap = new_cap;
        std::exchange(m_arr, std::move(new_arr));
    }

    m_arr[m_size] = ele;
    m_size += 1;
}

void Array::pop_back()
{
    if (m_size < 1)
    {
        return;
    }

    m_arr[m_size - 1] = 0;
    m_size -= 1;

    if (m_cap > 2 * m_size + 1)
    {
        auto new_cap = m_size + 1;
        auto new_arr = std::make_unique<int[]>(new_cap);

        std::copy(m_arr.get(), m_arr.get() + m_size, new_arr.get());

        std::exchange(m_arr, std::move(new_arr));
        m_cap = new_cap;
    }
}

Array &Array::operator=(Array other)
{
    std::cout << "assignment" << std::endl;
    std::swap(m_arr, other.m_arr);
    std::swap(m_size, other.m_size);
    std::swap(m_cap, other.m_cap);

    return *this;
}
