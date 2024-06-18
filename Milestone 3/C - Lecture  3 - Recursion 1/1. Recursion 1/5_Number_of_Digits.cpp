
/* 
    Question 3 : Number of Digits 
                Given the number 'n', find out and return the number of 
                digits present in a number recursively.
        
                Input format : Integer n
                Output Format : Count of digits
                Constraints :   1 <= n <= 10^6
                Sample Input 1 : 156
                Sample Output 1 : 3
                Sample Input 2 : 7 
                Sample Output 2 : 1
*/



#include<iostream>
using namespace std;
int count(int n){
    //write your code here
    static int ct = 0;

    if (n > 0) {
      ct++;
      count(n / 10);
    } else {
      return ct;
    }
}

int count ( int n ) {
    if ( n < 10 ) {
        return 1;
    }
    return 1 + count ( n / 10 );
}

int main() {
    int n; 
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "Number of Digits : " << count(n); 
}
