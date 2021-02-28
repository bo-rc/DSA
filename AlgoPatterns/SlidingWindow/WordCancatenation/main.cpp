/**
 * Problem Statement
 * Given a string and a list of words, 
 * find all the starting indices of substrings in the given string that are a concatenation of 
 * all the given words exactly once without any overlapping of words. 
 * It is given that all words are of the same length.
 * 
 * Example 1:
 * Input: String="catfoxcat", Words=["cat", "fox"]
 * Output: [0, 3]
 * Explanation: The two substring containing both the words are "catfox" & "foxcat".
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void step(int &index, int wordLen)
{
    index = index + wordLen;
}

class WordConcatenation
{
public:
    static vector<int> findWordConcatenation(const string &str, const vector<string> &words)
    {
        vector<int> ret{};
        int wordLen = words.at(0).size();
        unordered_map<string, int> wordMap{}; // to record occurance of words.
        for_each(words.cbegin(), words.cend(), [&wordMap](auto w) { ++wordMap[w]; });
        const unordered_map<string, int> wordMap_copy{wordMap};
        int left = 0;
        int right = 0;
        int numMatched = 0; // when we have words.size() num of words, we have complete match

        // sliding: expand and shrink
        while (right + wordLen <= str.size())
        {
            string word = str.substr(right, wordLen);

            if (wordMap.count(word) == 0) // non relevant word
            {
                step(right, wordLen);
                left = right;
                // need to reset counting state
                wordMap = wordMap_copy;
            }
            else // relevant word
            {
                if (wordMap[word] > 0) // still OK to add to collection
                {
                    ++numMatched;
                    --wordMap[word];
                    step(right, wordLen);
                }
                else // redundancy violation -> shrink from left until repeat word is dropped
                {
                    string leftWord{};
                    do
                    {
                        leftWord = str.substr(left, wordLen);
                        ++wordMap[leftWord];
                        --numMatched;
                        
                        step(left, wordLen);

                    } while (leftWord != word);
                }
            }

            if (numMatched == words.size())
                ret.push_back(left);
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{

    string inString{"muucatcatfoxmuufoxcat"};
    cout << inString << endl;
    vector<string> wordList{"cat", "fox"};

    vector<int> result =
        WordConcatenation::findWordConcatenation(inString, wordList);
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
