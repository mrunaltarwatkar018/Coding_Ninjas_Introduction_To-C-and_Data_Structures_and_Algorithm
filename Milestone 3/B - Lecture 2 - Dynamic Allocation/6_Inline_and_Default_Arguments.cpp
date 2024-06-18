#include<iostream>
using namespace std;

// Inline functions are used to reduce 
// the function call overhead. Inline function is a 
// function that is expanded in line when it is called.

// inline int max( int a, int b ) {
//     return ( a > b ) ? a : b;
// }

// int main() {
//     int a, b;
//     cin >> a >> b;

//     int c = max(a, b);
//     int x, y;
//     x = 12;
//     y = 34;

//     int z = max(x, y);
// }



// int main() {
//     int a, b;
//     cin >> a >> b;

//     // for finding maximum number
//     // int c;
//     // if ( a > b ) {
//     //     c = a;
//     // } else {
//     //     c = b;
//     // }

//     int c = ( a > b ) ? a : b;
// }


/* ========================= DEfault Value Of Arguments================================== */

// Finding the sum of elements which start from Start_index to till N number of aarays

int sum ( int a[], int size, int start_index = 0 ) {
    int ans = 0;
    for ( int i = start_index; i < size; i++ ) {
        ans += a[i];
    }
    return ans;
}

int sum2 ( int a, int b = 0, int c = 0, int d = 0 ) {
    return a + b + c + d;
}

int main() {
    // input code taking the aaray elements
    // Take array input from the user
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int a[20];

    cout << "Taking input from the user : ";
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << sum ( a, 20);
    
    cout << sum2 (4, 6);
}