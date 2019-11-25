/**
 * Problem Statement
 * Given a string with lowercase letters only, 
 * if you are allowed to replace no more than ‘k’ letters with any letter, 
 * find the length of the longest substring having the same letters after replacement.
 * 
 * Example 1:
 *  Input: String="aabccbb", k=2
 *  Output: 5  
 *  Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
 * 
 * Example 2:
 *  Input: String="abbcb", k=1
 *  Output: 4
 *  Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
 * 
 * Example 3:
 *  Input: String="abccde", k=1
 *  Output: 3
 *  Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".
 */

#include <iostream>
#include <limits>
#include <string>
#include <deque>
#include <map>
#include "Output.hpp"

class LongestSubstringWithSameLettersAfterReplacement
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
    std::cout << " \"araaci\", 2 : " << LongestSubstringWithSameLettersAfterReplacement::findLength("araaci", 2, out)
              << std::endl;
    std::cout << out;

    std::cout << " \"araaci\", 1 : " << LongestSubstringWithSameLettersAfterReplacement::findLength("araaci", 1, out)
              << std::endl;
    std::cout << out;

    std::cout << " \"cbbebi\", 3 : " << LongestSubstringWithSameLettersAfterReplacement::findLength("cbbebi", 3, out)
              << std::endl;
    std::cout << out;
}
