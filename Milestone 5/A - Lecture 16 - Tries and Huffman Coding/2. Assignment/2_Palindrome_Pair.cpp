/* =================================================================================================================== */
/* 
    Question  : Palindrome Pair
                
                Given 'n' number of words, you need to find if there exist 
                any two words which can be joined to make a palindrome or 
                any word, which itself is a palindrome.

                The function should return either true or false. You don't have 
                to print anything.

                Input format : 
                        The first line of the test case contains an integer 
                        value denoting 'n'.

                        The following contains 'n' number of words each 
                        separated by a single space.

                Output Format : 
                        The first and only line of output contains true if the 
                        conditions described in the task are met and false 
                        otherwise.

                Constraints :  
                        0 <= n <= 10^5
                        Time Limit: 1 sec


                Sample Input 1 :    
                        4
                        abc def ghi cba
                                          
                Sample Output 1 :   
                        true

                Explanation of Sample Input 1:
                        "abc" and "cba" forms a palindrome

                Sample Input 2 :    
                        2
                        abc def
                                          
                Sample Output 2 :   
                        false

                Explanation of Sample Input 2:
                        Neither their exists a pair which forms a palindrome, 
                        nor any of the words is a palindrome in itself. Hence, 
                        the output is 'false.'
*/

#include <bits/stdc++.h>
using namespace std;

// One method
// class TrieNode
// {
// public:
//     char data;
//     TrieNode **children;
//     bool isTerminal;
//     int childCount;

//     TrieNode(char data)
//     {
//         this->data = data;
//         children = new TrieNode *[26];
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//         isTerminal = false;
//         childCount = 0;
//     }
// };

// class Trie
// {
//     TrieNode *root;

// public:
//     int count;

//     Trie()
//     {
//         this->count = 0;
//         root = new TrieNode('\0');
//     }

//     bool add(TrieNode *root, string word)
//     {
//         // Base case
//         if (word.size() == 0)
//         {
//             if (!root->isTerminal)
//             {
//                 root->isTerminal = true;
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }

//         // Small calculation
//         int index = word[0] - 'a';
//         TrieNode *child;
//         if (root->children[index] != NULL)
//         {
//             child = root->children[index];
//         }
//         else
//         {
//             child = new TrieNode(word[0]);
//             root->children[index] = child;
//             root->childCount++;
//         }

//         // Recursive call
//         return add(child, word.substr(1));
//     }

//     void add(string word)
//     {
//         if (add(root, word))
//         {
//             this->count++;
//         }
//     }

//     /*..................... Palindrome Pair................... */
//     bool searchPalindrome(TrieNode *parent, string word)
//     {
//         if (parent->isTerminal || word.size() == 0)
//             return true;
//         if (parent->children[word[0] - 'a'] != NULL)
//             return searchPalindrome(parent->children[word[0] - 'a'], word.substr(1));
//         else
//             return false;
//     }

//     bool searchPalindrome(vector<string> v)
//     {
//         for (int i = 0; i < v.size(); i++)
//         {
//             string s1 = v[i], s2 = v[i];
//             reverse(s1.begin(), s1.end());
//             if (searchPalindrome(root, s1))
//                 return true;
//         }
//         return false;
//     }

//     bool isPalindromePair(vector<string> words)
//     {
//         // Write your code here
//         for (int i = 0; i < words.size(); i++)
//             add(words[i]);
//         return searchPalindrome(words);
//     }
// };



// Another Method

/*
    ---- The Approach We Have Taken To Implement This Problem ----

    The approach we have taken to solve this problem is to store
    the reverse of each of the words in the Trie. We then iterate
    over the words and search that does the Trie contains the same
    word or not.

    It may happen that some parts of the word or a substring exist
    in the Trie. We check for the remaining part of the string to
    be a palindrome or not.

    Vise versa of the above will also be true, that means, it may
    happen that the word in the Trie may extend further over
    different number of branches, hence we check all the branches
    one by one to see if any of the branches make a palindrome.
*/

/*
    ---- Another Possible Solution Could Be ----
    
    There's another way of solving this problem. It goes like this. First add
    the reverse of every word in the trie. Then for every word, search it in
    the trie. If you find it, then that means the word was a palindrome itself
    and you can return true. If you don't find it, you need the length of the
    part that you did find. For example, you're searching for "abcdd" in the
    trie, you didn't find a match for "abcdd" but you found the word "abc" in
    the trie. Finding "abc" in the trie means that the actual word was "cba"
    since we inserted the reverse of every word in the list.
    
    Now, you have the word "abcdd", you found the word "abc" in the trie. If you
    can find whether the part of "abcdd" that comes after "abc", i.e. "dd" is a
    palindrome, you can conclude that concatenating "abcdd" and "cba" will also
    give a palindrome. So you can return true. If the part isn't a palindrome,
    you move to check for the next word.
    
    If you traverse through all words without finding a pair of words that
    combine to form a palindrome or a word that's a palindrome by itself, then
    you can return false.
*/

/*
    Time complexity: O(N * M)
    Space complexity: O(N * M)
    
    where N is the number of words in the Trie and 
    M is the average word length

*/

#include <string>
#include <vector>
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;
    public:
        int count;
        Trie()
        {
            this->count = 0;
            root = new TrieNode('\0');
        }
        bool add(TrieNode *root, string word) {
            // Base case
            if (word.size() == 0) {
                if (!root->isTerminal) {
                    root->isTerminal = true;
                    return true;
                } else {
                    return false;
                }
            }

            // Small calculation
            int index = word[0] - 'a';
            TrieNode *child;

            if (root->children[index] != NULL) {
                child = root->children[index];
            } else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
                root->childCount++;
            }

            // Recursive call
            return add(child, word.substr(1));
        }

        // For user
        void add(string word) {
            if (add(root, word)) {
                this->count++;
            }
        }

        /*..................... Palindrome Pair................... */

        bool isPalindromePair(vector<string> words) {
            for (int i = 0; i < words.size(); i++) {
                this->add(reverseWord(words[i]));
            }

            return isPalindromePair(this->root, words);
        }

        string reverseWord(string word) {
            string reverse = "";

            for (int i = word.length() - 1; i >= 0; i--) {
                reverse += word[i];
            }

            return reverse;
        }

        bool isPalindromePair(TrieNode *root, vector<string> words) {
            if (words.size() == 0) {
                return false;
            }

            for (int i = 0; i < words.size(); i++) {
                if (doesPairExistFor(root, words[i], 0)) {
                    return true;
                }
            }

            return false;
        }

        bool doesPairExistFor(TrieNode *root, string word, int startIndex) {
            /* Since an empty string is always a palindrome, we return 'true' */
            if (word.length() == 0) {
                return true;
            }

            if (startIndex == word.length()) {
                if (root->isTerminal) {
                    /*
                    * When there exists an exact match of the word we are
                    * searching for in the Trie, irrespective of the trie
                    * extends further in the same path.
                    *
                    */
                    return true;
                }

                /*
                * When trie extends further, there doesnt exist an exact
                * match of the string we are looking for.
                * However, it may happen that any of the the branch
                * extending from root may form a palindrome.
                *
                * */
                return checkRemainingBranchesInTrie(root, "");
            }

            int charIndex = word[startIndex] - 'a';
            TrieNode *correspondingChild = root->children[charIndex];

            if (correspondingChild == NULL) {
                /*
                * This means that, down the line in the characters that we are
                * looking for against the word in the trie, the character doesn't
                * exist in the trie. This character can be anywhere in the range [0
                * - (word length-1)]
                *
                * */
                if (root->isTerminal) {
                    return checkWordForPalindrome(word.substr(startIndex));
                }

                return false;
            }

            return doesPairExistFor(correspondingChild, word, (startIndex + 1));
        }

        bool checkRemainingBranchesInTrie(TrieNode *root, string word) {
            /*
            *
            * This function recursively explores all the branches from the root
            * while keeping a track of the characters in the 'word' and checks
            * each word whenever the terminating condition is true.
            *
            * If the word is a palindrome, we return true and stops exploring the
            * other branches. If it is otherwise, we keep on checking the remaining
            * branches.
            *
            * Once all the branches are explored, and we don't find any branch or
            * word that makes itself a palindrome we return false at last.
            *
            */

            if (root->isTerminal) {
                if (checkWordForPalindrome(word)) {
                    return true;
                }
            }

            for (int i = 0; i < 26; i++) {
                TrieNode *childNode = root->children[i];
                if (childNode == NULL) {
                    continue;
                }

                string fwd = word + childNode->data;
                if (checkRemainingBranchesInTrie(childNode, fwd)) {
                    return true;
                }
            }

            return false;
        }

        bool checkWordForPalindrome(string word) {
            int startIndex = 0;
            int endIndex = word.length() - 1;
            while (startIndex < endIndex) {
                if (word[startIndex] != word[endIndex]) {
                    return false;
                }

                startIndex += 1;
                endIndex -= 1;
            }

            return true;
        }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}


