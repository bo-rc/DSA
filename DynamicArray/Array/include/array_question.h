/**
 * Implement Dynamic array of int. i.e. this class behaves as std::vector<int>
 * bonus: how about dynamic array of any type 'T'
*/

/** 
 * Includes here 
*/ 
#include <cstddef>

class Array
{
public:
    /**
     * @brief What is this?
     */
    Array();

    /**
     * @brief Array constructs an array objects with pre-allocated space.
     * @param cap, the capacity of the allocated space. This array may store
     *             up to cap integers before it needs new memory allocation.
     */
    Array(size_t cap);

    /**
     * @brief What is this?
     * @param other
     */
    Array(const Array &other);

    /**
     * @brief What is this?
     * @param other
     */
    Array(Array &&other);

    /**
     * @brief What is RAII?
     * @param other
     */
    ~Array();

    /**
     * @brief What is this?
     * @param other
     * @return
     */
    Array &operator=(Array other);

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
    // This class is basically a container with a dynamic size, 
    // the private fields
    // may be used for internal storage of data.

};


// add implementations below


// complete tests below
void test()
{
    // test constructors

    // test front() and back()

    // test copy constructor

    // test pop_back(), empty()
    // Please test dynamic sizing of Array
}

int main()
{
    // add testing here
    test();
    return 0;
}

