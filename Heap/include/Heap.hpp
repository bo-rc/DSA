/**
 * @file Heap.h
 * Definition of a Heap class.
 */

#pragma once

#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <iostream>

/**
 * Heap: A priority queue implemented as a Heap.
 */
template <class T, class Compare = std::less<T>>
class Heap
{
public:
    /**
     * Constructs an empty Heap.
     */
    explicit Heap(size_t capacity = 0);

    /**
     * Constructs a Heap from a vector of elements by copying the
     * elements into the Heap's storage and then running the buildHeap
     * algorithm.
     *
     * @param elems The elements that should be placed in the Heap.
     */
    Heap(const std::vector<T> &elems);

    /**
     * Print all element in m_elems
     */
    void print_out();
    /**
     * Removes the element with highest priority according to the
     * higher_priority() functor.
     *
     * By default, the higher_priority() function behaves like
     * operator<, so if T = int and a = 3 and b = 5, higher_priority(a,
     * b) is true (a compares smaller than b, thus it has higher
     * priority) and higher_priority(b, a) is false (b does not compare
     * smaller than a, and thus it has lower priority).
     */
    void pop();

    /**
     * Returns, but does not remove, the element with highest priority.
     *
     * @return The highest priority element in the entire Heap.
     */
    const T &peek() const;

    /**
     * Inserts the given element into the Heap, restoring the Heap
     * property after the insert as appropriate.
     *
     * @param elem The element to be inserted.
     */
    void push(T elem);

    /**
     * Determines if the given Heap is empty.
     *
     * @return Whether or not there are elements in the Heap.
     */
    bool empty() const;

    /**
     * decrease_key re-heap the container after a node's key has been changed.
     */
    void decrease_key(size_t idx);

    /**
     * Prints the heap to an ostream.
     */
    template <class Type, class Comp>
    friend std::ostream &operator<<(std::ostream &out,
                                    const Heap<Type, Comp> &toPrint);

private:
    /**
     * The internal storage for this Heap. **You may choose whether
     * your Heap is 0-based or 1-based (i.e., you are free to store the
     * root at either index 0 or index 1).** You should **pick *one***, and
     * write the helper functions according to that choice.
     */
    std::vector<T> m_elems;

    size_t m_size; // number of elements in Heap

    /**
     * Comparison functor.
     */
    Compare m_higher_priority;

    /**
     * Helper function that returns the root index of this Heap.
     * Required for grading purposes! (This function should be
     * ridiculously easy: either return 0 if you plan to store the root
     * at index 0, or 1 if you plan on storing it at index 1).
     *
     * @return The index of the root node of the Heap.
     */
    size_t root() const;

    /**
     * Helper function that returns the index of the left child of a
     * node in the Heap. Required for grading purposes! (And it should
     * be useful to you as well).
     *
     * @param idx The index of the current node.
     * @return The index of the left child of the current node.
     */
    size_t left_child(size_t idx) const;

    /**
     * Helper function that returns the index of the right child of a
     * node in the Heap. Required for grading purposes! (And it should
     * be useful to you as well).
     *
     * @param idx The index of the current node.
     * @return The index of the right child of the current node.
     */
    size_t right_child(size_t idx) const;

    /**
     * Helper function that returns the index of the parent of a node
     * in the Heap.
     *
     * @param idx The index of the current node.
     * @return The index of the parent of the current node.
     */
    size_t parent(size_t idx) const;

    /**
     * Helper function that determines whether a given node has a
     * child.
     *
     * @param idx The index of the current node.
     * @return A boolean indicating whether the current node has a
     *  child or not.
     */
    bool has_child(size_t idx) const;

    /**
     * Helper function that returns the index of the child with the
     * highest priority as defined by the higher_priority() functor.
     *
     * For example, if T == int and the left child of the current node
     * has data 5 and the right child of the current node has data 9,
     * this function should return the index of the left child (because
     * the default higher_priority() behaves like operator<).
     *
     * This function assumes that the current node has children.
     *
     * @param idx The index of the current node.
     * @return The index of the highest priority child of this node.
     */
    size_t max_priority_child(size_t idx) const;

    /**
     * Helper function that restores the Heap property by sinking a
     * node down the tree as necessary.
     *
     * @param idx The index of the current node that is being
     *  sunk down the tree.
     */
    void heapify_down(size_t idx);

    /**
     * Helper function that restores the Heap property by bubbling a
     * node up the tree as necessary.
     *
     * @param idx The index of the current node that is being
     *  bubbled up the tree.
     */
    void heapify_up(size_t idx);

    void buildHeap();
};

// implementation here
template <class T, class Compare>
void Heap<T, Compare>::print_out()
{
    for (int i = 1; i <= m_size; i++)
    {
        std::cout << m_elems[i] << " ";
    }
    std::cout << std::endl;
}

template <class T, class Compare>
size_t Heap<T, Compare>::root() const
{
    return 1;
}

template <class T, class Compare>
size_t Heap<T, Compare>::left_child(size_t idx) const
{
    return 2 * idx;
}

template <class T, class Compare>
size_t Heap<T, Compare>::right_child(size_t idx) const
{
    return 2 * idx + 1;
}

template <class T, class Compare>
size_t Heap<T, Compare>::parent(size_t idx) const
{
    return floor(idx / 2);
}

template <class T, class Compare>
bool Heap<T, Compare>::has_child(size_t idx) const
{
    return 2 * idx <= m_size;
}

template <class T, class Compare>
size_t Heap<T, Compare>::max_priority_child(size_t idx) const
{
    if (!has_child(idx))
        throw std::runtime_error("this node has no children");

    auto left = 2 * idx;
    auto right = 2 * idx + 1;

    return m_higher_priority(m_elems[left], m_elems[right]) ? left : right;
}

template <class T, class Compare>
void Heap<T, Compare>::heapify_down(size_t idx)
{
    // Implement the heapifyDown algorithm.
    // this is a iterative version, equivalent to the recursive version
    // but slightly more efficient
    size_t child;
    for (; 2 * idx <= m_size; idx = child)
    {
        child = max_priority_child(idx);
        if (m_higher_priority(m_elems[child], m_elems[idx]))
            std::swap(m_elems[idx], m_elems[child]);
        else
            break; // optimization: break early if possible
    }
}

template <class T, class Compare>
void Heap<T, Compare>::heapify_up(size_t idx)
{
    if (idx == root())
        return;
    size_t parentIdx = parent(idx);
    if (m_higher_priority(m_elems[idx], m_elems[parentIdx]))
    {
        std::swap(m_elems[idx], m_elems[parentIdx]);
        heapify_up(parentIdx);
    }
}

template <class T, class Compare>
Heap<T, Compare>::Heap(size_t capacity)
    : m_elems(capacity + 1), m_size{0} // Start from 1?
{
    // nothing to do
}

template <class T, class Compare>
Heap<T, Compare>::Heap(const std::vector<T> &elems)
    : m_elems(elems.size() + 1), m_size{elems.size()}
{
    // This is the STL way:
    std::copy(elems.cbegin(), elems.cend(), m_elems.begin() + 1);
    buildHeap();
}

template <class T, class Compare>
void Heap<T, Compare>::pop()
{
    // Remove the element with the highest priority.
    if (empty())
        throw std::underflow_error("pop() called but the heap is empty");

    m_elems[1] = std::move(m_elems[m_size--]);
    m_elems.pop_back();
    heapify_down(1);
}

template <class T, class Compare>
const T &Heap<T, Compare>::peek() const
{
    // Your implementation
    return m_elems[1];
}

template <class T, class Compare>
void Heap<T, Compare>::push(T elem)
{
    std::cout << " push () " << std::endl;
    // Add an element to the heap
    // emplace_back is more efficient for complex objects
    m_elems.emplace_back(elem);

    // iterative version to heapifyup
    size_t idx = ++m_size;
    std::cout << "idx = " << idx << std::endl;
    size_t p;
    for (; idx > 1; idx = p)
    {
        p = parent(idx);
        if (m_higher_priority(m_elems[idx], m_elems[p]))
        {
            std::cout << " higher " << std::endl;
            std::swap(m_elems[idx], m_elems[p]);
        }
        else
        {
            std::cout << " not higher " << std::endl;
            break;
        }
    }
}

template <class T, class Compare>
bool Heap<T, Compare>::empty() const
{
    return m_size == 0; // Your implementation
}

template <class T, class Compare>
void Heap<T, Compare>::buildHeap()
{
    // perform heapify_down so that
    // most element only need to move down one level
    for (int i = m_size / 2; i > 0; --i)
        heapify_down(i);
}

template <class Type, class Comp>
std::ostream &operator<<(std::ostream &out,
                         const Heap<Type, Comp> &toPrint)
{
    out << "[";
    for (size_t i = 1; i < toPrint.m_size; ++i)
        out << " " << (toPrint.m_elems)[i];

    out << " ]" << std::endl
        << std::endl;
    return out;
}

template <class T, class Compare>
void Heap<T, Compare>::decrease_key(size_t idx)
{
    std::swap(m_elems[root()], m_elems[idx]);
    buildHeap();
}