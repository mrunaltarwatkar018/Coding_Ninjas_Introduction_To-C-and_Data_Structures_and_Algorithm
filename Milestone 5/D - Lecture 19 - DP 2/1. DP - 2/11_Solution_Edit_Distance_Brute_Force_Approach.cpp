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
                       s = abc
                       t = dc
                                          
                Sample Output 1 :   
                        2

*/



#include <iostream>
using namespace std;

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
    string S;
    string T;

    cout << "Enter the string 'S' : ";
    cin >> S;
    cout << "Enter the string 'T' : ";
    cin >> T;

    cout << "First Approach Usung Recursive Calls : ";
    cout << editDistance( S, T );
}

// Output 

/*
    Enter the string 'S' : abcdf
    Enter the string 'T' : afd
    First Approach Usung Recursive Calls : 3
*/	




/*

    Example : 

    S = abc
    T = bcd


    for insert
    S = abc
    T = a bcd

    for delete
    S = abc
    T = cd


    for replace
    S = a b c
    T = a c d

*/