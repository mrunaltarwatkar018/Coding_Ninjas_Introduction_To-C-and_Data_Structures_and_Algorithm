/*
        Question  : Remove Consecutive Duplicates

        Problem statement
            For a given string(str), remove all the consecutive duplicate characters.

            Example:
            Input String: "aaaa"
            Expected Output: "a"

            Input String: "aabbbcc"
            Expected Output: "abc"

            Input Format:
            The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.

            Output Format:
            The only line of output prints the updated string.

            Note:
            You are not required to print anything. It has already been taken care of.

            Constraints:
            0 <= N <= 10^6
            Where N is the length of the input string.

            Time Limit: 1 second

            Constraints:
            0 <= N <= 10^6
            Where N is the length of the input string.

            Time Limit: 1 second

            Sample Input 1:
            aabccbaa

            Sample Output 1:
            abcba

            Sample Input 2:
            xxyyzxx

            Sample Output 2:
            xyzx



*/

#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[])
{
    // Write your code here
    int lastIndex = 0;
    for (int i = 1; input[i] != '\0'; i++)
    {
        if (input[lastIndex] != input[i])
        {
            input[++lastIndex] = input[i];
        }
    }
    input[lastIndex + 1] = '\0';
}

// another way
/*
Time complexity: O(N)
Space complexity: O(1)
where N is the length of the input string
*/
void removeConsecutiveDuplicates(char input[])
{
    for (int i = 1; input[i] != '\0'; i++)
    {
        if (input[i] == input[i - 1])
        {
            input[i - 1] = ' ';
        }
    }
    int space = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ')
        {
            char tmp = input[i];
            input[i] = input[space];
            input[space] = tmp;
            space++;
        }
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}