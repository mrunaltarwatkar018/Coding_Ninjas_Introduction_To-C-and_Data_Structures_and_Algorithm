#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* =================================================================================================================== */
/*
    Question  : All Index of Number
                Given an array of length N and an integer x, you need to
                find all the indexes where x is present in the input array.
                Save all the indexes in an array (in increasing order).

                Do this recursively. Indexing in the array starts from 0.

                Input format :
                                Line 1 : An Integer N i.e. size of array
                                Line 2 : N integers which are elements of the array,
                                         separated by spaces
                                Line 3 : Integer x
                Output Format : indexes where x is present in the array (separated by space)
                Constraints :   1 <= n <= 10^3
                Sample Input 1 : 5          (Size of array)
                                 9 8 10 8 8   (The array elements)
                                 8          (x)
                Sample Output 1 : 1 3 4

*/

#include <iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[])
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Save all the indexes in the output array passed and return the size of output array.
       Taking input and printing output is handled automatically.
    */
    if (size == 0)
    {
        return 0;
    }

    // Getting the recursive answer
    int smallAns = allIndexes(input + 1, size - 1, x, output);

    if (input[0] == x)
    {
        for (int i = smallAns - 1; i >= 0; i--)
        {
            output[i + 1] = output[i] + 1;
        }

        output[0] = 0;
        smallAns++;
    }
    else
    {

        for (int i = smallAns - 1; i >= 0; i--)
        {
            output[i] = output[i] + 1;
        }
    }
    return smallAns;
}



// another way
// int allIndexes(int input[], int size, int x, int output[]) {
//   /* Don't write main().
//      Don't read input, it is passed as function argument.
//      Save all the indexes in the output array passed and return the size of output array.
//      Taking input and printing output is handled automatically.
//   */
//   if (size == 0) {
//     return 0;
//   }

//   // Getting the recursive answer
//   int smallAns = allIndexes(input + 1, size - 1, x, output);

//   if (input[0] == x) {
//     for (int i = smallAns - 1; i >= 0; i--) {
//       output[i + 1] = output[i] + 1;
//     }

//     output[0] = 0;
//     smallAns++;
//   } else {

//     for (int i = smallAns - 1; i >= 0; i--) {
//       output[i] = output[i] + 1;
//     }
//   }
//   return smallAns;
// }


// void findIndexes ( int input[], int currIndex, int size, int x, int output[], int &k ) {
//     if ( currIndex == size ) {
//         return;
//     }

//     if ( input[currIndex] == x ) {
//         output[k] = currIndex;
//         k++;
//     }

//     findIndexes(input, currIndex + 1, size, x, output, k );
// }

// int allIndexes1( int input[], int size, int x, int output[] ) {
//     int k = 0;
//     findIndexes( input, 0, size, x, output, k );
//     return k;
// }

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;

    delete[] output;
}
