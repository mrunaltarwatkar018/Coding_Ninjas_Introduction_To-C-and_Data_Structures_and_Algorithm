/*
        Question  : Swap Alternate

        Problem statement

            You have been given an array/list(ARR) of size N. You need
            to swap every pair of alternate elements in the array/list.

            You don't need to print or return anything, just change in
            the input array itself.

            Detailed explanation ( Input/output format, Notes, Images )

            Input Format :
            The first line contains an Integer 't' which denotes the number
            of test cases or queries to be run. Then the test cases follow.

            First line of each test case or query contains an integer 'N'
            representing the size of the array/list.

            Second line contains 'N' single space separated integers representing
            the elements in the array/list.

            Output Format :
            For each test case, print the elements of the resulting array in
            a single row separated by a single space.

            Output for every test case will be printed in a separate line.

            Constraints :
            1 <= t <= 10^2
            0 <= N <= 10^5

            Time Limit: 1sec

            Sample Input 1:
            1
            6
            9 3 6 12 4 32

            Sample Output 1 :
            3 9 12 6 32 4

            Sample Input 2:
            2
            9
            9 3 6 12 4 32 5 11 19
            4
            1 2 3 4

            Sample Output 2 :
            3 9 12 6 32 4 11 5 19
            2 1 4 3
*/

#include <iostream>
using namespace std;

void swapAlternate(int *arr, int size)
{
    // Write your code here
    int i;
    for (i = 0; i + 1 < size; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

// alternate way
void swapAlternate(int *arr, int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        swapAlternate(arr, size);
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete[] arr;
    }
}