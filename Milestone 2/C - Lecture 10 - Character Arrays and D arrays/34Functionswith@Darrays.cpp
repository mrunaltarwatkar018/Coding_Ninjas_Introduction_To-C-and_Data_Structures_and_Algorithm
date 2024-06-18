#include<iostream>
using namespace std;

// void printArray( int a[100][100], int m, int n ) {
//     for ( int i = 0; i < m; i++ ) {
//         for ( int j = 0; j < n; j++ ) {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }  
// }

void printArray( int a[][5], int m, int n ) {
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }  
}

int main() {

    int a[5][5] = {{1, 2}, {3, 4}};
    // int a[100][100];
    // int m, n;
    // cout << "Enter the number of Rows & Columns : ";
    // cin >> m >> n;

    // cout << "Enter the Array Elements : ";
    // // Taking input from the user
    // for ( int i = 0; i < m; i++ ) {
    //     for ( int j = 0; j < n; j++ ) {
    //         cin >> a[i][j];
    //     }
    // }

    cout << "Array Becomes : " << endl;
    printArray(a, 5, 5);
}