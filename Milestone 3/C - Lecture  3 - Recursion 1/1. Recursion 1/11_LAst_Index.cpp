#include<iostream>
using namespace std;


/* =================================================================================================================== */
/* 
    Question  : Last Index of Number 
                Given an array of length N and an integer x, you need to
                find and return the last index of integer x present in the
                array. Return -1 if it is not present in the array.

                Last index means - if x is present multiple times in the array, 
                return the index at which x comes last in the array.

                You should start traversing your array from 0, not from (N - 1).

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
                Sample Output 1 : 3

*/
#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  int index = 0;
  for (int i = 0; i < size; i++) {

    if (input[i] == x) {
      index = i;
      for (int j = i; j < size; j++) {
        if (input[j] == x) {
          index = j;
        }
      }
      return index;
    }
  }
  return -1;
}


// Another way
// Time Complexity : O(n)
// Space Complexity : O(n)
// where n is size of input array


int lastIndex1( int input[], int size, int x ) {
    if ( size == 0 ) {
        return -1;
    }

    int smallAns = lastIndex1 ( input + 1, size - 1, x );

    if ( smallAns != -1 ) {
        return smallAns + 1;
    }

    if ( input[0] == x ) {
        return 0;
    } else {
        return -1;
    }
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}





