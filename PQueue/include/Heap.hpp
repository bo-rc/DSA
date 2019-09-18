#pragma once

#include <vector>
#include <initializer_list>

// a wrapper class using STL to simulate Heap
class Heap
{
public:
    int top() const;
    void push(int a);
    void pop();
    int empty() const;
    int size() const;

    Heap(std::initializer_list<int> inputs);

private:
    std::vector<int> m_array;
};
