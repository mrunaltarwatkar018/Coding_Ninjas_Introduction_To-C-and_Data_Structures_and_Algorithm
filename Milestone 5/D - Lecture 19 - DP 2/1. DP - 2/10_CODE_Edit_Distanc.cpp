/* =================================================================================================================== */
/* 
    Question  : Code : Edit Distance
                
                Given two strings s and t of lengths m and n respectively, 
                find the edit distance between the strings.

                Edit Distance

                Edit Distance of two strings is minimum number of 
                operations required to make one string equal to other. 
                In order to do so you can perform any of the following 
                three operations only :

                    1. Delete a character
                    2. Replace a character with another one
                    3. Insert a character

                Note
                    Strings don't contain spaces
                    You need to find the edit distance from input string1 
                    to input string2.

                Input format : 
                        The first line of input contains a string, that denotes 
                        the value of s. The following line contains a string, 
                        that denotes the value of t.

                Output Format : 
                        The first and only line of output contains the edit 
                        distance value between the given strings.

                Constraints :  
                        1<= m,n <= 10
                        Time Limit: 1 sec

                Sample Input 1 :    
                        abc
                        dc
                                          
                Sample Output 1 :   
                        2

*/




#include <cstring>
#include <iostream>
using namespace std;

// my Approach
int editDistance(string s1, string s2) {
	// Write your code here
	if ( s1.size() == 0 || s2.size() == 0 ) {
		return max( s1.size(), s2.size() );
	}

	if ( s1[0] == s2[0] ) {
		return editDistance( s1.substr(1), s2.substr(1) );
	} else {
		int x = 1 + editDistance( s1.substr(1), s2 );
		int y = 1 + editDistance( s1, s2.substr(1) );
		int z = 1 + editDistance( s1.substr(1), s2.substr(1) );
		return min( x, min( y, z ) );
	}
}



// Optimized Approach
/*
	Time complexity: O(3 ^ min(N, M))
	Space complexity: O(min(N, M))
	where N and M are the lengths of the two strings
*/

int editDistance(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();

	if (n == 0 || m == 0) {
		return max(n, m);
	}

	if (s1[0] == s2[0]) {
		return editDistance(s1.substr(1), s2.substr(1));
	}

	int deleteCost = editDistance(s1.substr(1), s2);
	int insertCost = editDistance(s1, s2.substr(1));
	int replaceCost = editDistance(s1.substr(1), s2.substr(1));
	
	return 1 + min(deleteCost, min(insertCost, replaceCost));
}


int main() {
    string s1;
    string s2;

    cout << "Enter the string 'S1' : ";
    cin >> s1;
    cout << "Enter the string 'S2' : ";
    cin >> s2;

    cout << "First Approach Usung Recursive Calls : ";
    cout << editDistance(s1, s2);
}