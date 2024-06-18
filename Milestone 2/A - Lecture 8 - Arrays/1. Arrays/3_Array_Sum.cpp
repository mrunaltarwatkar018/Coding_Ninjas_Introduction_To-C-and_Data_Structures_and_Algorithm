/*
        Question  : Print Array Sum

        Problem statement

            Given an array of length N, you need to find and print
            the sum of all elements of the array.

            Detailed explanation ( Input/output format, Notes, Images )

            Input Format :
            Line 1 : An Integer N i.e. size of array
            Line 2 : N integers which are elements of the array, separated by spaces

            Output Format :
            Sum

            Constraints :
            1 <= N <= 10^6

            Note for C++:
            It is advisable to declare an array with a size that can accommodate all the elements, considering that N has a maximum value of 10^5.

            Sample Input :
            3
            9 8 9

            Sample Output :
            26
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

    int input[1000000];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += input[i];
    }

    cout << sum << endl;

    return 0;
}

// another way

#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int arr[1000000];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += arr[i];
    }
    cout << result << endl;
}