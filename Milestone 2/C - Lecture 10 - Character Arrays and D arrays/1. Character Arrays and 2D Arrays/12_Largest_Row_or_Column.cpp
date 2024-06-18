/*
        Question  : Largest Row or Column

        Problem statement
            For a given two-dimensional integer array/list of size
            (N x M), you need to find out which row or column has
            the largest sum(sum of all the elements in a row or
            column) amongst all the rows/columns.

            Note :
            If there are more than one rows/columns with maximum
            sum, consider the row/column that comes first. And if ith
            row and jth column has the same largest sum, consider the
            ith row as answer.


            Detailed explanation ( Input/output format, Notes, Images )

            Input Format :
            The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

            First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

            Second line onwards, the next 'N' lines or rows represent the ith row values.

            Each of the ith row constitutes 'M' column values separated by a single space.

            Output Format :
            For each test case, If row sum is maximum, then print: "row" <row_index> <row_sum>
            OR
            If column sum is maximum, then print: "column" <col_index> <col_sum>
            It will be printed in a single line separated by a single space between each piece of information.

            Output for every test case will be printed in a seperate line.
            Consider :
            If there doesn't exist a sum at all then print "row 0 -2147483648", where -2147483648 or -2^31 is the smallest value for the range of Integer.


            Constraints:
            1 <= t <= 10^2
            1 <= N <= 10^3
            1 <= M <= 10^3

            Time Limit: 1sec

            Sample Input 1:
            1
            3 2
            6 9
            8 5
            9 2

            Sample Output 1:
            column 0 23

            Sample Input 2:
            1
            4 4
            6 9 8 5
            9 2 4 1
            8 3 9 3
            8 7 8 6

            Sample Output 2:
            column 0 31
*/

#include <iostream>
using namespace std;

// /*
// You can use minimum value of integer as -2147483647 and
// maximum value of integer as 2147483647
// */
// void findLargest(int **input, int nRows, int mCols)
// {
//     // Write your code here
//     int rLargeSum = -2e31;
//     int rCurrentSum = 0;
//     int rIndex = 0;

//     for (int i = 0; i < nRows; i++)
//     {
//         for (int j = 0; j < mCols; j++)
//         {
//             rCurrentSum += input[i][j];
//         }

//         if (rLargeSum < rCurrentSum)
//         {
//             rLargeSum = rCurrentSum;
//             rIndex = i;
//         }
//         rCurrentSum = 0;
//     }

//     int cLargeSum = -2e31;
//     int cCurrentSum = 0;
//     int cIndex = 0;

//     for (int i = 0; i < mCols; i++)
//     {
//         for (int j = 0; j < nRows; j++)
//         {
//             cCurrentSum += input[j][i];
//         }

//         if (cLargeSum < cCurrentSum)
//         {
//             cLargeSum = cCurrentSum;
//             cIndex = i;
//         }
//         cCurrentSum = 0;
//     }

//     if (rLargeSum >= cLargeSum)
//     {
//         cout << "row" << ' ' << rIndex << ' ' << rLargeSum << endl;
//     }
//     else
//     {
//         cout << "column" << ' ' << cIndex << ' ' << cLargeSum << endl;
//     }
// }



// another way
#include <climits>
void findLargest(int **input, int nRows, int mCols)
{
    bool isRow = true;
    int largestSum = INT_MIN;
    int num = 0;
    for (int i = 0; i < nRows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < mCols; j++)
        {
            rowSum += input[i][j];
        }
        if (rowSum > largestSum)
        {
            largestSum = rowSum;
            num = i;
        }
    }
    for (int j = 0; j < mCols; j++)
    {
        int colSum = 0;
        for (int i = 0; i < nRows; i++)
        {
            colSum += input[i][j];
        }
        if (colSum > largestSum)
        {
            largestSum = colSum;
            num = j;
            isRow = false;
        }
    }
    if (isRow)
    {
        cout << "row" << " " << num << " " << largestSum;
    }
    else
    {
        cout << "column" << " " << num << " " << largestSum;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;

        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }

        findLargest(input, row, col);
        cout << endl;
    }
}