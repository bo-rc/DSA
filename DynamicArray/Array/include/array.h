/**
 * Implement Dynamic array of int
 * bonus: how about dynamic array of any type 'T'
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <memory>

class Array
{
public:
    /**
     * @brief Array default constructor
     */
    Array();

    /**
     * @brief Array constructs an array objects with pre-allocated space.
     * @param capacity, the capacity of the allocated space. This array may store
     *                  up to cap integers before it needs new memory allocation.
     */
    Array(size_t capacity);

    /**
     * @brief Array copy constructor
     * @param other
     */
    Array(const Array &other);

    /**
     * @brief Array move constructor
     * @param other
     */
    Array(Array &&other);

    ~Array();

    /**
     * @brief operator = Array copy assignment
     * @param other
     * @return
     */
    Array &operator=(const Array &other);

    /**
     * @brief operator = Array move assignment
     * @param other
     * @return
     */
    Array &operator=(Array &&other);

    /**
     * @brief size returns the number of elements in Array
     * @return
     */
    size_t size() const;

    /**
     * @brief capacity returns the maximum number of elements that the Array may store
     *                  before it needs new memory allocation
     * @return
     */
    size_t capacity() const;

    /**
     * @brief empty returns true if the array is empty, false if not empty
     * @return
     */
    bool empty() const;

    /**
     * @brief front returns the first element in array.
     * @return
     */
    int front() const;

    /**
     * @brief back returns the last element in array.
     * @return
     */
    int back() const;

    /**
     * @brief operator [], returns the ith element in array, w/o bound-checking
     * @param pos, the index of the element
     * @return
     */
    int &operator[](size_t pos);
    int operator[](size_t pos) const;

    /**
     * @brief clear clears array
     */
    void clear();

    /**
     * @brief push_back adds an element to the end of the array
     * @param ele the element being added.
     */
    void push_back(int ele);

    /**
     * @brief pop_back removes the element at the end of the array
     */
    void pop_back();

private:
    // add something here to store integers in an Array obj.
    // This class is basically a container, the private fields
    // may be used for internal storage of elements.

    std::unique_ptr<int[]> m_arr = nullptr;
    size_t m_cap;
    size_t m_size;
};

#endif // ARRAY_H
