/*
        Question  : Print Keypad Combination - string

        Problem statement
            Given an integer n, using phone keypad find out and
            print all the possible strings that can be made using
            digits of input n.

                -------------       -----------------       -----------------
                |           |       |               |       |               |
                |           |       |      ABC      |       |       DEF     |
                |     1     |       |       2       |       |        3      |
                |           |       |               |       |               |
                -------------       -----------------       -----------------
                -------------       -----------------       -----------------
                |           |       |               |       |               |
                |    GHI    |       |      JKL      |       |       MNO     |
                |     4     |       |       2       |       |        3      |
                |           |       |               |       |               |
                -------------       -----------------       -----------------
                -------------       -----------------       -----------------
                |           |       |               |       |               |
                |   PQRS    |       |      TUV      |       |      WXYZ     |
                |     7     |       |       2       |       |        3      |
                |           |       |               |       |               |
                -------------       -----------------       -----------------
                -------------       -----------------       -----------------
                |           |       |               |       |               |
                |           |       |               |       |               |
                |     *     |       |       0       |       |        #      |
                |           |       |               |       |               |
                -------------       -----------------       -----------------

            Note :
            The order of strings are not important. Just print different strings
            in new lines.

            Detailed explanation ( Input/output format, Notes, Images )

                Input Format :
                Integer n

                Output Format :
                All possible strings in different lines

                Constraints :
                1 <= n <= 10^6

                Sample Input:
                23

                Sample Output:
                ad
                ae
                af
                bd
                be
                bf
                cd
                ce
                cf

*/

#include <iostream>
#include <string>

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// string dial(int key)
// {
//     unordered_map<int, string> m;
//     m[0] = "";
//     m[1] = "";
//     m[2] = "abc";
//     m[3] = "def";
//     m[4] = "ghi";
//     m[5] = "jkl";
//     m[6] = "mno";
//     m[7] = "pqrs";
//     m[8] = "tuv";
//     m[9] = "wxyz";
//     return m[key];
// }
// void pK(int num, string out)
// {

//     if (num == 0)
//     {
//         cout << out << endl;
//         return;
//     }
//     string pd = dial(num % 10);
//     for (int i = 0; i < pd.size(); i++)
//     {
//         pK(num / 10, pd[i] + out);
//     }
// }

// void printKeypad(int num)
// {
//     /*
//     Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
//     */
//     pK(num, "");
// }

// Another Approach

#include <iostream>
#include <string>
using namespace std;
void printKeypadHelper(int num, string output, string options[10])
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    int digit = num % 10;
    int i = 0;
    while (i < options[digit].length())
    {
        printKeypadHelper(num / 10, options[digit][i] + output, options);
        i++;
    }
    return;
}
void printKeypad(int num)
{
    string options[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    printKeypadHelper(num, "", options);
    return;
}

using namespace std;

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
