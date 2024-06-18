/* =================================================================================================================== */
/* 
    Question  : Code : Inverted Number Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 4
                                4444
                                333
                                22
                                1

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 50

                Sample Input 1 :    
                                    5
                                          
                Sample Output 1 :   
                                    55555 
                                    4444
                                    333
                                    22
                                    1

                Sample Input 2 :    
                                    6
                                          
                Sample Output 2 :   
                                    666666
                                    55555 
                                    4444
                                    333
                                    22
                                    1
*/





// First Method
// #include<iostream>
// using namespace std;


// int main(){

// 	int n;
// 	cin >> n;

// 	int i = 1;
// 	while ( i <= n ) {
// 		int j = 1;
// 		while ( j <= n - i + 1 ) {
// 			cout << ( n - i + 1 );
// 			j++;
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
        int currCol = n - currRow + 1;
        while(currCol >= 1) {
            cout << n - currRow + 1;
            currCol = currCol - 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}