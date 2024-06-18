
/* 
    Question 2 : Print Numbers 
                Given the number 'n', write a code to print numbers from 1 
                to n in increasing order recursively.
        
                Input format : Integer n
                Output Format : Numbers from 1 to n (separated by space)
                Constraints :   1 <= n <= 10000
                Sample Input 1 : 6
                Sample Output 1 : 1 2 3 4 5 6
                Sample Input 2 : 4 
                Sample Output 2 : 1 2 3 4
*/
#include<iostream>
using namespace std;

void print(int n){
    //write your code here
    if ( n == 1 ) {
        cout << n << " ";
    } else {
        print( n - 1 );
        cout << n << " ";
    }
}


int main() {
    int n; 
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "Print Numbers : ";
    print(n); 
}



