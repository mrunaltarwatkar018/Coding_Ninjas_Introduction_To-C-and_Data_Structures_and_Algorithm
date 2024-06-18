/* =================================================================================================================== */
/* 
    Question  : Code : Square Pattern
                
                WPrint the following pattern for the given N number of rows.

                Pattern for N = 4
                            4444
                            4444
                            4444
                            4444

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 50

                Sample Input 1 :    
                                    7
                                          
                Sample Output 1 :   
                            7777777
                            7777777
                            7777777
                            7777777
                            7777777
                            7777777
                            7777777

                Sample Input 2 :    
                                    6
                                          
                Sample Output 2 :   
                            666666
                            666666
                            666666
                            666666
                            666666
                            666666
*/





// First Method
// #include <cmath> //Header file for using "round()" function.
// #include<iostream>
// using namespace std;


// int main(){

// 	int rows;
// 	cin >> rows;

// 	int i = 1;

//         // for (int i = 1; i <= rows; i++) {
//         //   int j = 1;
//         //   for ( int j = 1; j <= rows; j++) {
// 		// 	  cout << rows;
// 		//   }
//         //   cout << endl;
//         // }

//         for (int i = 1; i <= rows; i++) {
//           int j = 1;
//           do {
// 			  cout << rows;
// 			  j++;
// 		  } while ( j <= rows);
//           cout << endl;
//         }

//     // for ( int i = 1; i <= rows; i++) {
//     //       int j = 1;
//     //       while (j <= rows) {
//     //         cout << rows;
//     //         j++;
//     //       }
//     //       cout << endl;
//     //     }


// 	// while ( i <= rows ) {
// 	// 	int j = 1;
// 	// 	while ( j<= rows ) {
// 	// 		cout << rows;
// 	// 		j++;
// 	// 	}
// 	// 	cout << endl;
// 	// 	i++;
// 	// }
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
        while(currCol <= n) {
            cout << n;
            currCol = currCol+1;
        }
        cout << endl;
        currRow = currRow+1;
    }
}