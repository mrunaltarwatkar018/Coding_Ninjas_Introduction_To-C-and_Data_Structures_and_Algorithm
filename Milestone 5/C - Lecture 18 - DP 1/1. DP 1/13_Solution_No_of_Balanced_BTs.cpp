#include <iostream>
using namespace std;
#include <cmath>

/*
		Time Complexity : O(2^n)
*/
// h >= 0
int balancedBTs(int h) {
	if( h <= 1 ) {
		return 1;
	}

	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);

	//int ans = (x*x + 2*x*y) % mod;

	int temp1 = (int) ( ( ( long ) (x) * x ) % mod) ;
	int temp2 = (int) ( (2* ( long ) (x) * y ) % mod );
	int ans = ( temp1 + temp2 ) % mod;


	return ans;
}

int main() {
	int h;
	cout << "Enter the value of 'h' : ";
	cin >> h;
	cout << "Number of balanced BTs : " << balancedBTs(h) << endl;
}



/*
		output :
			Enter the value of 'h' : 1
			Number of balanced BTs : 1

*/