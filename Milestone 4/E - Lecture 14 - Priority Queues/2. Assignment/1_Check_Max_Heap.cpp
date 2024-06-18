/* =================================================================================================================== */
/* 
    Question  : Check Max-Heap
                
                Given an array of integers, check whether it represents 
                max-heap or not. Return true if the given array represents 
                max-heap, else return false.

                Input format : 
                        The first line of input contains an integer, that 
                        denotes the value of the size of the array. Let us 
                        denote it with the symbol N.

                        The following line contains N space separated 
                        integers, that denote the value of the elements 
                        of the array.

                Output Format : 
                        The first and only line of output contains true if it 
                        represents max-heap and false if it is not a max-heap.

                Constraints :   
                                1 <= N <= 10^5
                                1 <= Ai <= 10^5
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    8
                                    42 20 18 6 14 11 9 4
                                          
                Sample Output 1 :   
                                    true
*/


#include <iostream>
using namespace std;

// One Method

// bool isMaxHeap(int arr[], int n) {
//     // Write your code here
//     for (int i = 0; i < n; i++) {
//         int leftChildIndex = 2 * i + 1;
//         int rightChildIndex = 2 * i + 2;
//         if (leftChildIndex < n && rightChildIndex < n && (!(arr[leftChildIndex] < arr[i] && arr[rightChildIndex] < arr[i])))
//             return false;
//         else if (leftChildIndex < n && !(arr[leftChildIndex] < arr[i]))
//             return false;
//     }
//     return true;
// }


// Another Method
/*
        Time Complexity : O(N)
        Space Complexity : O(1)

        where N is the size of the input array
*/

bool isMaxHeap( int arr[], int n ) {
        for ( int i = 0; 2 * i + 1 < n; i++ ) {
                int leftChildIndex = 2 * i + 1;
                int rightChildIndex = leftChildIndex + 1;

                if ( arr[i] < arr[leftChildIndex] ) {
                        return false;
                }

                if ( arr[i] < arr[rightChildIndex] ) {
                        return false;
                }
        }

        return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}