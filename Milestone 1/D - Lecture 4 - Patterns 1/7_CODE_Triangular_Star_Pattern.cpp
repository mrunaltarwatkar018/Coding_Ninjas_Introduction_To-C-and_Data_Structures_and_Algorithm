/* =================================================================================================================== */
/* 
    Question  : Code : Triangular Star Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 4
                                *
                                **
                                ***
                                ****

                    Note : There are no spaces between the stars (*).

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 50

                Sample Input 1 :    
                                    5
                                          
                Sample Output 1 :   
                                    *
                                    **
                                    ***
                                    ****
                                    *****

                Sample Input 2 :    
                                    6
                                          
                Sample Output 2 :   
                                    *
                                    **
                                    ***
                                    ****
                                    *****
                                    ******
*/





// First Method
// #include<iostream>
// using namespace std;


// int main(){
// 	int rows;
// 	cin >> rows;
// 	int i = 1;
// 	while ( i <= rows ) {
// 		int j = 1;
// 		while ( j <= i ) {
// 			cout << "*";
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
        int currCol = 1;
        while(currCol <= currRow) {
            cout << '*';
            currCol = currCol + 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}