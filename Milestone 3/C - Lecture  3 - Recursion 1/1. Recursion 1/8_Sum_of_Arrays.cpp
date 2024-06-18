/* 
    Question 1 : Sum of Arrya 
                Given an array of length N, you need to find and return the 
                sum of all elements of the array.
                Do this recursively.
        
                Input format : 
                                Line 1 : An Integer N i.e. size of array
                                Line 2 : N integers which are elements of the array, 
                                         separated by spaces
                Output Format : Sum
                Constraints :   1 <= n <= 10^3
                Sample Input 1 : 3
                                 9 8 9
                Sample Output 1 : 26
                Sample Input 2 : 3
                                 4 2 1
                Sample Output 2 : 7
*/




#include<iostream>
using namespace std;

int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += input[i];
  }
  return sum;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}















// Time Complexity : O(n)
// Space Complexity : O(n)
// where n is size of input array
// #include<iostream>
// using namespace std;

// int sum(int input[], int n) {
//   /* Don't write main().
//      Don't read input, it is passed as function argument.
//      Return output and don't print it.
//      Taking input and printing output is handled automatically.
//   */
//   int sum = 0;
//   for (int i = 0; i < n; i++) {
//     sum += input[i];
//   }
//   return sum;
// }

// int sum1 ( int input[], int n ) {
//     if ( n == 0 ) {
//         return 0;
//     }
//     return input[0] + sum1(input + 1, n - 1 );
// }


// int main() {

// }