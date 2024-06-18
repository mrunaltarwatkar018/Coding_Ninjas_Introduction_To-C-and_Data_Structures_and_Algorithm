/* =================================================================================================================== */
/* 
    Question  : Code : Alpha Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 5
                                E
                                DE
                                CDE
                                BCDE
                                ABCDE

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 26

                Sample Input 1 :    
                                    8
                                          
                Sample Output 1 :   
                                    H
                                    GH
                                    FGH
                                    EFGH
                                    DEFGH
                                    CDEFGH
                                    BCDEFGH
                                    ABCDEFGH

                Sample Input 2 :    
                                    7
                                          
                Sample Output 2 :   
                                    G
                                    FG
                                    EFG
                                    DEFG
                                    CDEFG
                                    BCDEFG
                                    ABCDEFG
*/





// First Method
// #include <iostream>
// using namespace std;

// int main() {

//     int n;
//     cin >> n;

//     int i = 1;
//     while (i <= n) {
//         int j = 1;
//         char c = 'A' + n - i;
//         while (j <= i) {
//         cout << c;
//         j++;
//         c++;
//         }
//         cout << endl;
//         i++;
//     }
// }







// Second Method
#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int currRow = 1;
    while(currRow <= n) {
        int currCol = 1;
        char ch = 'A' + n - currRow;
        while(currCol <= currRow) {
            cout << char(ch + currCol - 1);
            currCol = currCol + 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}