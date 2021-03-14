/**
 * 
Problem 1: Given an unsorted array of numbers and a target ‘key’, 
remove all instances of ‘key’ in-place and return the new length of the array.

Example 1:

Input: [3, 2, 3, 6, 3, 10, 9, 3], Key=3
Output: 4
Explanation: The first four elements after removing every 'Key' will be [2, 6, 10, 9].
Example 2:

Input: [2, 11, 2, 2, 1], Key=2
Output: 2
Explanation: The first two elements after removing every 'Key' will be [11, 1].
 */

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class RemoveElement {
 public:
  static int remove(vector<int>& arr, int key) {
    
    auto itr = remove_if(arr.begin(), arr.end(), [key](int a) { return a == key;});
    arr.erase(itr, arr.end());

    return arr.size();
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {3, 2, 3, 6, 3, 10, 9, 3};
  cout << "Array new length: " << RemoveElement::remove(arr, 3) << endl;

  arr = vector<int>{2, 11, 2, 2, 1};
  cout << "Array new length: " << RemoveElement::remove(arr, 2) << endl;
}
