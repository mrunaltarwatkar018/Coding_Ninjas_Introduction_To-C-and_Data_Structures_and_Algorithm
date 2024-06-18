/*
        Question  : Binary Search Recursive

        Problem statement

            Given an integer sorted array (sorted in increasing order)
            and an element x, find the x in given array using binary search.
            Return the index of x.

            Return -1 if x is not present in the given array.

            Note : If given array size is even, take first mid.

            Detailed explanation ( Input/output format, Notes, Images )
                Input format :
                    Line 1 : Array size
                    Line 2 : Array elements (separated by space)
                    Line 3 : x (element to be searched)

                Sample Input :
                6
                2 3 4 5 6 8
                5

                Sample Output:
                3


*/

#include <iostream>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched

int binarysearch(int input[], int start, int end,
                 int element)
{ // all elements must be sorted
    if (end >= start)
    {
        int mid = (start + end) / 2; // middle element of input[]
        if (input[mid] == element)
        {
            return mid; // mid is the index of element
        }
        if (input[mid] > element)
        {
            return binarysearch(input, start, mid - 1, element); // recursive call
        }
        else
        {
            return binarysearch(input, mid + 1, end, element);
        }
    }
    else
    {
        return -1;
    }
}

int binarySearch(int input[], int size, int element)
{
    // Write your code here
    binarysearch(input, 0, size - 1, element);
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}


























// #include <iostream>
// using namespace std;

// int binarySearch(int input[], int l, int r, int element)
// {
//     if (r >= l)
//     {
//         int mid = l + (r - l) / 2;
//         if (input[mid] == element)
//             return mid;
//         else if (input[mid] > element)
//             return binarySearch(input, l, mid - 1, element);
//         else
//             return binarySearch(input, mid + 1, r, element);
//     }
//     return -1;
// }

// int binarySearch(int input[], int size, int element)
// {
//     // Write your code here
//     binarySearch(input, 0, size - 1, element);
// }

// int main() {
//     int input[100000],length,element, ans;
//     cin >> length;
//     for(int i =0;i<length;i++)
//     {
//         cin >> input[i];;
//     }
//     cin>>element;
//     ans = binarySearch(input, length, element);
//     cout<< ans << endl;
// }