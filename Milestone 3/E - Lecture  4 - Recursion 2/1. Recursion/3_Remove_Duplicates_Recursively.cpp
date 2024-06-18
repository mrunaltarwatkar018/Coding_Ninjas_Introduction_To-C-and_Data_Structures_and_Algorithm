/*
        Question  : Remove Duplicates Recursively

        Problem statement
            Given a string S, remove consecutive duplicates from it recursively.

            Detailed explanation ( Input/output format, Notes, Images )

                Input Format :
                String S

                Output Format :
                Output string

                Constraints :
                1 <= |S| <= 10^3
                where |S| represents the length of string

                Sample Input 1 :
                aabccba

                Sample Output 1 :
                abcba

                Sample Input 2 :
                xxxyyyzwwzzz

                Sample Output 2 :
                xyzwz


*/

#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given string itself.
     * No need to return or print anything
     * Taking input and printing output is handled automatically.
     */
    if (input[0] == '\0')
        return;
    if (input[0] == input[1])
    {
        int i = 1;
        for (; input[i] != '\0'; i++)
            input[i - 1] = input[i];
        input[i - 1] = input[i];
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input + 1);
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}