/* =================================================================================================================== */
/* 
    Question  : Matrix Chain Multiplication
                
                        Given a chain of matrices A1, A2, A3,.....An, you have to 
                        figure out the most efficient way to multiply these matrices. 
                        In other words, determine where to place parentheses to minimize 
                        the number of multiplications.
                        
                        You will be given an array p[] of size n + 1. Dimension of 
                        matrix Ai is p[i - 1]*p[i]. You need to find minimum number 
                        of multiplications needed to multiply the chain.
                
                Input format : 
                        The first line of input contains an integer, that denotes the 
                        value of n. The following line contains n+1 integers, that 
                        denote the value of elements of array p[].

                Output Format : 
                       The first and only line of output prints the minimum number 
                       of multiplication needed.

                Constraints :  
                        1 <= n <= 100

                        Time Limit: 1 sec

                Sample Input 1 :    
                        3
                        10 15 20 25
                                          
                Sample Output 1 :   
                        8000

                Explanation to Sample Input 1 : 
                        There are two ways to multiply the chain - 
                        A1*(A2*A3) or (A1*A2)*A3.
                        If we multiply in order- A1*(A2*A3), then number of 
                        multiplications required are 11250.
                        If we multiply in order- (A1*A2)*A3, then number of 
                        multiplications required are 8000.
                        Thus minimum number of multiplications required 
                        are 8000. 
*/




#include <iostream>
using namespace std;

// Fisrt Approach
#include <climits>
#include <vector>

int matrixChainMultiplication(vector<vector<int>> &dp, int *p, int s, int e) {
        if ((e - s) == 1)
                return 0;
                
        if (dp[s][e])
                return dp[s][e];
                
        int ans = INT_MAX;
        
        for (int k = s + 1; k < e; k++) {
                int temp = matrixChainMultiplication(dp, p, s, k) + matrixChainMultiplication(dp, p, k,
                        e) + p[s] * p[k] * p[e];
                ans = min(ans, temp);
        }
        
        dp[s][e] = ans;
        
        return ans;
        }

        int matrixChainMultiplication(int *arr, int n) {
        // Write your code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        int ans = matrixChainMultiplication(dp, arr, 0, n);
        
        return ans;
}

// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(N^3)
    Space complexity: O(N^2)
    
    where N is the number of matrices to multiply
*/

#include <vector>
#include <climits>

int matrixChainMultiplication(int* arr, int n) {
        /*
                For simplicity of the program, one extra row and one
                extra column are allocated in dp[][]. 0th row and 0th
                column of dp[][] are not used
        */
        
        n += 1;
        /*
                dp[i,j] = Minimum number of scalar multiplications needed
                to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
                dimension of A[i] is arr[i-1] x arr[i]
        */
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        // Cost is zero when multiplying one matrix.
        for (int i = 1; i < n; i++) {
                dp[i][i] = 0;
        }
        
        // L is chain length.
        for (int L = 2; L < n; L++) {
                for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++) {
                        int q = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                        if (q < dp[i][j]) dp[i][j] = q;
                }
                }
        }
        
        return dp[1][n - 1];
}


// Optimized Approach [ C++ ( g++ 5.4 ) ]
/*
        Time complexity: O(N^3)
        Space complexity: O(N^2)

        where N is the number of matrices to multiply
*/
#include <vector>
#include <climits>

int matrixChainMultiplication(int* arr, int n) {
        /*
                For simplicity of the program, one extra row and one
                extra column are allocated in dp[][]. 0th row and 0th
                column of dp[][] are not used
        */

        n += 1;

        /*
                dp[i,j] = Minimum number of scalar multiplications needed
                to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
                dimension of A[i] is arr[i-1] x arr[i]
        */
        vector<vector<int>> dp(n, vector<int>(n));

        // Cost is zero when multiplying one matrix.

        for (int i = 1; i < n; i++) {
                dp[i][i] = 0;
        }

        // L is chain length.
        for (int L = 2; L < n; L++) {
                for (int i = 1; i < n - L + 1; i++) {
                        int j = i + L - 1;
                        dp[i][j] = INT_MAX;
                        for (int k = i; k <= j - 1; k++) {
                                int q = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                                if (q < dp[i][j]) dp[i][j] = q;
                        }
                }
        }

        return dp[1][n - 1];
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n+1];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}



