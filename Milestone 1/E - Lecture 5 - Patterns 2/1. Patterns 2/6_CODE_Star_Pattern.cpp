/* =================================================================================================================== */
/* 
    Question  : Code : Alpha Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 4
                                ...*
                                ..***
                                .*****
                                *******

                        The dots represent spaces.

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 50

                Sample Input 1 :    
                                    3
                                          
                Sample Output 1 :   
                                       *
                                      *** 
                                     *****

                Sample Input 2 :    
                                    4
                                          
                Sample Output 2 :   
                                        *
                                       *** 
                                      *****
                                     *******
*/





// First Method
// #include<iostream>
// using namespace std;


// int main(){
// 	int n;
// 	cin >> n;

// 	int i = 1;
// 	while ( i <= n ) {
// 		int spaces = 1;
// 		while ( spaces <= n - i ) {
// 			cout << ' ';
// 			spaces++;
// 		}

// 		int j = 1;
// 		while ( j <=i ) {
// 			cout << '*';
// 			j++;
// 		}

// 		j = i - 1;
// 		while ( j >= 1 ) {
// 			cout << '*';
// 			j--;
// 		}

// 		cout << endl;
// 		i++;
// 	}
  
// }










// Second Method
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