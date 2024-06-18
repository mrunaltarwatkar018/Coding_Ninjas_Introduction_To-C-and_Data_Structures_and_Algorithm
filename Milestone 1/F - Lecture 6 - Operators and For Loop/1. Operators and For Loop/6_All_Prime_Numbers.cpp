/*
        Question  : All Prime Numbers

        Problem statement
            Given an integer N, print all the prime numbers that lie in the
            range 2 to N (both inclusive).

            Print the prime numbers in different lines.

            Detailed explanation ( Input/output format, Notes, Images )

            Input Format :
            Integer N

            Output Format :
            Prime numbers in different lines

            Constraints :
            1 <= N <= 100

            Sample Input 1:
            9

            Sample Output 1:
            2
            3
            5
            7

            Sample Input 2:
            20

            Sample Output 2:
            2
            3
            5
            7
            11
            13
            17
            19
*/

#include <iostream>
using namespace std;

int main()
{

    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;

    if (n >= 2)
    {
        for (int num = 2; num <= n; num++)
        {
            bool isPrime = true;
            for (int div = 2; div < num; div++)
            {
                if (num % div == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                cout << num << endl;
            }
        }
    }
}

#include <iostream>
using namespace std;

int main()
{

    /*
        Read input as specified in the question.
        Print output as specified in the question.
    */

    int n;
    cin >> n;
    if (n >= 2)
    {
        for (int num = 2; num <= n; num++)
        {
            bool isPrime = true;
            for (int div = 2; div < num; div++)
            {
                if (num % div == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                cout << num << endl;
            }
        }
    }
}

// another way

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        bool isPrime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << i << endl;
        }
    }
}