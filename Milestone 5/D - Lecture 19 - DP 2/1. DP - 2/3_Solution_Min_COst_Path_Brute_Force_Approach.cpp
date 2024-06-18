#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

                            starting Point   --->    ending point
        for cell number 1 :     0, 1         --->    m - 1, n - 1
        for cell number 2 :     1, 1         --->    m - 1, n - 1
        for cell number 3 :     1, 0         --->    m - 1, n - 1

*/


//        Time Complexity of above Code is : O(3^n)
int minCostPath( int **input, int m, int n, int i, int j ) {
	// Base case
	if( i == m - 1 && j == n - 1) {
		return input[i][j];
	}

	if( i >= m || j >= n ) {
		return INT_MAX;
	}

	// Recursive calls
	int x = minCostPath( input, m, n, i, j + 1 );
	int y = minCostPath( input, m, n, i + 1, j + 1 );
	int z = minCostPath( input, m, n, i + 1, j );

	// Small Calculation
	int ans = min( x, min( y, z ) ) + input[i][j];
	return ans;
}

int minCostPath( int **input, int m, int n ) {
	return minCostPath( input, m, n, 0, 0 );
}

int main() {
	int m, n;
    // number of rows and number of columns
    cout << "Taking row & column as a input from the user : ";
	cin >> m >> n;

	int **input = new int*[m];
	for( int i = 0; i < m; i++ ) {

		input[i] = new int[n];

		for( int j = 0; j < n; j++ ) {
			cin >> input[i][j];
		}	
	}


    cout << "Minimum Path is : ";
	cout << minCostPath( input, m, n ) << endl;

}


/* 
Inputs

        3 3
        8 10 3
        2 0 4
        1 6 5

*/

// Output

/*
        Taking row & column as a input from the user : 3 3
                8 10 3
                2 0 4
                1 6 5
        Minimum Path is : 13
*/


/*
        Time Complexity of above Code is : 
*/