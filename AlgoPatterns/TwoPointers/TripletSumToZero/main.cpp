/**
 * 
Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.
 */

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero
{
public:
    static void getTriplets(int i, vector<int> &arr, vector<vector<int>> &triplets)
    {
        int targetSum = 0 - arr[i];
        int left = i + 1;
        int right = arr.size();
        while (left < right)
        {
            if (arr[left] + arr[right - 1] == targetSum)
            {
                triplets.push_back({arr[i], arr[left], arr[right - 1]});
                ++left, --right;
            }
            else if (arr[left] + arr[right - 1] < targetSum)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
    }
    static vector<vector<int>> searchTriplets(vector<int> &arr)
    {
        vector<vector<int>> triplets;

        sort(arr.begin(), arr.end());

        cout << "sorted array: " << endl;
        for (auto a : arr)
        {
            cout << a << ",";
        }
        cout << endl;

        // we maintain this progression:
        // elements left to arr[i] have already been processed
        for (int i = 0; i < arr.size() - 2; ++i)
        {
            // make sure do not duplicate triplets with the same start element
            // use do i - 1 check to make sure not skip cases like 0,0,0
            // i.e. always proceed when a new element is encountered, but do not repeat same leading element
            if (i > 1 and arr[i] == arr[i - 1])
                continue;
            getTriplets(i, arr, triplets);
        }

        return triplets;
    }
};

int main(int argc, char *argv[])
{
    vector<int> vec = {-3, -3, 0, 0, 0, 1, 2, -1, 1, -2};
    auto result = TripletSumToZero::searchTriplets(vec);
    for (auto vec : result)
    {
        cout << "[";
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;

    // vec = {-5, 2, -1, -2, 3};
    // result = TripletSumToZero::searchTriplets(vec);
    // for (auto vec : result)
    // {
    //     cout << "[";
    //     for (auto num : vec)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "]";
    // }
}
