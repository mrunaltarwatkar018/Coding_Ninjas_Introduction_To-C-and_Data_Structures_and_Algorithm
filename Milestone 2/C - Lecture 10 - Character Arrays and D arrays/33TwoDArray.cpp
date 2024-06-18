#include<iostream>
using namespace std;

int main() {
    int a[100][100];
    int m, n;
    cout << "Enter the number of Rows & Columns : ";
    cin >> m >> n;

    cout << "Enter the Array Elements : ";
    // Taking input from the user
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            cin >> a[i][j];
        }
    }

    cout << "The array is : " << endl;
    // print the aaray

    cout << "Row wise : " << endl;
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    cout << "Column wise : " << endl;
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            cout << " " << a[j][i];
        }
        cout << endl;
    }
}


/*
    Output : 
            Enter the number of Rows & Columns : 3 3
            Enter the Array Elements : 1 2 3 4 5 6 7 8 9
            The array is : 
            Row wise : 
             1 2 3
             4 5 6
             7 8 9
            Column wise : 
             1 4 7
             2 5 8
             3 6 9
*/