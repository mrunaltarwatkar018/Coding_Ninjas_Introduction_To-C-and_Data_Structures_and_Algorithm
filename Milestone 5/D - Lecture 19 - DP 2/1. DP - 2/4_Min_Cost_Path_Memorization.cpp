/*
        In general,
        Memorization is a Top - Down - Approach &
        DP is a Bottom - Up - Approach
*/


#include <iostream>
using namespace std;
#include <climits>

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
    cout << "Minimum Path with the help of Memorization is : ";
    cout << minCostPath_Mem(input, m, n, 0, 0) << endl;
    cout << "Minimum Path with Brute Force Sis : ";
    cout << minCostPath(input, m, n) << endl;
}


// output

/*
        Taking row & column as a input from the user : 2 3
        3 6 9 
        1 2 6
        Minimum Path with the help of Memorization is : 11
        Minimum Path with Brute Force Sis : 11
*/