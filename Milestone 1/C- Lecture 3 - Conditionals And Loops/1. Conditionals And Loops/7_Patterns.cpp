#include <iostream>
using namespace std;

/* to print --->
        1
        1 2
        1 2 3 
        1 2 3 4
        1 2 3 4 5 
        ............
*/
// int main() {
//     int n;
//     cout << "Enter the value of 'n' : ";
//     cin >> n;

//     int i = 1;
//     while ( i <= n)
//     {
//         int j = 1;
//         while ( j <= i) {
//             cout << j << " ";
//             j = j+1;
//         }
//         cout << endl;
//         i = i+1;
//     }
// }

/* to print -----> 
        1
        2 3
        4 5 6
        7 8 9 10
        11 12 13 14 15
        ....................
*/

// int main() {
//     int n;
//     cout << "Enter the value of 'n' : ";
//     cin >> n;

//     int i = 1;
//     int value = 1;
//     while ( i <= n) {
//         int j = 1;
//         while ( j <= i) {
//             cout << value << " ";
//             j = j + 1;
//             value = value + 1;
//         }
//         cout << endl;
//         i = i + 1;
//     }
// }

/* To Print ----> 
              1
            2 3
          4 5 6
*/
// int main() {
//     int n;
//     cout << "Enter the value of 'n' : ";
//     cin >> n;

//     int i = 1;
//     int value = 1;
//     while ( i <= n) {
//         int k = 1;
//         while ( k <= n - i) {
//             cout << " ";
//             k = k + 1;
//         }
        
//         int j = 1;
//         while ( j <= i) {
//             cout << value;
//             j = j + 1;
//             value = value + 1;
//         }
//         cout << endl;
//         i = i + 1;
//     }
// }

/*
            1 
          2 3 2 
        3 4 5 4 3 
      4 5 6 7 6 5 4 
    5 6 7 8 9 8 7 6 5 
..........................
*/

// #include <iostream>
// using namespace std;

// int main()
// {
// 	int rows, count = 0, count1 = 0, k = 0;
//     cout << "Enter The number of rows : ";
//     cin >> rows;

// 	for (int i = 1; i <= rows; ++i) {
// 		for (int space = 1; space <= rows - i; ++space) {
// 			cout << "  ";
// 			++count;
// 		}

// 		while (k != 2 * i - 1) {
// 			if (count <= rows - 1) {
// 				cout << i + k << " ";
// 				++count;
// 			}
// 			else {
// 				++count1;
// 				cout << i + k - 2 * count1 << " ";
// 			}
// 			++k;
// 		}
// 		count1 = count = k = 0;

// 		cout << endl;
// 	}
// 	return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//   /*  Read input as specified in the question.
//    * Print output as specified in the question.
//    */
//   int n;
//   cin >> n;

//   int i = 1;
//   while (i <= n) {
//     int spaces = 1;
//     while (spaces <= n - i) {
//       cout << " ";
//       spaces = spaces + 1;
//     }

//     int col = 1;
//     int value = i;
//     while (col <= i) {
//       cout << value;
//       value = value + 1;
//       col = col + 1;
//     }
//     cout << endl;
//     i = i + 1;
//   }
// }


