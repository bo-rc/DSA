/**
 * Problem Statement
 * Given an array of sorted numbers and a target sum, 
 * find a pair in the array whose sum is equal to the given target.
 * 
 * Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.
 * 
 * Example 1:
 * Input: [1, 2, 3, 4, 6], target=6
 * Output: [1, 3]
 * Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
 */

using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum
{
public:
    static pair<int, int> search(const vector<int> &arr, int targetSum)
    {
        // TODO: Write your code here
        return make_pair(-1, -1);
    }
};

int main(int argc, char *argv[])
{
    auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
    cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
    result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
    cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
    return 0;
}