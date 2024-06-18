/*
        Question  : Print Permutations

        Problem statement
            Given an input string (STR), print all possible permutations of the input string.

            Note:
            The input string may contain the same characters, so there will also be the same permutations.
            The order of permutations doesn’t matter.

            Detailed explanation ( Input/output format, Notes, Images )
                Sample Input 1:
                cba

                Sample Output 1:
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

#include <iostream>
#include <string>
using namespace std;

void printPermutationsHelper(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < input.length(); i++)
    {
        printPermutationsHelper(input.substr(0, i) + input.substr(i + 1),
                                output + input[i]);
    }
}

void printPermutations(string input)
{

    /* Don't write main() function.
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question
     */
    printPermutationsHelper(input, "");
    return;
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}