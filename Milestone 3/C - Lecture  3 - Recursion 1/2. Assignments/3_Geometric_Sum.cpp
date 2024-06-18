#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/* =================================================================================================================== */
/* 
    Question  : Geometric Sum
                Given k, find the geometric sum i.e.
                1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
                using recursion.

                Do this recursively. Indexing in the array starts from 0.
        
                Input format : Integer k
                Output Format : Geometric sum (upto 5 decimal places)
                Constraints :  0 <= k <= 1000
                Sample Input 1 : 3         
                Sample Output 1 : 1.87500
                Sample Input 2 : 4      
                Sample Output 2 : 1.93750

                Explanation for Sample Output 1 :
                    1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500
*/

double geometricSum(int k) {
    // Write your code here
    if ( k == 0 ) {
        return 1;
    }
    return ( 1 / pow(2, k)) + geometricSum( k - 1 );
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}