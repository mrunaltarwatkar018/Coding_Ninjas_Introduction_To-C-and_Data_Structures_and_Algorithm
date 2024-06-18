// factorial till N

#include<iostream>
using namespace std;

int factorial ( int n ) {
    cout << "Value of N is : " << n << endl;
    if ( n == 0 ) {
        return 1;
    }
    int smallOutput = factorial(n - 1);
    return n * smallOutput;
}

int main() {
    int n;
    cout << "Enter the value of N : ";
    cin >> n;
    int output = factorial(n);
    cout << "Output : " << output << endl;
}