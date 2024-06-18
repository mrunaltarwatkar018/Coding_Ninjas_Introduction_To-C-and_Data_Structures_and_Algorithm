/* =================================================================================================================== */
/* 
    Question  : Code : Alpha Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 5
                                ..*
                                .***
                                *****
                                .***
                                ..*
                    The dots represent spaces.


                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 49

                Sample Input 1 :    
                                    5
                                          
                Sample Output 1 :   
                                      *
                                     ***
                                    *****
                                     ***
                                      *

                Sample Input 2 :    
                                    3
                                          
                Sample Output 2 :   
                                         *
                                        ***
                                         *
*/





// First Method
// #include <iostream>
// using namespace std;

// int main() {


//     int n;
//     cin >> n;

//     // int i = 1;

//     int n1 = n / 2 + 1;
//     int n2 = n / 2;

//     // while ( i <= n ) {
//     //     int spaces = 1;
//     //     while ( spaces <= n - i ) {
//     //         cout << ' ';
//     //         spaces++;
//     //     }

//     //     int j = 1;
//     //     while ( j <= i ) {
//     //         cout << '*';
//     //         j++;
//     //     }

//     //     j = i - 1;
//     //     while ( j >= 1 ) {
//     //         cout << '*';
//     //         j--;
//     //     }

//     //     cout << endl;
//     //     i++;
//     // }

//     // loop 1 from 1 to n1;
//     for (int i = 1; i <= n1; i++) {
//         // there will be 2 loops here one for printing space and other for *
//         // loop 1 from 1 = n1 -i
//         for (int j = 1; j <= n1 - i; j++) {
//             cout << " ";
//         }

//         // loop 2 from 1 to 2*i -1
//         for (int j = 1; j <= 2 * i - 1; j++) {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     // loop 2 from n2 to 0;
//     // copy above loop
//     // and run i from n2 to 1 and do i--
//     for (int i = n2; i >= 1; i--) {
//         // there will be 2 loops here one for printing space and other for *
//         // loop 1 from 1 = n1 -i
//         for (int j = 1; j <= n1 - i; j++) {
//         cout << " ";
//         }

//         // loop 2 from 1 to 2*i -1
//         for (int j = 1; j <= 2 * i - 1; j++) {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }








// Second Method
#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int currRow = 1;
    while(currRow <= (n/2) + 1) {
        int spaces = 1;
        while(spaces <= (n/2) + 1 - currRow) {
            cout << " ";
            spaces = spaces + 1;
        }
        int currCol = 1;
        while(currCol <= (2 * currRow) - 1) {
            cout << "*";
            currCol = currCol+1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
    currRow = 1;
    while(currRow <= n / 2){
        int spaces = 1;
        while(spaces <= currRow) {
            cout << " ";
            spaces = spaces + 1;
        }
        int currCol = 2 * ((n/2) - currRow + 1) - 1;
        while(currCol >= 1) {
            cout << "*";
            currCol = currCol - 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}