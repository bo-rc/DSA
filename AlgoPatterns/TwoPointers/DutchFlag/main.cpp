/**
 * 
Problem Statement #
Given an array containing 0s, 1s and 2s, sort the array in-place. 
You should treat numbers of the array as objects, 
hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: 
red, white and blue; and since our input array also consists of three different numbers 
that is why it is called Dutch National Flag problem.


c.f. Heapsort is an in-place sorting algorithm

Example 1:

Input: [1, 0, 2, 1, 0]
Output: [0 0 1 1 2]
Example 2:

Input: [2, 2, 0, 1, 2, 0]
Output: [0 0 1 2 2 2 ]
 */

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class DutchFlag
{
public:
    static void sort2(vector<int> &arr)
    {
        make_heap(arr.begin(), arr.end());
        cout << "heap: " << endl;
        for (auto a : arr)
            cout << a << ",";
        cout << endl;
        sort_heap(arr.begin(), arr.end());
        cout << "sorted: " << endl;
        for (auto a : arr)
            cout << a << ",";
        cout << endl;
    }

    static void sort(vector<int> &arr)
    {
        cout << "input arr: " << endl;
        for (auto num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
        // since we have 3 distinguished numbers,
        // we can use two ptr to partition the arr:
        // 0 0 ... 0 | 1 1 ... 1 | 2 2 ... 2
        //           ^           ^
        //          low        high
        // 1, 0, 2, 1, 0
        //
        int low = 0;
        int high = arr.size();

        for (int i = 0; i < high; ++i)
        {
            if (arr[i] == 0)
            {
                swap(arr[i], arr[low++]);
                if (arr[i] == 2)
                    swap(arr[i], arr[--high]);
            }
            else if (arr[i] == 2)
            {
                swap(arr[i], arr[--high]);
                if (arr[i] == 0)
                    swap(arr[i], arr[low++]);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> arr = {1, 0, 2, 1, 0};
    DutchFlag::sort(arr);
    cout << "result: " << endl;
    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // // this is for testing make_heap and sort_heap
    // arr = vector<int>{-1, 3, 2, 1, 6, 8, 0, 6, 5, 8, 9, 0, 6, 5, 3};
    // DutchFlag::sort2(arr);
    // for (auto num : arr)
    // {
    //     cout << num << " ";
    // }
}
