/**
 * Given an array of positive numbers and a positive number ‘S’, 
 * find the length of the smallest contiguous subarray whose sum 
 * is greater than or equal to ‘S’. Return 0, if no such subarray exists.
 */

#include <iostream>
#include <limits>
#include <string>
#include <deque>
#include <set>
#include "Output.hpp"

class NoRepeatSubstring
{
public:
    static size_t findLength(const std::string &str, std::deque<char> &outString)
    {
        size_t maxLen{0};
        std::deque<char> stringWindow{};
        std::set<char> charSet{};

        for (const char &ch : str)
        {
            if (charSet.count(ch) > 0)
            {
                char frontChar;
                while ((frontChar = std::move(stringWindow.front())) != ch)
                {
                    stringWindow.pop_front();
                    charSet.erase(frontChar);
                }

                stringWindow.pop_front();
                charSet.erase(frontChar);
                stringWindow.push_back(ch);
                charSet.insert(ch);

                continue;
            }

            stringWindow.push_back(ch);
            charSet.insert(ch);

            if (stringWindow.size() > maxLen)
            {
                maxLen = stringWindow.size();
                outString = stringWindow;
            }
        }

        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    std::deque<char> out;
    std::cout << " \"aabccbb\": " << NoRepeatSubstring::findLength("aabccbb", out)
              << std::endl;
    std::cout << out;

    std::cout << " \"abbbb\": " << NoRepeatSubstring::findLength("abbbb", out)
              << std::endl;
    std::cout << out;

    std::cout << " \"abccde\": " << NoRepeatSubstring::findLength("abccde", out)
              << std::endl;
    std::cout << out;
}
