/*
        Question  : Column Wise Sum

        Problem statement
           Given a 2D integer array of size M*N, find and print the
           sum of ith column elements separated by space.

           (see in picture)

            Detailed explanation ( Input/output format, Notes, Images )
            Input Format :
            First and only line of input contains M and N, followed by M * N space separated integers representing the elements in the 2D array.
            Output Format :
            Sum of every ith column elements (separated by space)
            Constraints :
            1 <= M, N <= 10^3

            Sample Input 1 :
            4 2
            1 2
            3 4
            5 6
            7 8
            Sample Output 1 :
            16 20
            Sample Input 2:
            6 4
            28 26 24 22
            21 23 25 27
            20 18 16 14
            13 15 17 19
            12 10 8  6
            5  7  11 13
            Sample Output 2:
            99 99 101 101

*/

// #include <iostream>
// using namespace std;

// int main() {

//   /*  Read input as specified in the question.
//    * Print output as specified in the question.
//    */
//   int arr[1000][1000];
//   int r, c;
//   cin >> r >> c;

//   // i for rows
//   for (int i = 0; i < r; i++) {
//     for (int j = 0; j < c; j++) { // j for columns
//       cin >> arr[i][j];
//     }
//   }

//   int sum = 0;

//   // i for columns
//   for (int i = 0; i < c; i++) {
//     for (int j = 0; j < r; j++) { // j for rows
//       sum += arr[j][i];
//     }
//     cout << sum << ' ';
//     sum = 0;
//   }
// }

#include <iostream>
using namespace std;
int main()
{
    int numRows;
    int numCols;
    cin >> numRows >> numCols;
    int input[numRows][numCols];
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cin >> input[i][j];
        }
    }
    for (int j = 0; j < numCols; j++)
    {
        int sum = 0;
        for (int i = 0; i < numRows; i++)
        {
            sum += input[i][j];
        }
        cout << sum << " ";
    }
}