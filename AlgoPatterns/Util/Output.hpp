#include <vector>
#include <iostream>
#include <map>

#define CONT_INFO out << "Container type: " << typeid(cont).name() << " of size: " << cont.size() << " elements: \n";

// using template template for generic cout of all container types
template <typename T, template <typename...> class Container, typename... Args>
std::ostream &operator<<(std::ostream &out, const Container<T, Args...> &cont)
{
    CONT_INFO

    for (const auto &ele : cont)
    {
        out << ele << ", ";
    }
    out << std::endl;

    return out;
}

template <typename K, typename V, typename... Args>
std::ostream &operator<<(std::ostream &out, const std::map<K, V, Args...> &cont)
{
    CONT_INFO

    for (auto itr = cont.cbegin(); itr != cont.cend(); ++itr)
    {
        out << itr->first << ": " << itr->second << ", ";
    }
    out << std::endl;

    return out;
}