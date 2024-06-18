/*
    LCS : Longest Common Sub-Sequences
*/


/*
    Problem : List down the Longest Possible Common Sub-Sequences length.


    Sub-Sequences :

            Sub-Sequences are the part of the string but the order
            of characters shold be maintained and they need not to be 
            continuous.
*/


/*
                Sample Input 1 :    
                        S -> a b c d
                        T -> b a d e a b
                    
                    Explanation : a d, a b,
                                Total number of characters present in LCS : 2
                                          
                Sample Output 1 :   
                        2

                Sample Input 2 :    
                        S -> a b c d e
                        T -> c a d b e

                    Explanation : c d e, a b e, a d e
                                Total number of characters present in LCS : 3
                                          
                Sample Output 2 :   
                        3

                Sample Input 3 :    
                        S -> x y z
                        T -> z x y

                    Explanation : z, x y
                                Total number of characters present in LCS : 2
                                          
                Sample Output 3 :   
                        2

                Sample Input 4 :    
                        S -> x y z
                        T -> z x a y

                    Explanation : z, x y
                                Total number of characters present in LCS : 2
                                          
                Sample Output 4 :   
                        2
*/


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

int main() {
	string s, t;
    cout << "Enter The String 'S' : ";
	cin >> s;
    cout << "Enter The String 'T' : ";
	cin >> t;

    cout << "First Approach Usung Recursive Calls : ";
	cout << lcs(s, t) << endl;
}


// Output

/*
    Enter The String 'S' : xyz
    Enter The String 'T' : zxay
    First Approach Usung Recursive Calls : 2
*/