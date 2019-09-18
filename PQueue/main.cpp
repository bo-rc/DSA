#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <Heap.hpp>

template <typename T>
void print_heap(T q)
{
    while (!q.empty())
    {
        std::cout << q.top() << ",";
        q.pop();
    }
    std::cout << std::endl;
}

int main()
{
    using BuiltinHeap = std::priority_queue<int>;
    BuiltinHeap heap; // this is the built-in heap
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
    {
        heap.push(n);
    }
    print_heap(heap);
    std::cout << "print again,\n";
    print_heap(heap);

    using MyHeap = Heap;

    MyHeap myHeap{1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    print_heap(myHeap);
}