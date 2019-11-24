/**
 * Given an array of positive numbers and a positive number ‘S’, 
 * find the length of the smallest contiguous subarray whose sum 
 * is greater than or equal to ‘S’. Return 0, if no such subarray exists.
 */

#include <iostream>
#include <limits>
#include <string>
#include <deque>
#include <map>
#include "Output.hpp"

class LongestSubstringKDistinct
{
public:
    static size_t findLength(const std::string &str, int len, std::deque<char> &outString)
    {
        size_t maxLen{};
        std::deque<char> stringWindow{};
        std::map<char, int> charDict{};

        for (const char &ch : str)
        {
            charDict[ch] += 1;
            stringWindow.push_back(ch);

            // the size of charDict equals to number of distinctive characters
            while (charDict.size() > len and (not stringWindow.empty()))
            {
                auto frontChar = std::move(stringWindow.front());
                stringWindow.pop_front();

                if (charDict[frontChar] > 1)
                {
                    charDict[frontChar] -= 1;
                }
                else // when charDict[frontChar] == 1 : remove the char
                {
                    charDict.erase(frontChar);
                }
            }

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
    std::cout << " \"araaci\", 2 : " << LongestSubstringKDistinct::findLength("araaci", 2, out)
              << std::endl;
    std::cout << out;

    std::cout << " \"araaci\", 1 : " << LongestSubstringKDistinct::findLength("araaci", 1, out)
              << std::endl;
    std::cout << out;

    std::cout << " \"cbbebi\", 3 : " << LongestSubstringKDistinct::findLength("cbbebi", 3, out)
              << std::endl;
    std::cout << out;
}
