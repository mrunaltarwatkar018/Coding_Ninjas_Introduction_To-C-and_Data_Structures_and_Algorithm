// Recusive Approach


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
		Time Complexity : O(2^n) & O(3^n)
*/
int minSteps(int n) {
	// Base case
	if( n <= 1 ) {
		return 0;
	}

	// Recursive call
	int x = minSteps( n - 1 );

	int y = INT_MAX, z = INT_MAX;

	if( n % 2 == 0 ) {
		y = minSteps( n / 2 );
	}

	if( n % 3 == 0 ) {
		z = minSteps( n / 3 );
	}

	// Calculate final output
	int ans = min( x, min ( y, z ) ) + 1;

	return ans;

}

int main() {
	int n;
	cout <<"Enter The Number 'N' : ";
	cin >> n;

	cout << "Ans : " << minSteps(n) << endl;
}



/*
		OUTPUT :
					Enter The Number 'N' : 7
					Ans : 3
*/