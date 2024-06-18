#include<iostream>
using namespace std;

/* Factorial */
// int main() {
//     int n,r;
//     cout << "Enter the value of n & r : ";
//     cin >> n >> r;
//     int fact_n = 1;
//     int i = 1;
//     while ( i <= n ) {
//         fact_n = fact_n * i;
//         i++;
//     }

//     int fact_r = 1;
//     i = 1;
//     while ( i <= r ) {
//         fact_r = fact_r * i;
//         i++;
//     }

//     int fact_n_r = 1;
//     i = 1;
//     while ( i <= n - r ) {
//         fact_n_r = fact_n_r * i;
//         i++;
//     }
//     cout << fact_n / ( fact_r * fact_n_r ) << endl;
// }

/* Output_datatype Function_name ( input ) */

// int factorial ( int n ) {
//     int ans = 1;
//     int i = 1;
//     while ( i <= n ) {
//         ans = ans * i;
//         i++;
//     }
//     return ans;
// }

// int main() {
//     int n, r;
//     cout << "Enter the value of n & r : ";
//     cin >> n >> r;

//     // int output = factorial ( 5 );
//     // cout << output << endl;
//     // cout << factorial ( 5 ) << endl;
//     int fact_n = factorial(n);
//     int fact_r = factorial(r);
//     int fact_n_r = factorial( n - r );
//     int ans = fact_n / ( fact_r * fact_n_r );
//     cout << ans << endl;
// }

/* Prime Number */
// bool isPrime ( int n ) {
//     int d = 2;
//     while ( d < n ) {
//         if ( n % d == 0 ) {
//             return false;
//         }
//         d++;
//     }
//     return true;    
// }

// int main() {
//     bool ans = isPrime(31);
//     cout << ans << endl;
//     ans = isPrime(85);
//     cout << ans << endl;
// }

/* Print 1 to N numbers in a function */
// void print_1_to_n( int n ) {
//     for ( int i = 1; i <= n; i++ ) {
//         cout << i << endl;
//     }
// }

// int main() {
//     print_1_to_n(10);
// }

/* Multiply To Numbers By using function */
int multiply ( int a, int b ) {
    return a * b;
}

int main() {
    int A, B;
    cout << "Enter the value of A & B : ";
    cin >> A >> B;
    int ans =multiply(A, B);
    cout << ans << endl;
}