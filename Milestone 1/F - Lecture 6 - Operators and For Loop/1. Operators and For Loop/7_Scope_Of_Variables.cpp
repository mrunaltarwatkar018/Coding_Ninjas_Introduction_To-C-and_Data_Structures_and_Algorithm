#include<iostream>
using namespace std;

// int main() {

//     int k = 1;
//     while ( k < 100 ) {
//         int k2 = 1002;
//         cout << k2 << endl;
//         k++;
//     }
//     //cout << k2 << endl;  // out of scope because k2 is not avaliable or declared here
// }
    
//     int i = 10;
//     cout << i << endl;
//     if ( i == 10 ) {
//         int j = 12;
//         cout << j << endl;           // in scope
//     } else {
//         int j = 122;
//         cout << j << endl;
//     }
//     // cout << j << endl;  // out of scope because j is not avaliable or declared here
// }

// int main() {
//     int i = 1;
//     while ( i < 10 )
//     {
//         int j = 1;
//         while ( j < i ) {
//             int k = 10;
//             cout << j;
//             j++;
//         }
//         //cout << k << endl;  //'k' was not declared in this scope
//         cout << endl;
//         i++;
//     }
    
// }

int  main() {
    int i = 10;
    // not allowed int i = 22;
    cout << i << endl;

    if ( i == 10 ) {
        int i = 23;
        cout << i << endl;
    }

    cout << i << endl;


    int k = 22;
    for ( int k = 0; k < 10; k++ ) {
        cout << k << endl;
    }

     cout << k << endl;  //'k' was not declared in this scope
}