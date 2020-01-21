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
    static bool findPermutation(const std::string &str, const std::string &pattern)
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
};

int main(int argc, char *argv[])
{
    std::cout << std::boolalpha;
    std::cout << "Permutation exist: " << PermutationInString::findPermutation("oidbcaf", "abc") << std::endl;
    std::cout << "Permutation exist: " << PermutationInString::findPermutation("odicf", "dc") << std::endl;
    std::cout << "Permutation exist: " << PermutationInString::findPermutation("bcdxabcdy", "bcdyabcdx") << std::endl;
    std::cout << "Permutation exist: " << PermutationInString::findPermutation("aaacb", "abc") << std::endl;
}
