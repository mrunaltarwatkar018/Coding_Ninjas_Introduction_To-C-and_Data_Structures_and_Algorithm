#include <iostream>
using namespace std;

/* =================================================================================================================== */
/* 
    Question  : Sum of digits (recursive)
                Write a recursive function that returns the sum of the digits of a given integer.

                Do this recursively. Indexing in the array starts from 0.
        
                Input format : Integer N
                Output Format : Sum of digits of N
                Constraints :  0 <= N <= 10^9
                Sample Input 1 : 12345       
                Sample Output 1 : 15
                Sample Input 2 : 9  
                Sample Output 2 : 9

*/




int sumOfDigits(int n) {
    // Write your code here
    if (n == 0) {
      return 0;
    }
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}