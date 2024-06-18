/* 
    Question  : First Index of Number 
                Given an array of length N and an integer x, you need to
                find and return the first index of integer x present in the
                array. Return -1 if it is not present in the array.

                First index means, the index of first occurrence of x in the 
                input array.

                Do this recursively. Indexing in the array starts from 0.
        
                Input format : 
                                Line 1 : An Integer N i.e. size of array
                                Line 2 : N integers which are elements of the array, 
                                         separated by spaces
                                Line 3 : Integer x
                Output Format : first index or -1
                Constraints :   1 <= n <= 10^3
                Sample Input 1 : 4          (Size of array)
                                 9 8 10 8   (The array elements)
                                 8          (x)
                Sample Output 1 : 1

*/


#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  for (int i = 0; i < size; i++) {
    if (input[i] == x) {
      return i;
    }
  }
  return -1;
}


// Another Approach
// Time Complexity : O(n)
// Space Complexity : O(n)
// where n is size of input array


// int firstIndex( int input[], int size, int x ) {
//     if ( size == 0 ) {
//         return -1;
//     }

//     if ( input[0] == x ) {
//         return 0;
//     }

//     int ans = firstIndex1 ( input + 1, size - 1, x );

//     if ( ans != -1 ) {
//         return ans + 1;
//     } else {
//         return ans;
//     }
// }


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex(input, n, x) << endl;

}


