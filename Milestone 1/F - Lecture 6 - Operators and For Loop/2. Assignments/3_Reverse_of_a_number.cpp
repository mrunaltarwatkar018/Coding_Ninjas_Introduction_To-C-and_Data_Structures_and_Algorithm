/*
        Question  : Reverse of a Number

        Problem statement

            Write a program to generate the reverse of a given number N.
            Print the corresponding reverse number.

            Note : If a number has trailing zeros, then its reverse will
            not include them. For e.g., reverse of 10400 will be 401
            instead of 00401.

            Detailed explanation ( Input/output format, Notes, Images )

            Input format :
            Integer N

            Output format :
            Corresponding reverse number

            Constraints:
            0 <= N < 10^8

            Sample Input 1 :
            1234

            Sample Output 1 :
            4321

            Sample Input 2 :
            1980

            Sample Output 2 :
            891
*/

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;

    int reverseNumber = 0;

    while (n > 0)
    {
        int last = n % 10;
        reverseNumber = reverseNumber * 10 + last;
        n = n / 10;
    }
    cout << reverseNumber << endl;
}

// another way

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int temp = n, revNum = 0;
    while (temp > 0)
    {
        int lastDigit = temp % 10;
        temp = temp / 10;
        revNum = revNum * 10 + lastDigit;
    }
    cout << revNum;
}
