#include <iostream>
using namespace std;

int knapsack( int *weight, int *values, int n, int maxWeight ) {
    // Base Case

    if ( n == 0 || maxWeight == 0 ) {
        return 0;
    }

    if ( weight[0] > maxWeight ) {
        return knapsack( weight + 1, values + 1, n - 1, maxWeight );
    }

    // Recursive Calls
    int x = knapsack( weight + 1, values + 1, n - 1, maxWeight - weight[0] ) + values[0];

    int y = knapsack( weight + 1, values + 1, n - 1, maxWeight );

    return max( x, y );
}


int main() {
	int n;
	int weights[] = {5, 1, 8, 9, 2};
	int values[] = {4, 10, 2, 3, 1};
	int W = 15;

    cout << "Knapsack : ";
	cout << knapsack(weights, values, 5, W) << endl;
}


// Output :

/*

    Knapsack : 17

*/


/*

    Given :

           0  1  2  3  4  
    W  ->  5  1  8  9  2
    V  ->  4 10  2  3  1
    MW ->  15



    Explanation :


                            |       Weight(W)              Values(V)
                            |
                0  1  2     |  5 + 1 + 8 = 14           4 + 10 + 2 = 16
                1  2  4     |  1 + 8 + 2 = 11           10 + 2 + 1 = 13
                0  1  3     |  5 + 1 + 9 = 15           4 + 10 + 3 = 17




*/