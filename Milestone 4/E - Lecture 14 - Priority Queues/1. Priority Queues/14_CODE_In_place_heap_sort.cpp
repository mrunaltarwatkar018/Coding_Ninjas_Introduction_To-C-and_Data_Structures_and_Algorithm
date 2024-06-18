/* =================================================================================================================== */
/* 
    Question  : Code : In-place heap sort
                
                Given an integer array of size N. Sort this array 
                (in decreasing order) using heap sort.

                Note    : 
                        Space complexity should be O(1).

                Input Format :
                    The first line of input contains an integer, that 
                    denotes the value of the size of the array or N.
                    
                    The following line contains N space separated integers, 
                    that denote the value of the elements of the array.

                Output Formats :
                    The first and only line of output contains array elements 
                    after sorting. The elements of the array in the output are 
                    separated by single space. 
                
                Constraints :
                    1 <= n <= 10^6
                    Time Limit: 1 sec

                Sample Input 1 :
                    6 
                    2 6 8 5 4 3

                Sample Output 1 :
                    8 6 5 4 3 2
*/

#include <iostream>
using namespace std;

// One Method

// void heapSort(int arr[], int n)
// {
//     // Write your code
//     for (int i = 1; i < n; i++)
//     {
//         int childIndex = i;
//         while (childIndex > 0)
//         {
//             int parentIndex = (childIndex - 1) / 2;
//             if (arr[parentIndex] > arr[childIndex])
//             {
//                 int temp = arr[parentIndex];
//                 arr[parentIndex] = arr[childIndex];
//                 arr[childIndex] = temp;
//             }
//             else
//                 break;
//             childIndex = parentIndex;
//         }
//     }
//     int size = n;

//     while (size > 1)
//     {
//         int temp = arr[0];
//         arr[0] = arr[size - 1];
//         arr[size - 1] = temp;

//         size--;

//         int parentIndex = 0;
//         while (parentIndex < size)
//         {
//             int leftChildIndex = 2 * parentIndex + 1;
//             int rightChildIndex = 2 * parentIndex + 2;
//             int minIndex;
//             if (leftChildIndex < size && rightChildIndex < size)
//                 minIndex = (arr[leftChildIndex] <= arr[rightChildIndex]) ? leftChildIndex : rightChildIndex;
//             else if (leftChildIndex < size)
//                 minIndex = leftChildIndex;
//             else
//                 break;
//             if (arr[minIndex] < arr[parentIndex])
//             {
//                 int temp = arr[minIndex];
//                 arr[minIndex] = arr[parentIndex];
//                 arr[parentIndex] = temp;
//             }
//             else
//                 break;
//             parentIndex = minIndex;
//         }
//     }
// }

// Another Method

/*
    Time complexity: O(log(N))
    Space complexity: O(1)
    where N is the size of the input array
*/
void heapSort(int arr[], int n) {
    // Build the heap in input array
    for (int i = 1; i < n; i++) {
        int childIndex = i;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (arr[childIndex] < arr[parentIndex]) {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    // Remove elements
    int size = n;

    while (size > 1) {

        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;

        size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndx = 2 * parentIndex + 2;

        while (leftChildIndex < size) {
            int minIndex = parentIndex;

            if (arr[minIndex] > arr[leftChildIndex]) {
                minIndex = leftChildIndex;
            }

            if (rightChildIndx < size && arr[rightChildIndx] < arr[minIndex]) {
                minIndex = rightChildIndx;
            }

            if (minIndex == parentIndex) {
                break;
            }

            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndx = 2 * parentIndex + 2;
        }
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}