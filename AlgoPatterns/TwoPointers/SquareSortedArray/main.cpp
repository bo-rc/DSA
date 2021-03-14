/**
 * 
Problem Statement #
Given a sorted array, create a new array containing squares of 
all the numbers of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0, 1, 1, 4, 9]
 */

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class SortedArraySquares
{
public:
    static vector<int> makeSquares(const vector<int> &arr)
    {
        vector<int> squared;
        transform(arr.cbegin(), arr.end(), back_inserter(squared), [](auto a) { return a * a; });

        vector<int> squared_sorted;
        // the problem is that we have both + and - int in the arr
        for (size_t front = 0, back = squared.size(); front < back; /* update in loop body */)
        {
            if (squared[front] < squared[back - 1])
            {
                squared_sorted.push_back(squared[back - 1]);
                --back;
            }
            else
            {
                squared_sorted.push_back(squared[front]);
                ++front;
            }
        }

        reverse(squared_sorted.begin(), squared_sorted.end());
        return squared_sorted;
    }

    static vector<int> makeSquares2(const vector<int> &arr)
    {

        auto itr = find_if(arr.cbegin(), arr.cend(), [](int a) { return a > 0; });
        int negEnd = distance(arr.cbegin(), itr);

        vector<int> squared_sorted;
        for (size_t front = negEnd, back = negEnd; front > 0 or back < arr.size() - 1; /* update in loop body */)
        {
            if (-arr[front - 1] < arr[back])
            {
                squared_sorted.push_back(arr[front - 1] * arr[front - 1]);
                front--;
            }
            else
            {
                squared_sorted.push_back(arr[back] * arr[back]);
                back++;
            }
        }

        return squared_sorted;
    }

    static vector<int> makeSquares3(const vector<int> &arr)
    {
        int n = arr.size();
        vector<int> squares(n);
        int highestSquareIdx = n - 1;
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int leftSquare = arr[left] * arr[left];
            int rightSquare = arr[right] * arr[right];
            if (leftSquare > rightSquare)
            {
                squares[highestSquareIdx--] = leftSquare;
                left++;
            }
            else
            {
                squares[highestSquareIdx--] = rightSquare;
                right--;
            }
        }
        return squares;
    }
};

int main(int argc, char *argv[])
{
    vector<int> result = SortedArraySquares::makeSquares2(vector<int>{-2, -1, 0, 2, 3});
    for (auto num : result)
        cout << num << " ";
    cout << endl;

    result = SortedArraySquares::makeSquares2(vector<int>{-3, -1, 0, 1, 2});
    for (auto num : result)
        cout << num << " ";
    cout << endl;
}
