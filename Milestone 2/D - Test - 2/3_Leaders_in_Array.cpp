/* =================================================================================================================== */
/* 
    Question  : Leaders in array
                
                Given an integer array A of size n. Find and print all the 
                leaders present in the input array. An array element A[i] is 
                called Leader, if all the elements following it (i.e. present 
                at its right) are less than or equal to A[i].

                Print all the leader elements separated by space and in the 
                same order they are present in the input array.

                Input format : 
                                Line 1 : Integer n, size of array
                                Line 2 : Array A elements (separated by space)

                Output Format : 
                                leaders of array (separated by space)

                Constraints :   
                                1 <= n <= 10^6

                Sample Input 1 :    
                                    6
                                    3 12 34 2 0 -1
                                          
                Sample Output 1 :   
                                    34 2 0 -1

                Sample Input 2 :    
                                    5 
                                    13 17 5 4 6
                                          
                Sample Output 2 :   
                                    17 6
                                   
*/


#include<iostream>
#include<climits>
using namespace std;

// One Method
void Leaders(int* arr,int len)
{
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/

	for ( int i = 0; i < len; i++ ) {
		bool isLeader = true;
		for ( int j = i + 1; j < len; j++ ) {
			if ( arr[i] < arr[j] ) {
				isLeader = false;
				break;
			}
		}

		if ( isLeader ) {
			cout << arr[i] << ' ';
		}
	}
}


// Another Method

// Time Complexity : O(n)

// void Leaders ( int arr, int len ) {
//     int j = 0;
//     int *save = new int[len];
//     int largest = INT_MIN;          // largest contains the maximum value of leading array.
//     for ( int i = len - 1; i >= 0; i-- ) {
        
//         // if element at current index is greater than largest then put it in array and make ot largest;
//         if ( arr[i] >= largest ) { 
//             save[j] = arr[i];
//             j++;
//             largest = arr[i];
//         }
//     }

//     // print the array in reverse order
//     for ( int i = j - 1; i >= 0; i-- ) {
//         cout << save[i] << " ";
//     }

// }

int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}