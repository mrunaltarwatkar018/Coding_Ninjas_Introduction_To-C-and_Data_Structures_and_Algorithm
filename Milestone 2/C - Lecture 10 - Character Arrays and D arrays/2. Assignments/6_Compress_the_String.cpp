/*
        Question  : Compress the string

        Problem statement
            Write a program to do basic string compression. For a character which is
            consecutively repeated more than once, replace consecutive duplicate
            occurrences with the count of repetitions.

            Example:
            If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".
            The string is compressed only when the repeated character count
            is more than 1.

            Note:
            Consecutive count of every character in the input string is less than
            or equal to 9. You are not required to print anything. It has already
            been taken care of. Just implement the given function and return the
            compressed string.

            Detailed explanation ( Input/output format, Notes, Images )

            Input Format:
            The first and only line of input contains a string without any
            leading and trailing spaces.

            Output Format:
            The output contains the string after compression printed in
            single line

            Constraints:
            0 <= N <= 10^6

            Where 'N' is the length of the input string.

            Time Limit: 1 sec

            Sample Input 1:
            aaabbccdsa

            Sample Output 1:
            a3b2c2dsa

            Explanation for Sample Output 1:

            In the given string 'a' is repeated 3 times, 'b' is repeated 2 times,
            'c' is repeated 2 times and 'd', 's' and 'a' and occuring 1 time hence
            no compression for last 3 characters.

            Sample Input 2:
            aaabbcddeeeee

            Sample Output 2:
            a3b2cd2e5

            Explanation for Sample Output 2:
            In the given string 'a' is repeated 3 times, 'b' is repeated 2 times,
            'c' is occuring single time, 'd' is repeating 2 times and 'e' is
            repeating 5times.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string getCompressedString(string &input)
{
    // Write your code here.
    // Write your code here
    int size = 1e6;
    char compressString[size];
    for (int i = 0; i <= input.length(); i++)
    {
        compressString[i] = input[i];
    }
    int lastIndex = 0;
    int count = 49;
    for (int i = 1; i <= strlen(compressString); i++)
    {
        if (compressString[i] == compressString[lastIndex])
        {
            count++;
        }
        else
        {
            if (count == 49)
            {
                compressString[++lastIndex] = compressString[i];
                count = 49;
            }
            else if (i == strlen(compressString))
            {
                compressString[lastIndex + 1] = count;
                compressString[lastIndex + 2] = '\0';
            }
            else
            {
                compressString[lastIndex + 1] = count;
                compressString[lastIndex + 2] = compressString[i];
                lastIndex = (lastIndex + 2);
                count = 49;
            }
        }
    }
    return compressString;
}

// another way

/*
Time complexity: O(N)
Space complexity: O(1)
Where 'N' is the length of the input string.
*/
string getCompressedString(string &input)
{
    if (input.length() == 0)
    {
        return "";
    }
    // Variables to iterate the string and keep the count of the current character.
    int startIndex = 0;
    int endIndex = 0;
    // Resultant string.
    string compressedString = "";
    // Iterate all the characters of the string.
    while (startIndex < input.length())
    {
        while ((endIndex < input.length()) && (input[endIndex] == input[startIndex]))
        {
            endIndex += 1;
        }
        int totalCharCount = endIndex - startIndex;
        // If count is greater than 1, then append count to the string, else only character.
        if (totalCharCount != 1)
        {
            compressedString += input[startIndex];
            compressedString += (char)(totalCharCount + '0');
        }
        else
        {
            compressedString += input[startIndex];
        }
        startIndex = endIndex;
    }
    return compressedString;
}

int main()
{
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}