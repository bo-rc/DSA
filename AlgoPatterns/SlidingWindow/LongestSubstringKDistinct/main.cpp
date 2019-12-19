/**
 * Problem Statement
 *  Given a string, find the length of the longest substring in it with no more than K distinct characters.
 * 
 * Example 1:
 *  Input: String="araaci", K=2
 *  Output: 4   
 *  Explanation: The longest substring with no more than '2' distinct characters is "araa".
 * 
 * Example 2:
 *  Input: String="araaci", K=1
 *  Output: 2
 *  Explanation: The longest substring with no more than '1' distinct characters is "aa".
 * 
 * Example 3:
 *  Input: String="cbbebi", K=3
 *  Output: 5
 *  Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
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

            // the size of charDict is the number of keys,
            // equals to number of distinctive characters
            // when the number > len, remove a front element
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

            // update with better result
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
