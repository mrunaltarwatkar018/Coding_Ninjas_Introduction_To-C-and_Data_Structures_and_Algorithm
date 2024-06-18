/*
        Question  : Return Permutations - string

        Problem statement
            Given a string S, find and return all the possible permutations of the input string.

            Note 1 : The order of permutations is not important. Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

            Detailed explanation ( Input/output format, Notes, Images )

                Input Format :
                String S

                Output Format :
                All permutations (in different lines)

                Sample Input :
                abc

                Sample Output :
                abc
                acb
                bac
                bca
                cab
                cba


*/
#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    /* Don't write main() function.
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question
     */
    if (input.length() == 0)
    {
        output[0] = "";
        return 1;
    }

    string smallOutput[10000];
    int smallSize = returnPermutations(input.substr(1), smallOutput);
    int k = 0;
    for (int i = 0; i < smallSize; i++)
    {
        for (int j = 0; j <= smallOutput[i].length(); j++)
        {
            output[k++] = smallOutput[i].substr(0, j) + input[0] +
                          smallOutput[i].substr(j);
        }
    }

    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
