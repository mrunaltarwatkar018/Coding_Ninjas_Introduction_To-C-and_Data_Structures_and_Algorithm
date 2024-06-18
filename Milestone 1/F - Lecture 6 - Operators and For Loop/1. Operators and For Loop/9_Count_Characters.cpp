/*
        Question  : Count Characters

        Problem statement
            Write a program to count and print the total number of characters
            (lowercase english alphabets only), digits (0 to 9) and white spaces
            (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.

            That is, input will be a stream of characters and you need to consider
            all the characters which are entered till '$'.

            Print count of characters, count of digits and count of white spaces
            respectively (separated by space).

            Detailed explanation ( Input/output format, Notes, Images )

            Input Format :
            A stream of characters terminated by '$'

            Output Format :
            3 integers i.e. count_of_characters count_of_digits count_of_whitespaces (separated by space)

            Sample Input :
            abc def4 5$

            Sample Output :
            6 2 2

            Sample Output Explanation :
            Number of characters : 6 (a, b, c, d, e, f)
            Number of digits : 2 (4, 5)
            Number of white spaces : 2 (one space after abc and one newline after 4)
*/

#include <iostream>
using namespace std;

int main()
{

    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    char c;
    int alphabet = 0;
    int digit = 0;
    int space = 0;
    c = cin.get();
    while (c != '$')
    {
        if (c >= 97 && c <= 122)
            alphabet++;
        else if (c >= 48 && c <= 57)
            digit++;
        else if (c == 9 || c == 32 || c == 10)
            space++;
        c = cin.get();
    }
    cout << alphabet << " " << digit << " " << space;
}

// another way
#include <iostream>
using namespace std;
int main()
{
    char ch;
    ch = cin.get();
    int digits = 0, spaces = 0, characters = 0;
    while (ch != '$')
    {
        if (ch >= 'a' && ch <= 'z')
        {
            characters = characters + 1;
        }
        else if (ch >= '0' && ch <= '9')
        {
            digits = digits + 1;
        }
        else if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            spaces = spaces + 1;
        }
        ch = cin.get();
    }
    cout << characters << " " << digits << " " << spaces;
}