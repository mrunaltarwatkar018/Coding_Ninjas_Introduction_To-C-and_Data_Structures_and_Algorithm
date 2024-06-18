/* =================================================================================================================== */
/* 
    Question  : Print 2D Array
                
                Given a 2D integer array with n rows and m columns. Print 
                the 0th row from input n times, 1st row n-1 times…..(n-1)th 
                row will be printed 1 time.

                Input format : 
                                Line 1 : No of rows (n) and no of columns (m) 
                                (separated by single space)
                                Line 2 : Row 1 elements (separated by space)
                                Line 3 : Row 2 elements (separated by space)
                                Line 4 : and so on

                Output Format : 
                                The first and only line of output contains true, if x is 
                                present and false, otherwise.

                Sample Input  :    
                                    3 3
                                    1 2 3
                                    4 5 6
                                    7 8 9
                                          
                Sample Output  :   
                                    1 2 3
                                    1 2 3
                                    1 2 3
                                    4 5 6
                                    4 5 6
                                    7 8 9

*/


#include <iostream>
using namespace std;



// void print2DArray(int **input, int row, int col) {
// 	// Write your code here

// 	for ( int i = 0; i < row; i++ ) {
// 		for ( int k = 1; k <= row - i; k++ ) {
// 			for ( int j = 0; j < col; j++ ) {
// 				cout << input[i][j] << ' ';
// 			}
// 			cout << endl;
// 		}
// 	}

// }

void print2DArray( int **input, int row, int col ) {
    
    int k = row;

    for ( int i = 0; i < row; i++ ) {

        for ( int l = k - 1; l >= 0; l-- ) {

            for ( int j = 0; j < col; j++ ) {

                cout << input[i][j] << " ";

            }

            cout << "\n";

        }

        k--;

    }

}

int main() {
    int row, col;
    cin >> row >> col;

    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
	    input[i] = new int[col];
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    print2DArray(input, row, col);
}



































// #include <iostream>
// using namespace std;

// void print2DArray(int **input, int row, int col) {
// 	int i,j,k;
//     for(i=0;i<row;i++){
//         for(k=1;k<=row-i;k++){
//             for(j=0;j<col;j++){
//                 cout << input[i][j] << ' ';
//             }
//             cout << endl;
//         }
//     }

// }
// int main() {
//     int row, col;
//     cin >> row >> col;

//     int **input = new int*[row];
//     for(int i = 0; i < row; i++) {
// 	    input[i] = new int[col];
// 	    for(int j = 0; j < col; j++) {
// 	        cin >> input[i][j];
// 	    }
//     }
//     print2DArray(input, row, col);
// }