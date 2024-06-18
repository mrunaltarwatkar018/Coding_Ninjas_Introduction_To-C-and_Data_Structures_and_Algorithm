#include <iostream>
using namespace std;

// Approach Using DP
int editDistance_DP( string s, string t ) {
    int m = s.size();
    int n = t.size();
    int **output = new int *[m+1];

    for ( int i = 0; i <= m; i++ ) {
        output[i] = new int [n+1];
    }


    // Fill the 1st Row
    for ( int j = 0; j <= n; j++ ) {
        output[0][j] = j;
    }

    // Fill the 1st Column
    for ( int i = 1; i <= m; i++ ) {
        output[i][0] = i;
    }

    // fill remaining array
    for ( int i = 1; i <= m ; i++) {
        for ( int j = 1; j <= n; j++ ) {
            if ( s[m-i] == t[n-j] ) {
                output[i][j] = output[i-1][j-1];
            } else {
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];

                output[i][j] = min( a, min( b, c ) ) + 1;
            }
        }
    }
    return output[m][n];
}


// Approach Using Memorization
int editDistance_mem( string s, string t, int **output ) {
    int m = s.size();
    int n = t.size();

    // Base Case
    if ( s.size() == 0 || t.size() == 0 ) {
        return max( s.size(), t.size() );
    }


    // Check if ans already exists
    if ( output[m][n] != -1 ) {
        return output[m][n];
    }

    int ans;
	if( s[0] == t[0] ) {
		ans = editDistance_mem(s.substr(1), t.substr(1), output);
	}
	else {
		// Insert
		int x = editDistance_mem(s.substr(1), t, output) + 1;
		// Delete
		int y = editDistance_mem(s, t.substr(1), output) + 1;
		// Replace
		int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

		ans =  min(x, min(y, z));
	}

	// Save the ans
	output[m][n] = ans;

	// Return the ans
	return ans;

}

int editDistance_mem( string s, string t ) {
    int m = s.size();
    int n = t.size();

    int **ans = new int *[m+1];

    for ( int i = 0; i <= m; i++ ) {
        ans[i] = new int[n+1];

        for ( int j = 0; j <= n; j++ ) {
            ans[i][j] = -1;
        }

    }

    return editDistance_mem( s, t, ans );
}




// Recursive Calls or Burate Force Appraoch
/*
	Time complexity: O(3 ^ min(N, M))
	Space complexity: O(min(N, M))
	where N and M are the lengths of the two strings
*/

int editDistance( string s, string t ) {

    // Base Case
    if ( s.size() == 0 || t.size() == 0 ) {
        return max( s.size(), t.size() );
    }


    if ( s[0] == t[0] ) {
        return editDistance( s.substr(1), t.substr(1) );
    } else {
        // Insert
        int x = editDistance( s.substr(1), t ) + 1;
        // Delete
        int y = editDistance( s, t.substr(1) ) + 1;
        // Replace
        int z = editDistance( s.substr(1), t.substr(1) ) + 1;

        return min( x, min( y, z ) );
    }
}

int main() {
	string s = "abcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdf";
	string t = "afdiafdafdafdafd";
    
    // string s = "abcdf";
    // string t = "afd";

    cout << "Edit Distance with the help of MemorizationDP is : ";
    cout << editDistance_DP(s, t) << endl;
    cout << "Edit Distance with the help of Memorization is : ";
	cout << editDistance_mem( s, t ) << endl;
    cout << "First Approach Usung Recursive Calls : ";
	cout << editDistance( s, t ) << endl;
}



// output

/*
    Edit Distance with the help of MemorizationDP is : 40
    Edit Distance with the help of Memorization is : 40
    First Approach Usung Recursive Calls : 
*/