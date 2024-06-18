#include <iostream>
using namespace std; 
int main() {
    // int n;
    // cout << "Enter the value of n : ";
    // cin >> n;
    // int d = 2;
    // bool divided = false;
    // while (d < n) {
    //     if (n%d == 0) {
    //         divided = true;
    //         break;
    //     }
    //     d++;
    // }
    // if ( divided) {
    //     cout << "Not Prime" << endl;
    // } else {
    //     cout << "Prime" << endl;
    // }

    // int n;
    // cin >> n;

    // int i = 1;
    // while ( i < n ) {
    //     int j = 1;
    //     while ( j < n ) {
    //         cout << j;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /* Output : 5
                1234
                1234
                1234
                1234
                
    */

    // int n;
    // cin >> n;

    // int i = 1;
    // while ( i < n ) {
    //     int j = 1;
    //     while ( j < n ) {
    //         cout << j;
    //         j++;
    //         if ( j > i ) {
    //             break;
    //         }
    //     }
    //     cout << endl;
    //     i++;
    // }

    /* Output : 5
                1
                12
                123
                1234
                
    */

    // int n;
    // cin >> n;

    // bool divided = false;
    // for ( int d = 2; d < n; d++ ) {
    //     if ( n % d == 0 ) {
    //         divided = true;
    //         break;
    //     }
    // }
    // if ( divided ) {
    //     cout << "Not Prime" << endl;
    // } else {
    //     cout << "Prime" << endl;
    // }

    // int i = 1;
    // while ( i < 10 ) {
    //     cout << i << endl;   // output : 1 2 3 4
    //     if ( i == 4 ) {
    //         break;
    //     }
    //     i++;
    // } 

    int i = 1;
    while ( i < 10 ) {
        if ( i == 7 ) {
            i++;
            continue;
        }
        cout << i << endl;   // output : 1 2 3 4 5 6 8 9
        i++;
    } 


    for ( int j = 1; j < 10; j++ ) {
        if ( j == 7 ) {
            continue;
        }
        cout << j << endl;          // output : 1 2 3 4 5 6 8 9
    }
}