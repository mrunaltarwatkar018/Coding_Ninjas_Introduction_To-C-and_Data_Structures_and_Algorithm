/* =================================================================================================================== */
/* 
    Question  : Code: Knapsack (Memoization and DP)
                
                A thief is robbing a store and can carry a maximal weight 
                of W into his knapsack. There are N items and ith item 
                weighs wi and is of value vi. Considering the constraints 
                of maximum weight that knapsack can carry, you have to 
                find and return the maximum value that thief can generate 
                by stealing items.

                Note :
                        Space complexity should be O(W).

                Input format : 
                        The first line contains an integers, that denote the 
                        value of N. The following line contains N space 
                        separated integers, that denote the values of weight 
                        of items. The following line contains N space separated 
                        integers, that denote the values associated with the items. 
                        The following line contains an integer that denote the 
                        value of W. W denotes maximum weight that thief can carry.

                Output Format : 
                        The first and only line of output contains the 
                        maximum value that thief can generate, as described 
                        in the task. 

                Constraints :  
                        1 <= N <= 10^4
                        1<= wi <= 100
                        1 <= vi <= 100

                        Time Limit: 1 sec

                Sample Input 1 :    
                        4
                        1 2 4 5
                        5 4 8 6
                        5
                                          
                Sample Output 1 :   
                        13   

*/


#include <cstring>
#include <iostream>
using namespace std;

// First Approach

int knapsack(int *weights, int *values, int n, int maxWeight) {
    // Write your code here
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        output[i] = new int[maxWeight + 1];

    for (int i = 0; i <= n; i++)
        output[i][0] = 0;

    for (int i = 0; i <= maxWeight; i++)
        output[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            if (j < weights[n - i])
                output[i][j] = output[i - 1][j];
            else
                output[i][j] = max(output[i - 1][j - weights[n - i]] + values[n - i], output[i - 1][j]);
        }
    }
    return output[n][maxWeight];
}


// Optimized Approach [ C++ ( g++ 11 ) ]

/*
        Time complexity: O(N * W)
        Space complexity: O(W)

        where N is the number of items
        and W is the maximum weight that the theif can carry
*/
#include <vector>
int knapsack( int* weight, int* value, int n, int maxWeight ) {
        vector<vector<int>> dp( 2, vector<int>( maxWeight + 1, 0 ) );
        for ( int i = 0; i < n; i++ ) {
                for ( int j = 1; j <= maxWeight; ++j ) {
                        if ( weight[i] <= j ) {
                                dp[i % 2][j] = max(value[i] + dp[ ( 1 + i ) % 2 ] [ j - weight[i] ], dp[ ( i + 1 ) % 2 ] [j] );
                        } else {
                                dp[i % 2][j] = dp[(i + 1) % 2][j];
                        }
                }
        }
        return dp[ ( n + 1 ) % 2 ][maxWeight];
}






// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
        Time complexity: O(N * W)
        Space complexity: O(W)

        where N is the number of items
        and W is the maximum weight that the theif can carry
*/

#include <vector>
int knapsack(int* weight, int* value, int n, int maxWeight) {
        vector<vector<int>> dp(2, vector<int>(maxWeight + 1, 0));
        for (int i = 0; i < n; i++) {
                for (int j = 1; j <= maxWeight; ++j) {
                        if (weight[i] <= j) {
                                dp[i % 2][j] = max(value[i] + dp[(1 + i) % 2][j - weight[i]], dp[(i + 1) % 2][j]);
                        } else {
                                dp[i % 2][j] = dp[(i + 1) % 2][j];
                        }
                }
        }
        return dp[(n + 1) % 2][maxWeight];
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}