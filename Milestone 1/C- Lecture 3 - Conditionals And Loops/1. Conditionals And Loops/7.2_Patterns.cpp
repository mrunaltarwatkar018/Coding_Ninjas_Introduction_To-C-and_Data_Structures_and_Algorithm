#include<iostream>
using namespace std;

/*
    Enter the value of n : 5
                  Output :  *****
                            *****
                            *****
                            *****
                            *****
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <=n)
//         {
//             cout << "*";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
    Enter the value of n : 5
            Output  :   *
                        **
                        ***
                        ****
                        *****
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1; 
// 	while ( i <= n ) {
// 		int j = 1;
// 		while ( j <= i ) {
// 			cout << "*";
// 			j++;
// 		}
// 		cout << endl;
// 		i++;
// 	} 
// }


/*
        Enter the value of n : 4
                      Output : 1111
                               2222
                               3333
                               4444
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <=n)
//         {
//             cout << i;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
        Enter the value of n : 5
                      Output : 12345
                               12345
                               12345
                               12345
                               12345
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <=n)
//         {
//             cout << j;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }


/*
Enter the value of n :  4
              Output :  4321
                        4321
                        4321
                        4321
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <=n)
//         {
//             cout << n - j + 1;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
        Enter the value of n :  5
                      Output :  1
                                12
                                123
                                1234
                                12345
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << j;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
        Enter the value of n :  5
                      Output :  1
                                23
                                345
                                4567
                                56789
*/

// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n ) {
//         int p = i;
//         int j = 1;
//         while (j <= i ) {
//             cout << p;
//             p++;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }


/*
        Enter the value of n :  5
                      Output :  1
                                22
                                333
                                4444
                                55555
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n ) {
//         int j = 1;
//         while (j <= i ) {
//             int p = i;
//             cout << p;
//             p++;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
        Enter the value of n :  5
                      Output :  1
                                23
                                456
                                78910
                                1112131415
*/

// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     int k = 1;
//     while (i <= n ) {
//         int j = 1;
//         while (j <= i ) {
//             cout << k;
//             k++;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
          Enter the value of n : 5
                        Output : 1
                                 21
                                 321
                                 4321
                                 54321
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n ) {
//         int j = 1;
//         while (j <= i ) {
//             cout << i - j + 1;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
Enter the value of n :  5
              Output :  A
                        BB
                        CCC
                        DDDD
                        EEEEE
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while (i <= n ) {
//         int j = 1;
//         while (j <= i ) {
//             cout << char('A' + i - 1);
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

/*
        Enter the value of n :  5
                      Output :  A
                                BC
                                CDE
                                DEFG
                                EFGHI
*/
// int main(){
    
// 	int n;
//     cout << "Enter the value of n : ";
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

// #include<iostream>
// using namespace std;


// int main() {
    
//     int n;
//     cin >> n;
//     int currRow = 1;
//     while(currRow <= n) {
//         int currCol = 1;
//         char ch = 'A' + currRow - 1;
//         while(currCol <= currRow) {
//             cout << char(ch + currCol - 1);
//             currCol++;
//         }
//         cout << endl;
//         currRow++;
//     }
    
// }

/*
        Enter the value of n :   6
                        Output : 1
                                 22
                                 333
                                 4444
                                 55555
                                 666666
*/
// int main(){

//        /*  Read input as specified in the question.
// 	* Print output as specified in the question.
// 	*/
// 	int n;
//         cout << "Enter the value of n : ";
// 	cin >> n;
        
// 	int i = 1;
// 	int val = 1;
// 	while ( i <= n ) {
// 		int j = 1;
// 		while ( j <= i ) {
// 			cout << val;
// 			j++;
// 		}
// 		val++;
// 		cout << endl;
// 		i++;
// 	}  
// }

/* Output : 
                1
                12
                123
                1234
                12345
                123456
                1234567
                12345678
*/

int main() {
    int i = 1;
    while ( i < 10 ) {
        int j = 1;
        while ( j < i ) {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}