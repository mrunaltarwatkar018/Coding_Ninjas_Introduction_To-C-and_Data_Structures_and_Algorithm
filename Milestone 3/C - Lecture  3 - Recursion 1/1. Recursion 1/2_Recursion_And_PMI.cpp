// PMI = Principle of Mathemathical Induction
// It is used for to prove some facts 

#include<iostream>
using namespace std;

int factorial ( int n ) {
    if ( n == 0 ) {
        return 1;
    }

    int smallOutput = factorial ( n - 1 );
    int output = n * smallOutput;
    return output;
}

int main() {
    int n; 
    cout << "Enter the value of n : ";
    cin >> n;
    cout << factorial ( n ) << endl;
}
