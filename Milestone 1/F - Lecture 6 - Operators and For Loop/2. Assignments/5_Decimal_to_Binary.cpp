/*
        Question  : Decimal to Binary

        Problem statement
            Given a decimal number (integer N), convert it into binary and print.

            Note for C++ coders:
            Do not use the inbuilt implementation of "pow" function. The implementation
            of that function is done for 'double's and it may fail when used for 'int's,
            'long's, or 'long long's. Implement your own "pow" function to work for
            non-float data types.

            The given input number could be large, so the corresponding binary number can
            exceed the integer range. So you may want to take the answer as long for CPP
            and Java.


            Detailed explanation ( Input/output format, Notes, Images )

            Input format :
            Integer N

            Output format :
            Corresponding Binary number (long)

            Constraints :
            0 <= N <= 10^5

            Sample Input 1 :
            12

            Sample Output 1 :
            1100

            Sample Input 2 :
            7

            Sample Output 2 :
            111

            Sample Input 2 :
            0

            Sample Output 2 :
            0
*/

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;

    long answer = 0;
    long placeValue = 1;

    while (n > 0)
    {
        int rem = n % 2;

        answer = answer + placeValue * rem;
        placeValue = placeValue * 10;
        n = n / 2;
    }
    cout << answer << endl;
    return 0;
}

// another way

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long binary = 0, pow = 1;
    while (n > 0)
    {
        int lastBit = n % 2;
        binary += lastBit * pow;
        pow *= 10;
        n = n / 2;
    }
    cout << binary;
}
