#include <Heap.hpp>
#include <algorithm>

Heap::Heap(std::initializer_list<int> inputs)
{
    m_array = inputs;
    std::make_heap(m_array.begin(), m_array.end());
}

int Heap::top() const
{
    if (!empty())
    {
        return m_array[0];
    }
    else
    {
        return -1;
    }
}

void Heap::push(int a)
{
    m_array.push_back(a);
    std::make_heap(m_array.begin(), m_array.end());
}

void Heap::pop()
{
    if (!empty())
    {
        std::pop_heap(m_array.begin(), m_array.end());
        m_array.pop_back();
    }
}

int Heap::empty() const
{
    return m_array.empty();
}
int Heap::size() const
{
    return m_array.size();
}