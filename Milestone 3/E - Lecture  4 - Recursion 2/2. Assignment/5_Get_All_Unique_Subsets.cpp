/*
        Question  : Get All unique Subsets

        Problem statement

            You are given an sorted integer array of size 'n'.

            Your task is to find and return all the unique subsets
            of the input array.

            Subsets are arrays of length varying from 0 to 'n', that
            contain elements of the array. But the order of elements
            should remain the same as in the input array.

            Note:
            The order of subsets is not important. You can return the
            subsets in any order. However, in the output, you will see
            the subsets in lexicographically sorted order.

            Constraints :
            1 <= n <= 15
            1 <= arr[i] <= 100

            Time Limit: 1 sec
            Example:
            Input: 'n' = 3, 'arr' = [12, 15, 20]

            Output: [[], [12], [12, 15], [12, 15, 20], [12, 20], [15], [15, 20], [20]]

            Sample Explanation: Since there are no repeated numbers, a total of 8 subsets are generated.
            Constraints :
            1 <= n <= 15
            1 <= arr[i] <= 100

            Time Limit: 1 sec


            Example:
            Input: 'n' = 3, 'arr' = [12, 15, 20]

            Output: [[], [12], [12, 15], [12, 15, 20], [12, 20], [15], [15, 20], [20]]

            Sample Explanation: Since there are no repeated numbers, a total of 8 subsets are generated.


            Input Format :
            The first line will contain the value of ‘n’.

            The second line will contain n integers, denoting the
            array 'arr' elements.

            Output format :
            Return all unique subsets in any order.

            Note :
            You don't need to print anything. It has already been taken care of. Just implement the given function.

            Sample Input 1 :
            3
            12 15 20

            Sample Output 1 :
            [] (this represents an empty array)
            12
            12 15
            12 15 20
            12 20
            15
            15 20
            20

            Explanation Of Sample Input 1 :
            Since there are no repeated numbers, 8 subsets are generated.
            Sample Input 2 :
            3
            1 1 2

            Sample Output 2 :
            []
            1
            1 1
            1 1 2
            1 2
            2

            Explanation Of Sample Input 2 :
            Since there are repeated numbers, the total number of unique subsets is 6.

            Expected Time Complexity :
            The expected time complexity is O(k * 2^n), where n is the size of the array and 'k' is the average size of a subset.

            Expected Space Complexity :
            The expected time complexity is O(k * 2^n), where n is the size of the array and 'k' is the average size of a subset.

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Runner
{
    vector<int> arr;
    int n;

public:
    void takeInput()
    {
        cin >> n;
        arr.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
    }
    void execute()
    {
        getUniqueSubsets(arr);
    }

    void executeAndPrintOutput()
    {
        auto c = getUniqueSubsets(arr);
        sort(c.begin(), c.end());

        for (auto val : c)
        {
            for (auto vall : val)
                cout << vall << ' ';
            cout << '\n';
        }
    }
};

// Recursive function to generate unique subsets
// void getUniqueSubsets(int indx, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
// {
//     // Base case: when the index reaches the end of the array
//     if (indx == arr.size())
//     {
//         ans.push_back(temp); // Add the current subset to the result
//         return;
//     }
//     // Include the current element in the subset
//     temp.push_back(arr[indx]);
//     getUniqueSubsets(indx + 1, arr, temp, ans);
//     // Exclude the current element and skip duplicates
//     temp.pop_back();
//     while (indx + 1 < arr.size() && arr[indx] == arr[indx + 1])
//     {
//         indx++;
//     }
//     // Move to the next unique element in the array
//     // and make a recursive call to generate subsets without including the current element
//     getUniqueSubsets(indx + 1, arr, temp, ans);
// }
// // Function to get all unique subsets of an array
// vector<vector<int>> getUniqueSubsets(vector<int> &arr)
// {
//     vector<int> temp;                    // Temporary vector to store subsets
//     vector<vector<int>> ans;             // Result vector to store all unique subsets
//     sort(arr.begin(), arr.end());        // Sort the input array to handle duplicates
//     getUniqueSubsets(0, arr, temp, ans); // Start the recursive process from index 0
//     return ans;                          // Return the final result
// }

// Another Approach

// Recursive function to generate unique subsets
void getUniqueSubsets(int indx, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
{
    // Base case: when the index reaches the end of the array
    if (indx == arr.size())
    {
        ans.push_back(temp); // Add the current subset to the result
        return;
    }
    // Include the current element in the subset
    temp.push_back(arr[indx]);
    getUniqueSubsets(indx + 1, arr, temp, ans);
    // Exclude the current element and skip duplicates
    temp.pop_back();
    while (indx + 1 < arr.size() && arr[indx] == arr[indx + 1])
    {
        indx++;
    }
    // Move to the next unique element in the array
    // and make a recursive call to generate subsets without including the current element
    getUniqueSubsets(indx + 1, arr, temp, ans);
}
// Function to get all unique subsets of an array
vector<vector<int>> getUniqueSubsets(vector<int> &arr)
{
    vector<int> temp;                    // Temporary vector to store subsets
    vector<vector<int>> ans;             // Result vector to store all unique subsets
    sort(arr.begin(), arr.end());        // Sort the input array to handle duplicates
    getUniqueSubsets(0, arr, temp, ans); // Start the recursive process from index 0
    return ans;                          // Return the final result
}

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
