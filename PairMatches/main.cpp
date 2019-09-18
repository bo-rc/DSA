#include <iostream>
#include <vector>
#include "count.hpp"
#include "MyClass.hpp"

int main()
{
    std::vector<float> fArray_1{1.1, 1.2, 2.2, 5.4};
    std::vector<float> fArray_2{1.1, 0.2, 2.2, 1.4};

    std::cout << "float test, matched pairs: "
              << count(fArray_1, fArray_2) << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "fu" << std::endl;
    }

    std::vector<int> iArray_1{1, 2, 3, 4};
    std::vector<int> iArray_2{1, 3, 2, 4};

    std::cout << "int test, matched pairs: "
              << count(iArray_1, iArray_2) << std::endl;

    std::vector<MyClass> cArray_1;
    std::vector<MyClass> cArray_2;

    cArray_1.emplace_back(MyClass(2));
    cArray_1.emplace_back(MyClass(4));
    cArray_1.emplace_back(MyClass(6));

    cArray_2.emplace_back(MyClass(1));
    cArray_2.emplace_back(MyClass(4));
    cArray_2.emplace_back(MyClass(6));

    std::cout << "MyClass test, matched pairs: "
              << count(cArray_1, cArray_2) << std::endl;
}