#include <iostream>
using namespace std;

// First Approach Usung Recursive Calls
/*
    Time Complexity in Wrost case : exponential i.e. 2^n
*/

int lcs( string s, string t ) {
    // Base case

    if ( s.size() == 0 || t.size() == 0 ) {
        return 0;
    }

    // Recursive calls

    if ( s[0] == t[0] ) {
        return 1 + lcs( s.substr(1), t.substr(1) );
    } else {
        int a = lcs( s.substr(1), t );
        int b = lcs( s, t.substr(1) );
        int c = lcs( s.substr(1), t.substr(1) );

        return max( a, max( b, c ) );
    }

}

// Second Approach Usung Memorization
// optimized Code ( with the help of Memorization )
/*
        Time Complexity : O( m * n )
        Space Complexity : O( m * n ) because we are using the extra 2D array (to save our output for furthe used) apart from the given input
*/
int lcs_mem( string s, string t, int **output ) {
	int m = s.size();
	int n = t.size();
	
	// Base case
	if( s.size() == 0 || t.size() == 0 ) {
		return 0;
	}

	// Check if ans already exists
	if( output[m][n] != -1 ) {
		return output[m][n];
	}

	int ans;
	// Recursive calls
	if( s[0] == t[0])  {
		ans = 1 + lcs_mem( s.substr(1), t.substr(1), output );
	}
	else {
		int a = lcs_mem(s.substr(1), t, output);
		int b = lcs_mem(s, t.substr(1), output);
		int c = lcs_mem(s.substr(1), t.substr(1), output);
		ans = max(a, max(b, c));
	}

	// Save your calculation
	output[m][n] = ans;

	// Return ans
	return ans;
}

int lcs_mem( string s, string t  ) {
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];

    for( int i = 0; i <= m; i++ ) {
        output[i] = new int[n+1];
        for( int j = 0; j <= n; j++ ) {
            output[i][j] = -1;
        }
    }
    return lcs_mem( s, t, output );
}


// DP Approach
// optimized Code ( with the help of DP )
/*
        Time Complexity : O( m * n )
        Space Complexity : O( m * n ) because we are using the extra 2D array (to save our output for furthe used) apart from the given input
*/
int lcs_DP( string s, string t ) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];

	for( int i = 0; i <= m; i++ ) {
		output[i] = new int[n+1];
	}

	// Fill 1st row ( means Row number 0 is fixed but Column varied )
	for( int j = 0; j <= n; j++ ) {
		output[0][j] = 0;
	}

	// Fill 1st col ( means Column number 0 is fixed but Row varied )
	for( int i = 1; i <= m; i++ ) {
		output[i][0] = 0;
	}

	for( int i = 1; i <= m; i++ ) {

		for( int j = 1; j <= n; j++ ) {

			// Check if 1st char matches
			if( s[m-i] == t[n-j] ) {
				output[i][j] = 1 + output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b, c));
			}

		}

	}

	return output[m][n];
}

int main() {
	string s, t;
    cout << "Enter The String 'S' : ";
	cin >> s;
    cout << "Enter The String 'T' : ";
	cin >> t;

    cout << "First Approach Usung Recursive Calls : ";
	cout << lcs(s, t) << endl;

    cout << "LCS with the help of Memorization is : ";
    cout << lcs_mem( s, t ) << endl;

    cout << "LCS with the help of DP is : ";
    cout << lcs_DP(s, t) << endl;

}




/*
    For Dp Approach:


    Step 1 : Create an output array of required Dimmensions
    Step 2 : Fill 1st Row and 1st Column with Zero ( 0 ) values
    Step 3 : Check Dependencies of the shell, if clear then fill thaat cell
    Step 4 : Finally, Fill the Matrix from Left to Right ROW by ROW
    Step 5 : amd at last return the answer of the given input

*/


/*
    In DP Approach,
    we don't need to initalize of an output array in case of DP, 
    bacause

    Quki DP ke Time pe Hum aapne cells ki values ko ussi order main
    used krte hai jiss order main fill krte hai.
    Hum kabhi bhi yese cell ki value use hi nahi karenge jaha garbage padha 
    ho, toh hame initialize krne ki jarurat hi nhi hai.


*/



// output
/*
    Enter The String 'S' : abcdef
    Enter The String 'T' : befadscv
    First Approach Usung Recursive Calls : 3
    LCS with the help of Memorization is : 3
    LCS with the help of DP is : 3

*/