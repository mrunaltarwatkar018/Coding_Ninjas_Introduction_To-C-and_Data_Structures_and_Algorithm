#include <iostream>
#include <cstring>
using namespace std;

/* =================================================================================================================== */
/*
    Question  : Check Palindrome (recursive)
                Check whether a given String S is a
                palindrome using recursion. Return true or false.

                Do this recursively. Indexing in the array starts from 0.

                Input format : String S
                Output Format : 'true' or 'false'
                Constraints :  0 <= |S| <= 1000
                                where |S| represents length of string S.
                Sample Input 1 : racecar
                Sample Output 1 : true
                Sample Input 2 : ninja
                Sample Output 2 : false

*/

bool checkPalindrome(char input[])
{
    // Write your code here
    static int i = 0;
    int l = strlen(input);
    if (i == l)
        return true;
    if (input[i] == input[l - i - 1])
    {
        i++;
        checkPalindrome(input);
    }
    else
        return false;
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}







/*
Time Complexity: O(N)
Space Complexity: O(1)
Where N is the length of the string.
*/
// Helper function to check if a string is a palindrome recursively.
// bool isPalindromeHelper(const string &str, int left, int right)
// {
//     // Base case: If the left and right pointers meet or cross each other, the string is a palindrome.
//     if (left >= right)
//     {
//         return true;
//     }
//     // Recursive case: Check if the characters at the left and right pointers are equal.
//     if (str[left] == str[right])
//     {
//         // Recurse for the substring by moving the left pointer to the right and the right pointer to
//         the left.return isPalindromeHelper(str, left + 1, right - 1);
//     }
//     // If the characters at the left and right pointers are not equal, the string is not a palindrome.
//     return false;
// }
// // Function to check if a string is a palindrome.
// bool isPalindrome(string &S)
// {
//     // Call the helper function to perform the recursive palindrome check.
//     // Pass the left pointer as 0 and the right pointer as the last index of the string.
//     return isPalindromeHelper(S, 0, S.length() - 1);
// }