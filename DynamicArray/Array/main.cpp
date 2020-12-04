#include "array.h"
#include <iostream>
#include <cassert>


void test()
{
    // test default constructor
    Array myArray0;
    assert(myArray0.capacity() == 0);
    assert(myArray0.size() == 0);

    // test Array(size_t capacity);
    Array myArray1(9);
    assert(myArray1.capacity() == 9);
    assert(myArray1.size() == 0);

    // test push_back()
    Array myOtherArray;
    for (int i = 0; i < 20; ++i)
    {
        // test push_back() and [] operator
        myOtherArray.push_back(i);
        std::cout << "pushed back, size: " << myOtherArray.size() << " cap: " << myOtherArray.capacity() << std::endl;
    }

    // test front() and back()
    assert(myOtherArray.front() == 0);
    assert(myOtherArray.back() == 19);

    // test copy constructor
    Array myArray2(myOtherArray);
    for (size_t i = 0; i < myOtherArray.size(); ++i)
    {
        assert(myOtherArray[i] == myArray2[i]);
    }

    // test clear()
    myArray2.clear();
    assert(myArray2.size() == 0);

    // test move constructor
    Array myArray3(std::move(myOtherArray));
    assert(myArray3.size() == 20);
    assert(myOtherArray.size() == 0);

    // test assignment operator overloads
    Array myArray4 {};
    myArray4 = myArray3;
    myArray4 = std::move(myArray3);
    assert(myArray3.size() == 0);

    // test pop_back(), empty()
    while (not myArray4.empty())
    {
        myArray4.pop_back();
        std::cout << "pop back, size: " << myArray4.size() << " cap: " << myArray4.capacity() << std::endl;
    }
}

int main()
{
    // add testing here

    test();

    return 0;
}
