/*
        Question  : Fibonacci Number

        Problem statement
            Create a function that determines whether a given number 
            N belongs to the Fibonacci sequence. If N is found in the 
            Fibonacci sequence, the function should return true; otherwise, 
            it should return false.

            Detailed explanation ( Input/output format, Notes, Images )
            Input Format :
            Integer N

            Output Format :
            true or false

            Constraints :
            0 <= n <= 10^4

            Sample Input 1 :
            5

            Sample Output 1 :
            true

            Explanation :
            Fibonacci sequence begins 0, 1, 1, 2, 3, 5, ... and so on. 
            Since 5 appears in the sequence.
            
            Sample Input 2 :
            14

            Sample Output 2 :
            false

*/

#include<iostream>
using namespace std;


bool checkMember(int n){

  /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Return output and don't print it.
   * Taking input and printing output is handled automatically.
  */

    int a = 0;
    int b = 1;
    int c;
    while (a < n)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return a == n;//This statement will return true if 'a' is equal to 'n', false otherwise.

}

int main(){

  int n; 
  cin >> n ;
  if(checkMember(n)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }

}