/*
        In general,
        Memorization is a Top - Down - Approach &
        DP is a Bottom - Up - Approach
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <climits>


// DP Approach
// optimized Code ( with the help of DP )
/*
        Time Complexity : O( m * n )
        Space Complexity : O( m * n ) because we are using the extra array to save our output for furthe used
*/
int minCostPath_DP( int **input, int m, int n ) {
    int **output = new int *[m];
    for( int i = 0; i < m; i++ ) {
        output[i] = new int[n];
    }

    // Fill the last cell i.e., destination
    output[m-1][n-1] = input[m-1][n-1];

    // Fill last row ( as/from Right to Left Manner )
    for( int j = n - 2; j >= 0; j-- ) {
		output[m-1][j] = output[m-1][j+1] + input[m-1][j]; 
	}  

    // Fill last Column ( as/from Bottom to Top Manner )
    for( int i = m - 2; i >= 0; i-- ) {
		output[i][n-1] = output[i+1][n-1] + input[i][n-1]; 
    }

    // Fill remaining cells
    for ( int i = m - 2; i >= 0; i-- ) {
        for ( int j = n - 2; j >= 0; j-- ) {
            output[i][j] = min( output[i][j+1], min( output[i+1][j+1], output[i+1][j] ) ) + input[i][j];
        }
    }

    return output[0][0];
}



// optimized Code ( with the help of Memorization )
/*
        Time Complexity : O( m * n )
        Space Complexity : O( m * n ) because we are using the extra array to save our output for furthe used
*/
int minCostPath_Mem( int **input, int m, int n, int i, int j, int **output ) {
    // Base Cases
    if( i == m - 1 && j == n - 1 ) {
        return input[i][j];
    }
    
    if( i >= m || j >= n ) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if( output[i][j] != -1 ) {
        return output[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, output);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
    int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
    // Small Calculation
    int ans = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    output[i][j] = ans;
    
    return ans;
}

int minCostPath_Mem(int **input, int m, int n, int i, int j) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
    
    return minCostPath_Mem(input, m, n, i, j, output);
}

int minCostPath(int **input, int m, int n, int i, int j) {
    // Base case
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Recursive calls
    int x = minCostPath(input, m, n, i, j+1);
    int y = minCostPath(input, m, n, i+1, j+1);
    int z = minCostPath(input, m, n, i+1, j);
    
    // Small Calculation
    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n) {
    return minCostPath(input, m, n, 0, 0);
}

int main() {
    int m, n;
    // number of rows and number of columns
    cout << "Taking row & column as a input from the user : ";
    cin >> m >> n;
    int **input = new int*[m];
    for(int i = 0; i < m; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }	
    }


    cout << "Minimum Path with the help of DP is : ";
    cout << minCostPath_DP( input, m, n ) << endl;
    cout << "Minimum Path with the help of Memorization is : ";
    cout << minCostPath_Mem( input, m, n, 0, 0 ) << endl;
    cout << "Minimum Path with Brute Force is : ";
    cout << minCostPath( input, m, n ) << endl;

}


// output

/*
        Taking row & column as a input from the user : 2 3
        3 4 5
        3 7 8
        Minimum Path with the help of DP is : 15
        Minimum Path with the help of Memorization is : 15
        Minimum Path with Brute Force is : 15
*/
















/*

#include <iostream>
using namespace std;
#include <climits>

int minCOst_DP(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
	}

	ans[m-1][n-1] = input[m-1][n-1];

	// Last row
	for(int j = n - 2; j >= 0; j--) {
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}

	// Last col
	for(int i = m-2; i >= 0; i--) {
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
	}

	for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));
		}
	}
	return ans[0][0];
}


int minCostPath_Better(int **input, int m, int n, int i, int j, int **ans) {
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	if(ans[i][j] != -1) {
		return ans[i][j];
	}

	int x = minCostPath_Better(input, m, n, i+1, j, ans);
	if(x < INT_MAX) {
		ans[i+1][j] = x;
	}
	int y = minCostPath_Better(input, m, n, i+1, j+1, ans);
	if(y < INT_MAX) {
		ans[i+1][j+1] = y;
	}
	int z = minCostPath_Better(input, m, n, i, j+1, ans);
	if(z < INT_MAX) {
		ans[i][j+1] = z;
	}

	ans[i][j] = min(x, min(y, z)) + input[i][j];
	return ans[i][j];
}



















int minCostPath_Better(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
		for(int j = 0; j < n; j++) {
			ans[i][j] = -1;
		}
	}
	return minCostPath_Better(input, m, n, 0, 0, ans);
}


int minCostPath(int **input, int m, int n, int i, int j) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1);
	int y = minCostPath(input, m, n, i+1, j+1);
	int z = minCostPath(input, m, n, i+1, j);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
	return ans;
}

int minCostPath(int **input, int m, int n) {
	return minCostPath(input, m, n, 0, 0);
}

int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}
	cout << minCOst_DP(input, m, n) << endl;
	cout << minCostPath_Better(input, m, n) << endl;
	cout << minCostPath(input, m, n) << endl;
}

*/