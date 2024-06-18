/*
        Question  : Print Subsets Sum to K

        Problem statement

                Given an array A and an integer K, print all subsets of A which sum to K.

                Subsets are of length varying from 0 to n, that contain elements of the
                array. But the order of elements should remain same as in the input array.


                Note :
                The order of subsets are not important. Just print them in different lines.


                Detailed explanation ( Input/output format, Notes, Images )

                    Input format :
                    Line 1 : Size of input array
                    Line 2 : Array elements separated by space
                    Line 3 : K

                    Sample Input:
                    9
                    5 12 3 17 1 18 15 3 17
                    6

                    Sample Output:
                    3 3
                    5 1
*/

#include <iostream>
using namespace std;

void psubset(int input[], int size, int k, int output[], int m)
{
    if (size == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        else
            return;
    }

    int o1[m + 1];
    int i;
    for (i = 0; i < m; i++)
    {
        o1[i] = output[i];
    }
    o1[i] = input[0];
    psubset(input + 1, size - 1, k - input[0], o1, m + 1);
    psubset(input + 1, size - 1, k, output, m);
}

void printSubsetSumToK(int input[], int size, int k)
{
    // Write your code here
    int m = 0;
    int output[m];
    psubset(input, size, k, output, m);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
