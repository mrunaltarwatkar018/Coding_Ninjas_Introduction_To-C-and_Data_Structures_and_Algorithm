/* =================================================================================================================== */
/* 
    Question  : Crossword Problem
                
                Coding Ninjas has provided you a crossword of 10*10 grid. 
                The grid contains '+' or '-' as its cell values. Now, you 
                are also provided with a word list that needs to placed 
                accurately in the grid. Cells marked with '-' are to be 
                filled with word list.
                
                For example, The following is an example for the input 
                crossword grid and the word list.


                        +-++++++++
                        +-++-+++++
                        +-------++
                        +-++-+++++
                        +-++-+++++
                        +-++-+++++
                        ++++-+++++
                        ++++-+++++
                        ++++++++++
                        ----------
                        CALIFORNIA;NIGERIA;CANADA;TELAVIV

                    Output for the given input should be:

                        +C++++++++
                        +A++T+++++
                        +NIGERIA++
                        +A++L+++++
                        +D++A+++++
                        +A++V+++++
                        ++++I+++++
                        ++++V+++++
                        ++++++++++
                        CALIFORNIA
                
                Note    : We have provided such test cases that there is only one 
                        solution for the given input.

                Input format : 
                        The first 10 lines of input contain crossword. Each of 
                        10 lines has a character array of size 10. Input characters 
                        are either '+' or '-'.

                        The next line of input contains the word list, in 
                        which each word is separated by ';'.    

                Output Format : 
                        Print the crossword grid, after placing the words 
                        of word list in '-' cells.    

                Constraints :  
                        The number of words in the word list lie 
                        in the range of: [1,6]
                        The length of words in the word list lie 
                        in the range: [1, 10]
                        Time Limit: 1 second


                Sample Input 1 :    
                            +-++++++++
                            +-++-+++++
                            +-------++
                            +-++-+++++
                            +-++-+++++
                            +-++-+++++
                            ++++-+++++
                            ++++-+++++
                            ++++++++++
                            ----------
                            CALIFORNIA;NIGERIA;CANADA;TELAVIV
                                          
                Sample Output 1 :   
                            +C++++++++
                            +A++T+++++
                            +NIGERIA++
                            +A++L+++++
                            +D++A+++++
                            +A++V+++++
                            ++++I+++++
                            ++++V+++++
                            ++++++++++
                            CALIFORNIA

*/


// one method

// #include <bits/stdc++.h>
// using namespace std;
// char crossWord[10][10];

// bool isValidHorizontal(int row, int col, string word) {
//     if (10 - col < word.length())
//         return false;
//     for (int i = 0, j = col; i < word.length(); ++i, j++)
//         if (crossWord[row][j] != '-' && crossWord[row][j] != word[i])
//             return false;
//     return true;
// }

// bool isValidVertical(int row, int col, string word) {

//     if (10 - row < word.length())
//         return false;
//     for (int i = row, j = 0; j < word.length(); ++i, j++)
//         if (crossWord[i][col] != '-' && crossWord[i][col] != word[j])
//             return false;
//     return true;
// }

// void setHorizontal(int row, int col, string word, bool state[]) {
//     for (int i = 0, j = col; i < word.size(); ++i, j++) {
//         if (crossWord[row][j] != '+') {
//             if (crossWord[row][j] == word[i])
//                 state[i] = false;
//             else
//                 state[i] = true;
//             crossWord[row][j] = word[i];
//         }
//     }
// }

// void setVertical(int row, int col, string word, bool state[])
// {
//     for (int i = 0, j = row; i < word.size(); ++i, j++)
//     {
//         if (crossWord[j][col] != '+')
//         {
//             if (crossWord[j][col] == word[i])
//                 state[i] = false;
//             else
//                 state[i] = true;
//             crossWord[j][col] = word[i];
//         }
//     }
// }

// void resetHorizontal(int row, int col, bool state[], int size) {
//     for (int i = 0, j = col; i < size; ++i, j++)
//         if (state[i] == true)
//             crossWord[row][j] = '-';
// }

// void resetVertical(int row, int col, bool state[], int size) {
//     for (int i = 0, j = row; i < size; ++i, j++)
//         if (state[i] == true)
//             crossWord[j][col] = '-';
// }

// void set_value(bool helper[], int len) {
//     for (int i = 0; i < len; i++)
//         helper[i] = false;
// }

// bool crossWordHelper(string input[], int size, int index) {
//     if (index == size) {
//         for (int i = 0; i < 10; i++) {
//             for (int j = 0; j < 10; j++)
//                 cout << crossWord[i][j];
//             cout << endl;
//         }
//         return true;
//     }

//     for (int i = 0; i < 10; i++) {
//         for (int j = 0; j < 10; j++) {
//             if (crossWord[i][j] == '-' || crossWord[i][j] == input[index][0]) {
//                 int length = input[index].size();
//                 bool state[length];
//                 set_value(state, length);
//                 if (isValidHorizontal(i, j, input[index])) {
//                     setHorizontal(i, j, input[index], state);
//                     if (crossWordHelper(input, size, index + 1))
//                         return true;
//                     resetHorizontal(i, j, state, length);
//                 }
//                 if (isValidVertical(i, j, input[index]))
//                 {
//                     setVertical(i, j, input[index], state);
//                     if (crossWordHelper(input, size, index + 1))
//                         return true;
//                     resetVertical(i, j, state, length);
//                 }
//             }
//         }
//     }
//     return false;
// }

// void solveCrossWord(string input[], int size) {
//     bool res = crossWordHelper(input, size, 0);
// }

// int main() {
//     string ss;
//     for (int i = 0; i < 10; i++) {
//         cin >> ss;
//         for (int j = 0; j < ss.size(); j++)
//             crossWord[i][j] = ss[j];
//     }
//     char s[200];
//     cin >> s;
//     string input[10];
//     char ch;
//     string word = "";
//     int a = 0;
//     for (int i = 0; s[i] != '\0'; ++i) {
//         if (s[i] == ';') {
//             input[a++] = word;
//             word = "";
//         }
//         else
//             word += s[i];
//     }
//     input[a++] = word;
//     solveCrossWord(input, a);
//     return 0;
// }








// Another Method

/*
            Time complexity : O(2^K)
            Space complexity : O(N*N)
            where N is the size of cross word
            and K is the number of words

*/

#include <bits/stdc++.h>
using namespace std;

vector<string> crossword(10);
vector<string> words;
bool flag;

void puzzle(int ind) {
    if (!flag) {
        return;
    }

    if (ind == words.size()) {
        if (flag) {
            for (auto word : crossword) {
                cout << word << endl;
            }
            flag = false;
        }
        return;
    }

    int i, j, p, q, k;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            p = i, q = j;
            for (k = 0; k < words[ind].size() && p + k < 10; ++k) {
                if (crossword[p + k][q] != '-' && crossword[p + k][q] != words[ind][k]) {
                    break;
                }
            }

            if (k == words[ind].size()) {
                vector<string> temp = crossword;
                for (k = 0; k < words[ind].size(); ++k) {
                    crossword[p + k][q] = words[ind][k];
                }
                puzzle(ind + 1);
                crossword = temp;
            }

            for (k = 0; k < words[ind].size() && q + k < 10; ++k) {
                if (crossword[p][q + k] != '-' && crossword[p][q + k] != words[ind][k]) {
                    break;
                }
            }

            if (k == words[ind].size()) {
                vector<string> temp = crossword;
                for (k = 0; k < words[ind].size(); ++k) {
                    crossword[p][q + k] = words[ind][k];
                }
                puzzle(ind + 1);
                crossword = temp;
            }
        }
    }
}

int main() {
    flag = true;
    int i, j;

    for (i = 0; i < 10; ++i) {
        cin >> crossword[i];
    }

    string s, w;
    cin >> w;
    for (auto x : w) {
        if (x == ';') {
            words.push_back(s);
            s = "";
        } else
            s += x;
    }
    
    words.push_back(s);
    puzzle(0);
    return 0;
}