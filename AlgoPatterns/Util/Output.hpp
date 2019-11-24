#include <vector>
#include <iostream>

// using template template for generic cout of all container types
template <typename T, template <typename...> class Container, typename... Args>
std::ostream &operator<<(std::ostream &out, const Container<T, Args...> &cont)
{
    out << "Container type: " << typeid(cont).name() << " of size: " << cont.size() << " elements: ";
    for (const auto &ele : cont)
    {
        out << ele << ", ";
    }
    out << std::endl;

    return out;
}