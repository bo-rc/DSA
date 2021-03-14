/**
 * Problem Statement #
Given an array of sorted numbers, remove all duplicates from it. 
You should not use any extra space; after removing the duplicates in-place return the length of the subarray that has no duplicate in it.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].
 */

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    auto iter = unique(arr.begin(), arr.end());
    arr.erase(iter, arr.end());
    return arr.size();
  }

  static int remove2(vector<int>& arr) {
    size_t slowPtr = 0;
    size_t fastPtr = 0;

    for (; fastPtr < arr.size(); ++fastPtr)
    {
        if (arr[slowPtr] == arr[fastPtr])
            continue;

        ++slowPtr;
        arr[slowPtr] = arr[fastPtr];
    }

    arr.erase(arr.cbegin() + slowPtr + 1, arr.cend());
    for (auto a : arr)
      cout << a << ",";
    cout << endl;
    return arr.size();
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove2(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove2(arr) << endl;
}
