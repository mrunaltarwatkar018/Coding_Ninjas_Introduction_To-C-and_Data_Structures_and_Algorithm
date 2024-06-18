/* =================================================================================================================== */
/* 
    Question  : Start Pattern
                
                Print the following pattern

                Pattern for N = 4

                                . . . 1
                                . . 2 3
                                . 3 4 5
                                4 5 6 7
                                
                        The dots represent spaces.

                Input format : 
                                N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :
                                0 <= N <= 50

                Sample Input 1 :    
                                    3


                Sample Output 1 :
                                     * 
                                   * * *  
                                 * * * * *

                Sample Input 2 :    
                                    4


                Sample Output 2 :
                                     * 
                                   * * *  
                                 * * * * *
                               * * * * * * *
                                                                                                            
*/


// First method
// #include<iostream>
// using namespace std;


// int main(){

// 	int n;
// 	cin >> n;

// 	int i = 0, j = 0, k = 0;
// 	while ( i < n) {
// 		while ( k <= n - i - 2 ) {
// 			cout << " ";
// 			k++;
// 		}
// 		k = 0;

// 		while (j < 2 * i - 1) {
//             cout << "*";
//             j++;
//         }
// 		j = 0;
// 		i++;
// 		cout << endl;
// 	}
// 	return 0;
  
// }


// 

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int currRow = 1;
    while(currRow <= n) {
        int spaces = 1;
        while(spaces <= n - currRow) {
            cout << " ";
            spaces = spaces + 1;
        }
        int currCol = 1;
            while(currCol <= (2 * currRow) - 1) {
            cout << '*';
            currCol = currCol + 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}