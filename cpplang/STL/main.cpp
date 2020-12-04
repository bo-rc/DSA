#include <cctype>
#include <string>
#include <algorithm>
#include <iostream>

int main()
{
    std::string str("(123) 456-5555");
    str.erase(std::remove_if(str.begin(), str.end(), 
                            [&](auto c) { return not std::isdigit(c);}), 
                            str.end());

    std::cout << str << std::endl; // Expected output: 1234565555
}