/*
        Question  : Binary to Decimal

        Problem statement
            Given a binary number as an integer N, convert it into
            decimal and print.

            Detailed explanation ( Input/output format, Notes, Images )

            Input format :
            An integer N in the Binary Format

            Output format :
            Corresponding Decimal number (as integer)

            Constraints :
            0 <= N <= 10^9

            Sample Input 1 :
            1100

            Sample Output 1 :
            12

            Sample Input 2 :
            111

            Sample Output 2 :
            7
*/

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;

    int answer = 0;
    int placeValue = 1;

    while (n > 0)
    {
        int last = n % 10;
        answer = answer + placeValue * last;
        placeValue = placeValue * 2;
        n = n / 10;
    }
    cout << answer << endl;
}

// another way

#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int decimal = 0, pow = 1;
    while (num > 0)
    {
        int last = num % 10;
        decimal += last * pow;
        pow *= 2;
        num = num / 10;
    }
    cout << decimal;
}
