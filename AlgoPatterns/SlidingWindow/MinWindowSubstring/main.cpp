/**
 * Given a string and a pattern, find the smallest substring in the given string 
 * which has all the characters of the given pattern.
 * 
 * Example:
 * Input: String="aabdec", Pattern="abc"
 * Output: "abdec"
 * Explanation: The smallest substring having all characters of the pattern is "abdec"
 * 
 * Sliding window:
 *  1. expand right
 *  2. check if condition is met
 *      2.a shrink left until condition is not met, record result of last met, expand right.
 *  3. termination condition is when expand cannot happen anymore.
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct result_t{
    int size;
    int start;
};

// this is a N^2 algorithm
std::unordered_map<char, int> buildCharMap(const std::string& pattern)
{
    std::unordered_map<char, int> map;
    for (const auto& ch : pattern)
    {
        if (map.count(ch) == 0)
            map.insert({ch, 1});
        else
            ++map[ch]; 
    }

    return map;
}

class MinimumWindowSubstring
{
public:

    static string findSubstring(const std::string &str, const std::string &pattern)
    {
        result_t range = _findSubstring(str, pattern);

        if (range.size > str.size())
            return string{};

        return str.substr(range.start, range.size);
    }

    static result_t _findSubstring(const std::string &str, const std::string &pattern)
    {
        result_t res{str.size() + 1, 0};

        auto charMap = buildCharMap(pattern);
        decltype(charMap) countMap(charMap);
        for_each(countMap.begin(), countMap.end(), [](auto& element) { element.second = 0;});

        int matched = 0;
        int min_size = 0;

        // sliding window
        int left = 0;
        int right = 0;
        int num_matched = 0;
        //
        while (right < str.size()) 
        {           
            char currenChar = str[right];
            // str[right] is an important char
            if ( charMap.count(currenChar) != 0 )
            {
                if (charMap[currenChar] > 0)
                    ++num_matched;

                --charMap[currenChar];
            }

            // check if fully matched
            while (num_matched == pattern.size())
            {
                int new_size = right - left + 1;
                if (res.size > new_size)
                {
                    res.start = left;
                    res.size = right - left + 1;
                }

                // then we try to SHRINK from the left
                char leftChar = str[left];

                // when leftChar is a useful char, dropping it -> update num_matched.
                if (charMap.count(leftChar) != 0)
                {
                    if (charMap[leftChar] >= 0)
                        --num_matched;
                    ++charMap[leftChar];
                }
                // shrinking
                ++left;
            }

            // then we EXPAND to the right
            ++right;
        }
    
    return res;
        
    }
};

int main(int argc, char *argv[])
{
    std::string str {"aabdec"};
    std::string pattern {"abc"};
    std::cout << "String: " << str << " -> Mini substring contains: " 
    << pattern << " is: " << MinimumWindowSubstring::findSubstring(str, pattern) << std::endl;

    return 0;
}
