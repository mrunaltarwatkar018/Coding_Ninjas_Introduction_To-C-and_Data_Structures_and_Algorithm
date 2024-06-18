/* =================================================================================================================== */
/* 
    Question  : Code : Alpha Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 3
                            A
                            BB
                            CCC

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 26

                Sample Input 1 :    
                                    7
                                          
                Sample Output 1 :   
                                    A
                                    BB
                                    CCC
                                    DDDD
                                    EEEEE
                                    FFFFFF
                                    GGGGGGG

                Sample Input 2 :    
                                    6
                                          
                Sample Output 2 :   
                                    A
                                    BB
                                    CCC
                                    DDDD
                                    EEEEE
                                    FFFFFF
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
//         while (j <= i) {
//             cout << char('A' + i - 1);
//             j++;
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
        char ch = 'A' + currRow - 1;
        while(currCol <= currRow) {
            cout << ch;
            currCol = currCol + 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}