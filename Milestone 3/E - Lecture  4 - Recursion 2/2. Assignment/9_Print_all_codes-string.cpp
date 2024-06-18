/*
        Question  : Print All Codes- string

        Problem statement

            Assume that the value of a = 1, b = 2, c = 3, ... , z = 26.
            You are given a numeric string S. Write a program to print
            the list of all possible codes that can be generated from
            the given string.

            Note : The order of codes are not important. Just print them in different lines.

            Detailed explanation ( Input/output format, Notes, Images )

                Input format :
                A numeric string S
                Output Format :
                All possible codes in different lines

                Constraints :
                1 <= Length of String S <= 10

                Sample Input:
                1123

                Sample Output:
                aabc
                kbc
                alc
                aaw
                kw

*/
#include <iostream>
using namespace std;

#include <string>
using namespace std;
void printAllPossibleCodesHelper(string input, string output)
{
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }

    int num = input[0] - 48;
    char ch = num - 1 + 'a';
    printAllPossibleCodesHelper(input.substr(1), output + ch);
    if (input[1] != '\0')
    {
        num = num * 10 + input[1] - 48;
        ch = num - 1 + 'a';
        if (num >= 10 && num <= 26)
        {
            printAllPossibleCodesHelper(input.substr(2), output + ch);
        }
    }
}

void printAllPossibleCodes(string input)
{
    printAllPossibleCodesHelper(input, "");
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
