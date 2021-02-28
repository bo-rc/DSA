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
    static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    unordered_map<string, int> wordFrequencyMap;
    for (auto word : words) {
      wordFrequencyMap[word]++;
    }

    vector<int> resultIndices;
    int wordsCount = words.size(), wordLength = words[0].length();

    for (int i = 0; i <= int(str.length()) - wordsCount * wordLength; i++) {
      unordered_map<string, int> wordsSeen;
      for (int j = 0; j < wordsCount; j++) {
        int nextWordIndex = i + j * wordLength;
        // get the next word from the string
        string word = str.substr(nextWordIndex, wordLength);
        if (wordFrequencyMap.find(word) ==
            wordFrequencyMap.end()) {  // break if we don't need this word
          break;
        }

        wordsSeen[word]++;  // add the word to the 'wordsSeen' map

        // no need to process further if the word has higher frequency than required
        if (wordsSeen[word] > wordFrequencyMap[word]) {
          break;
        }

        if (j + 1 == wordsCount) {  // store index if we have found all the words
          resultIndices.push_back(i);
        }
      }
    }

    return resultIndices;
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
