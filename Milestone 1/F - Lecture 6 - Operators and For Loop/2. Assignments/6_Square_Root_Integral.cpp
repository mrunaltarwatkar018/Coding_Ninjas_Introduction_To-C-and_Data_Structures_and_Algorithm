/*
        Question  : Square Root integral

        Problem statement
            Given a number N, find its square root. You need to find
            and print only the integral part of square root of N.

            For eg. if number given is 18, answer is 4.

            Detailed explanation ( Input/output format, Notes, Images )

            Input format :
            Integer N

            Output Format :
            Square root of N (integer part only)

            Constraints :
            0 <= N <= 10^8

            Sample Input 1 :
            10

            Sample Output 1 :
            3

            Sample Input 2 :
            4

            Sample Output 2 :
            2
*/

// A more optimised solution of this problem will be taught later
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int output = 0;
    while (output * output <= n)
    {
        output = output + 1;
    }
    output = output - 1;
    cout << output;
}

// another way

// A more optimised solution of this problem will be taught later
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int output = 0;
    while (output * output <= n)
    {
        output = output + 1;
    }
    output = output - 1;
    cout << output;
}
