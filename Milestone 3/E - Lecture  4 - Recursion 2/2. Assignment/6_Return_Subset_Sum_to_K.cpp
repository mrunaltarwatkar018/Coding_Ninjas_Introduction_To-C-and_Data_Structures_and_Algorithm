/*
        Question  : Return Subset Sum to K

        Problem statement

            Given an array A of size n and an integer K, return all
            subsets of A which sum to K.

            Subsets are of length varying from 0 to n, that contain
            elements of the array. But the order of elements should
            remain same as in the input array.

            Note :
            The order of subsets are not important.


            Detailed explanation ( Input/output format, Notes, Images )

                Input format :
                Line 1 : Integer n, Size of input array
                Line 2 : Array elements separated by space
                Line 3 : K

                Constraints :
                1 <= n <= 20

                Sample Input :
                9
                5 12 3 17 1 18 15 3 17
                6

                Sample Output :
                3 3
                5 1
*/

#include <iostream>
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
    {{2, 1, 4},	// Length of this subset is 2
    {2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int startIndex, int output[][50], int k)
{
    if (startIndex == n)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int smallOutput1[1000][50], smallOutput2[1000][50];
    int size1 = subsetSumToK(input, n, startIndex + 1, smallOutput1, k);
    int size2 = subsetSumToK(input, n, startIndex + 1, smallOutput2, k - input[startIndex]);
    int row = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j <= smallOutput1[i][0]; j++)
        {
            output[row][j] = smallOutput1[i][j];
        }
        row++;
    }
    for (int i = 0; i < size2; i++)
    {
        output[row][0] = smallOutput2[i][0] + 1;
        output[row][1] = input[startIndex];
        for (int j = 1; j <= smallOutput2[i][0]; j++)
        {
            output[row][j + 1] = smallOutput2[i][j];
        }
        row++;
    }
    return row;
}
int subsetSumToK(int input[], int n, int output[][50], int k)
{
    return subsetSumToK(input, n, 0, output, k);
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
