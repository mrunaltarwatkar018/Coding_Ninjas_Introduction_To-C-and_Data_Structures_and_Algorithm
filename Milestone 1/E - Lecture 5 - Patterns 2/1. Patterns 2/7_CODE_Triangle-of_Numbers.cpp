/* =================================================================================================================== */
/* 
    Question  : Code : Alpha Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 4
                                        1
                                       232
                                      34543
                                     4567654

                        The dots represent spaces.

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 50

                Sample Input 1 :    
                                    5
                                          
                Sample Output 1 :   
                                        1
                                       232
                                      34543
                                     4567654
                                    567898765

                Sample Input 2 :    
                                    4
                                          
                Sample Output 2 :   
                                        1
                                       232
                                      34543
                                     4567654
*/





// First Method
// #include <iostream>
// using namespace std;

// int main() {
//     int Nrows;
//     cin >> Nrows;

//     int n, i, j, m, a;
//     cin >> n;

//     for (i = 1; i <= n; i++) {
//         for (int k = n - 1; k >= i; k--) {
//             cout << " ";
//         }
//         a = i;
//         for (j = 0; j < i; j++) {
//             cout << a;
//         }

//        a--;
//        for (m = i - 1; m > 0; m--) {
//             cout << a;
//         }
//         cout << endl;
//     }
// }



// Second Method
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int currRow = 1;
    while(currRow <= n){
        int spaces = 1;
        while(spaces <= n - currRow) {
            cout << " ";
            spaces = spaces + 1;
        }
        int currCol = 1;
        int val = currRow;
        while(currCol <= currRow) {
            cout << val;
            val = val+1;
            currCol = currCol + 1;
        }
        val = 2 * (currRow - 1);
        while(val >= currRow) {
            cout << val;
            val = val - 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}