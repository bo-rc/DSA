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
    static void findMaxCountChar(const std::map<char, size_t> &countMap, size_t &maxCount, char &maxCountChar)
    {
        for (const auto &kv : countMap)
        {
            if (kv.second > maxCount)
            {
                maxCount = kv.second;
                maxCountChar = kv.first;
            }
        }
    }

    static size_t findLength(const std::string &str, size_t k)
    {
        size_t maxLen{0};
        std::deque<char> stringWindow{};
        std::map<char, size_t> count{};

        size_t replaceCount = 0;
        size_t maxCount = 0;
        char longestChar{};

        for (const auto &ch : str)
        {
            stringWindow.push_back(ch);
            count[ch] += 1;

            // update longestChar
            if (count[ch] > maxCount)
            {
                maxCount = count[ch];
                longestChar = ch;
            }

            // update replaceCount
            replaceCount = stringWindow.size() - maxCount;

            // if over the limit: shrink window
            if (replaceCount > k)
            {
                char deleteChar = stringWindow.front();
                stringWindow.pop_front();

                // special treatment for longestChar
                // no decrease for replaceCount
                // update maxCount
                if (deleteChar == longestChar)
                {
                    // no decrease for replaceCount
                    // update maxCount
                    --count[deleteChar];
                    --maxCount;
                }
                else
                {
                    --replaceCount;
                }
            }

            // update result
            maxLen = stringWindow.size() > maxLen ? stringWindow.size() : maxLen;
        }
        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    std::deque<char> out;
    std::cout << " \"araaci\", 2 : " << LongestSubstringWithSameLettersAfterReplacement::findLength("araaci", 2)
              << std::endl;

    std::cout << " \"araaci\", 1 : " << LongestSubstringWithSameLettersAfterReplacement::findLength("araaci", 1)
              << std::endl;

    std::cout << " \"cbbebi\", 3 : " << LongestSubstringWithSameLettersAfterReplacement::findLength("cbbebi", 3)
              << std::endl;
}
