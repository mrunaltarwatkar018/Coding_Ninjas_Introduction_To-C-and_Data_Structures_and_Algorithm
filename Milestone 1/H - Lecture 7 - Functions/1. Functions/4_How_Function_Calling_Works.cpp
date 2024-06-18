#include<iostream>
using namespace std;
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
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;
//     for (int x = 1; x <= n; x++ ) {
//         if (isPrime(x)) {
//             cout << x << endl;
//         }
//     }
// }


/* Call Stack Function */
void B() {
    cout << 5 << endl;
}

void A(int a) {
    cout << 1 << endl;
    B();
    cout << 2 << endl;
}

int main() {
    int n = 10;
    cout << 3 << endl;
    A(n);
    cout << n << endl;
    cout << 4 << endl;
}