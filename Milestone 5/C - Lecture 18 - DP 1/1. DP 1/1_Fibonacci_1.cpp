
// Recursive Approach

#include <iostream>
using namespace std;

int fibo( int n ) {
	if( n <= 1 ) {
		return n;
	}

	int a = fibo(n - 1);
	int b = fibo(n - 2);

	return a + b;
}

// Memorization Apporach : Top-down Approach
int fibo_helper( int n, int *ans ) {
	if ( n <= 1 ) {
		return n;
	}

	// Check if output/ans already exists
	if ( ans[n] != -1 ) {
		return ans[n];
	}

	// Calculate output
	int a = fibo_helper( n - 1, ans );
	int b = fibo_helper( n - 2, ans );

	// Save the output for future use
	ans[n] = a + b;
	
	// Return the final output
	return ans[n];
}

int fibo_2( int n ) {
	int *ans = new int[n+1];

	// initalize array to -1
	for ( int i = 0; i <= n; i++ ) {
		ans[i] = -1;
	}
	
	return fibo_helper( n, ans );
}

int main() {
	int n;
	cout << "Enter the number 'n' : ";
	cin >> n;
	cout << fibo_2(n) << endl;
}



/*

		#include <iostream>
		using namespace std;

		int fibo( int n ) {
			if( n <= 1 ) {
				return n;
			}

			int a = fibo(n - 1);
			int b = fibo(n - 2);

			return a + b;
		}

		int main() {
			int n;
			cout << "Enter the number 'n' : ";
			cin >> n;
			cout << fibo_2(n) << endl;
		}

		Before improving code, our time complexity is : O(2^n)

		Steps to reduce or improve the Time Complexity  of above code :
		
		ans[i] => ith fibobnacci number
		ans[n] => nth fibobnacci number


		Check if ans already exists or not
				-> if yes => Return
				-> if No => calculate 
						 => save for future use
						 => and then Return

		After improving code, our time complexity is : O(n)

*/



/*
		OUTPUT :


*/