/* =================================================================================================================== */
/* 
    Question  : Ways To Make Coin Change
                
                        For the given infinite supply of coins of each of 
                        denominations, D = {D0, D1, D2, D3, ...... Dn-1}. 
                        You need to figure out the total number of ways W, 
                        in which you can make the change for Value V using 
                        coins of denominations D.
                        
                        Return 0 if the change isn't possible.
                
                Input format : 
                        The first line of the input contains an integer value N, 
                        which denotes the total number of denominations.

                        The second line of input contains N values, separated by 
                        a single space. These values denote the value of 
                        denomination.

                        The third line of the input contains an integer value, 
                        that denotes the value of V.

                Output Format : 
                       Print the total total number of ways i.e. W.

                Constraints :  
                        1 <= n <= 10
                        1 <= V <= 1000

                        Time Limit: 1 sec

                Sample Input 1 :    
                        3
                        1 2 3
                        4
                                          
                Sample Output 1 :   
                        4

                Explanation to Sample Input 1 : 
                        Number of ways are - 4 total i.e. (1,1,1,1), 
                        (1,1, 2), (1, 3) and (2, 2).

                Sample Input 2 :    
                        6
                        1 2 3 4 5 6
                        250
                                          
                Sample Output 2 :   
                        13868903

*/


#include <iostream>
using namespace std;

// First Approach
int countWaysToMakeChange(int arr[], int n, int value, int **temp) {
    if (n == 0)
        return 0;

    if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (temp[n][value] > 0)
        return temp[n][value];

    int ans1 = countWaysToMakeChange(arr + 1, n - 1, value, temp);
    int ans2 = countWaysToMakeChange(arr, n, value - arr[0], temp);
    temp[n][value] = ans1 + ans2;

    return ans1 + ans2;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value) {
    // Write your code here
    int **output = new int *[11];

    for (int i = 0; i < 11; i++) {
        output[i] = new int[1001];
        for (int j = 0; j < 1001; j++)
            output[i][j] = 0;
    }

    int ans = countWaysToMakeChange(denominations, numDenominations, value, output);

    for (int i = 0; i < 11; i++) {
        delete[] output[i];
    }

    delete[] output;
    
    return ans;
}


// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(N * M)
    Space complexity: O(N * M)

    where M is number of demoninations
    and N is the value to make change for
*/

int countWaysToMakeChange(int *denominations, int m, int n) {
    int i, j, x, y;

    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)

    int table[n + 1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i = 0; i < m; i++) {
        table[0][i] = 1;
    }

    // Fill rest of the table entries in bottom
    // up manner
    for (i = 1; i < n + 1; i++) {
        for (j = 0; j < m; j++) {
            // Count of solutions including denominations[j]
            x = (i - denominations[j] >= 0) ? table[i - denominations[j]][j] : 0;

            // Count of solutions excluding denominations[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

// Optimized Approach [ C++ ( g++ 5.4 ) ]
/*
    Time complexity: O(N * M)
    Space complexity: O(N * M)

    where M is number of demoninations
    and N is the value to make change for
*/

int countWaysToMakeChange(int *denominations, int m, int n) {
    int i, j, x, y;

    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)

    int table[n + 1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i = 0; i < m; i++) {
        table[0][i] = 1;
    }

    // Fill rest of the table entries in bottom
    // up manner
    for (i = 1; i < n + 1; i++) {
        for (j = 0; j < m; j++) {
            // Count of solutions including denominations[j]
            x = (i - denominations[j] >= 0) ? table[i - denominations[j]][j] : 0;

            // Count of solutions excluding denominations[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
            
            // total count
            table[i][j] = x + y;
        }
    }
    
    return table[n][m - 1];
}

int main() {

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}



