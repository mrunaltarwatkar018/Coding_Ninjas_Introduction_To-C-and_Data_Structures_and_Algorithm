/*
        Question  : Second Largest in Array

        Problem statement
            You have been given a random integer array/list(ARR) of size N.
            You are required to find and return the second largest element
            present in the array/list.

            Detailed explanation ( Input/output format, Notes, Images )

            Input format :
            The first line contains an integer 'N' representing the size of the array/list.

            The second line contains 'N' single space separated integers representing the elements in the array/list.

            Output Format :
            Return the second largest element in the array/list.

            Constraints :
            0 <= N <= 10^2
            1<=arr[i]<=10^3

            Time Limit: 1 sec

            Sample Input 1:
            5
            4 3 10 9 2

            Sample Output 1:
            9

            Sample Input 2:
            7
            13 6 31 14 29 44 3

            Sample Output 2:
            31
*/

#include <iostream>
using namespace std;

int findSecondLargest(int *input, int n)
{
    // Write your code here
    int secondLargest = -2e31;
    int largest = input[0];

    for (int i = 1; i < n; i++)
    {
        if (input[i] >= largest)
        {
            if (input[i] > largest)
            {
                secondLargest = largest;
                largest = input[i];
            }
        }
        else if (input[i] > secondLargest)
        {
            secondLargest = input[i];
        }
    }
    return secondLargest;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = findSecondLargest(arr, n);
    cout << ans;
    return 0;
}
