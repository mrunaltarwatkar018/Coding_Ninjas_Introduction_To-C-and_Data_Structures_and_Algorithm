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
}


// output
/*
    Enter The String 'S' : abcd
    Enter The String 'T' : xyzw
    First Approach Usung Recursive Calls : 0
    LCS with the help of Memorization is : 
    

    Enter The String 'S' : abcd
    Enter The String 'T' : badce
    First Approach Usung Recursive Calls : 2
    LCS with the help of Memorization is : 2
*/