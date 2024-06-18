/*
        Question  : Terms of AP

        Problem statement

            Write a program to print first x terms of the series
            3N + 2 which are not multiples of 4.

            Detailed explanation ( Input/output format, Notes, Images )

            Input format :
            Integer x

            Output format :
            Terms of series (separated by space)

            Constraints :
            1 <= x <= 1,000

            Sample Input 1 :
            10

            Sample Output 1 :
            5 11 14 17 23 26 29 35 38 41

            Sample Input 2 :
            4

            Sample Output 2 :
            5 11 14 17

            Explanation :
            Input is 4 and print the first 4 numbers that are not
            divisible by 4 and are of the form 3N + 2, where k is
            a non-negative integer.
*/

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int x;
    cin >> x;

    int count = 1;
    int term;
    int n = 1;

    while (count <= x)
    {
        term = (3 * n) + 2;
        if (term % 4 != 0)
        {
            cout << term << " ";
            count++;
        }
        n++;
    }
}

// another way

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 1, current = 1;
    while (count <= n)
    {
        int num = 3 * current + 2;
        if (num % 4 != 0)
        {
            cout << num << " ";
            count++;
        }
        current++;
    }
}
