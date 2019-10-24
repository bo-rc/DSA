#include <vector>
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &arr)
{
    out << "Array of " << arr.size() << " elements: ";
    for (const auto &ele : arr)
    {
        out << ele << ", ";
    }
    out << std::endl;

    return out;
}