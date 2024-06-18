/* =================================================================================================================== */
/* 
    Question  : Code : Triangular Number Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 4
                                1
                                21
                                321
                                4321

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
                                    21
                                    321
                                    4321
                                    54321

                Sample Input 2 :    
                                    6
                                          
                Sample Output 2 :   
                                    1
                                    21
                                    321
                                    4321
                                    54321
                                    654321
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
// 		while ( j <= i ){
// 			cout << i - j + 1;
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
        int currCol = currRow;
        while(currCol >= 1) {
            cout << currCol;
            currCol = currCol - 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}