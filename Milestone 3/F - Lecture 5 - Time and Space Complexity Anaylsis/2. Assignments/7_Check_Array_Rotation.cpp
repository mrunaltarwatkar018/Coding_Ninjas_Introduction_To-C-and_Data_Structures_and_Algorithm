
/* =================================================================================================================== */
/* 
    Question  : Check Array Rotation
                You have been given an integer array/list(ARR) of size N. 
                It has been sorted(in increasing order) and then rotated 
                by some number 'K' (K is greater than 0) in the right 
                hand direction.
                Your task is to write a function that returns the value 
                of 'K', that means, the index from which the array/list 
                has been rotated.

                Input format : 
                                The first line contains an Integer 't' which denotes 
                                the number of test cases or queries to be run. Then the 
                                test cases follow.
                                First line of each test case or query contains an 
                                integer 'N' representing the size of the array/list.
                                Second line contains 'N' single space separated integers 
                                representing the elements in the array/list.

                Output Format : 
                                For each test case, print the unique element present in the array.
                                Output for every test case will be printed in a separate line.

                Constraints :   1 <= t <= 10^2
                                0 <= N <= 10^5
                                Time Limit: 1 sec

                Sample Input 1 : 1        
                                 6   
                                 5 6 1 2 3 4
                Sample Output 1 : 2

                Sample Input 1 :    2
                                    5
                                    3 6 8 9 10
                                    4
                                    10 20 30 1        
                Sample Output 1 :   0
                                    3                   
*/
#include <iostream>
using namespace std;
// #include "solution.h"

int arrayRotateCheck(int *input, int size)
{
    // Write your code here
    int index = 0;
    for (int i = 1; i < size; i++)
        if (input[i] < input[i - 1])
            index = i;
    return index;
}

int binarySearch(int vec[], int start, int end ) {
    int n = end;
    while ( start <= end ) {
        int mid = start + (end - start)/2;
        if (vec[start] <= vec[end] ) 
            return start;
            int next = ( mid + 1 ) % n;
            int prev = ( mid - 1 + n ) % n;
        if (vec[mid] < vec[next] && vec[mid] < vec[prev]) {
            return mid;
        }
        else if ( vec[start] <= vec[mid] ) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }         
    }
    return 0;
}

// int arrayRotateCheck(int *input, int size) {
//   // Write your code here
//   return binarySearch(input, 0, size - 1);
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cout << arrayRotateCheck(input, size) << endl;
        delete[] input;
    }
    return 0;
}