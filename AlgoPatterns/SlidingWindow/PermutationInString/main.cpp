/**
 * Problem Statement
 * Permutation in a String (hard)
 * Given a string and a pattern, find out if the string contains any permutation of the pattern.
 * 
 * Example 1:
 * Input: String="oidbcaf", Pattern="abc"
 * Output: true
 * Explanation: The string contains "bca" which is a permutation of the given pattern.
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <set>
#include <vector>

// this is a N^2 algorithm
std::set<std::string> all_perm(std::string str)
{
    std::set<std::string> permSet;

    do
    {
        permSet.insert(str);
    } while (std::next_permutation(str.begin(), str.end())); // at most N/2 swaps per call

    return permSet;
}

class PermutationInString
{
public:
    static bool hasPermutation(const std::string &str, const std::string &pattern)
    {
        auto permSet = all_perm(pattern);

        for (size_t winStart = 0; winStart + pattern.size() - 1 < str.size(); ++winStart)
        {
            std::string window = str.substr(winStart, pattern.size());
            if (permSet.count(window) > 0)
            {
                return true;
            }
        }

        return false;
    }

    // anagram is permutation
    static std::vector<size_t> findStringAnagrams(const std::string &str, const std::string &pattern)
    {
        std::vector<size_t> res;
        auto permSet = all_perm(pattern);

        for (size_t winStart = 0; winStart + pattern.size() - 1 < str.size(); ++winStart)
        {
            std::string window = str.substr(winStart, pattern.size());
            if (permSet.count(window) > 0)
            {
                res.push_back(winStart);
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    std::cout << std::boolalpha;
    std::cout << "Permutation exist: " << PermutationInString::hasPermutation("oidbcaf", "abc") << std::endl;
    std::cout << "Permutation exist: " << PermutationInString::hasPermutation("odicf", "dc") << std::endl;
    std::cout << "Permutation exist: " << PermutationInString::hasPermutation("bcdxabcdy", "bcdyabcdx") << std::endl;
    std::cout << "Permutation exist: " << PermutationInString::hasPermutation("aaacb", "abc") << std::endl;

    std::cout << "Anagrams: " << std::endl;
    auto res = PermutationInString::findStringAnagrams("ppqp", "pq");

    std::cout << "[";
    for (const auto& index : res)
    {
        std::cout << index << ",";
    }
    std::cout << "]" << std::endl;

    return 0;
}
