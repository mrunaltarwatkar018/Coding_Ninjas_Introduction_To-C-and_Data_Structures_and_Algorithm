/* =================================================================================================================== */
/* 
    Question  : Code : Alpha Pattern
                
                Print the following pattern for the given N number of rows.

                Pattern for N = 4
                                A
                                BC
                                CDE
                                DEFG

                Input format : 
                                Integer N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Constraints :   
                                0 <= N <= 13

                Sample Input 1 :    
                                    5
                                          
                Sample Output 1 :   
                                    A
                                    BC
                                    CDE
                                    DEFG
                                    EFGHI

                Sample Input 2 :    
                                    6
                                          
                Sample Output 2 :   
                                    A
                                    BC
                                    CDE
                                    DEFG
                                    EFGHI
                                    FGHIJK
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
// 		char chrr = 'A' + i - 1;
// 		while ( j <= i ) {
// 			cout << char( chrr + j - 1);
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
        char ch = 'A' + currRow - 1;
        while(currCol <= currRow) {
            cout << char(ch + currCol - 1);
            currCol = currCol + 1;
        }
        cout << endl;
        currRow = currRow + 1;
    }
}