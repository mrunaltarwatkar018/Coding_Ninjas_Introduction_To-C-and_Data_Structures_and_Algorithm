#include<iostream>
using namespace std;

/*
        Enter the value of n :  5
                      Output :  ABCDE
                                ABCDE
                                ABCDE
                                ABCDE
                                ABCDE
*/
// int main() {
// 	int n;
//     cout << "Enter the value of n : ";
// 	cin >> n; 

//     int i = 1;
//     while ( i<=n ) {
//         int j = 1; 
//         while ( j<=n ) {
//             // char ch = 'A' + j - 1;
//             // cout << ch;
//             cout << char('A' + j - 1);
//             j++;
//         }
//         cout << endl;
//         i++;
//     }       
// }


/*
        Enter the value of n :  5
                      Output :  AAAAA
                                BBBBB
                                CCCCC
                                DDDDD
                                EEEEE
*/
// int main() {
// 	int n;
//     cout << "Enter the value of n : ";
// 	cin >> n; 

//     int i = 1;
//     while ( i<=n ) {
//         int j = 1; 
//         while ( j<=n ) {
//             // char ch = 'A' + i - 1;
//             // cout << ch;
//             cout << char('A' + i - 1);
//             j++;
//         }
//         cout << endl;
//         i++;
//     }       
// }


/*
        Enter the value of n :  5
                      Output :  ABCDE
                                BCDEF
                                CDEFG
                                DEFGH
                                EFGHI
*/
// int main() {
// 	int n;
//     cout << "Enter the value of n : ";
// 	cin >> n; 

//     int i = 1;
//     while ( i<=n ) {
//         int j = 1;
//         char startChar = 'A' + i - 1; 
//         while ( j<=n ) {
//             char ch = startChar + j - 1;
//             cout << ch;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }       
// }


/*
        Enter the value of n :  5
                      Output :  A
                                AB
                                ABC
                                ABCD
                                ABCDE
*/
// int main(){

//        /*  Read input as specified in the question.
// 	* Print output as specified in the question.
// 	*/
// 	int n;
//     cout << "Enter the value of n : ";
// 	cin >> n;
        
// 	int i = 1;
// 	int val = 1;
// 	while ( i <= n ) {
// 		int j = 1;
// 		while ( j <= i ) {
// 			cout << char('A' + j - 1);
// 			j++;
// 		}
// 		val++;
// 		cout << endl;
// 		i++;
// 	}  
// }



int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
	int n;
	cin >> n;

	int i = 1;

	while ( i <= n ) {
		int j = 1;
		while ( j <= i ){
			cout << i - j + 1;
			j++;
		}
		cout << endl;
		i++;
	}  
}