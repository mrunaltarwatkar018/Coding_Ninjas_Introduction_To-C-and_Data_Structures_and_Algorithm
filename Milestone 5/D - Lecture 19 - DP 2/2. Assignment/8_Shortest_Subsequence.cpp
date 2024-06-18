/* =================================================================================================================== */
/* 
    Question  : Shortest Subsequence
                
                    Gary has two string S and V. Now, Gary wants to know the 
                    length shortest subsequence in S, which is not a subsequence 
                    in V.
                    
                    Note: The input data will be such that there will always be 
                    a solution.
                
                Input format : 
                        The first line of input contains a string, that denotes 
                        the value of S. The following line contains a string, 
                        that denotes the value of V.

                Output Format : 
                       Length of shortest subsequence in S such that it is 
                       not a subsequence in V

                Constraints :  
                        1 <= |S| <= 1000 (|x| implies the length of the string x)
                        1 <= |V| <= 1000 

                        Time Limit: 1 sec

                Sample Input 1 :    
                        babab
                        babba
                                          
                Sample Output 1 :   
                        3

                Explanation:
                        "aab" is the shortest subsequence which is present 
                        in S and absent in V.
*/


#include <iostream>
#include <string>
using namespace std;

// Fisrt Approach
int getans(char *s1, char *s2, int len1, int len2, int **dp) {
    if (len1 <= 0) {
        return 1001;
    }

    if (len2 <= 0) {
        return 1;
    }

    if (dp[len1][len2] > -1) {
        return dp[len1][len2];
    }
    
    int ans = 0;
    int option1 = getans(s1 + 1, s2, len1 - 1, len2, dp);
    int i = 0;
    
    for (; i < len2; i++) {
        if (s1[0] == s2[i]) {
            break;
        }
    }

    if (i == len2) {
        return 1;
    }

    int option2 = 1 + getans(s1 + 1, s2 + i + 1, len1 - 1, len2 - 1 - i, dp);
    
    ans = min(option1, option2);
    dp[len1][len2] = ans;
    
    return ans;
}

int solve(string S, string V) {
    // Write your code here.
    char *s1 = new char[S.length()];
    char *s2 = new char[V.length()];
    for (int i = 0; i < S.length(); i++)
    {
        s1[i] = S[i];
    }
    for (int i = 0; i < V.length(); i++)
    {
        s2[i] = V[i];
    }
    int **dp = new int *[S.length() + 1];
    for (int i = 0; i <= S.length(); i++)
    {
        dp[i] = new int[V.length() + 1];
        for (int j = 0; j <= V.length(); j++)
        {
            dp[i][j] = -1;
        }
    }
    return getans(s1, s2, S.length(), V.length(), dp);
}

// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(N * M)
    Space compleity: O(N * M)
    
    where N and M are the lengths of the two input strings
*/

#include <vector>

int solve(string s, string v) {
    /*
        We establish the relationship between the sub problems and the
        problem at hand. Let dp(i, j) be the length of the shortest subsequence
        that is in s[1..i] that is not in v[1..j]. Here we have the following
        relationship: dp(i, j) = ...
        1) If letter s[i] is nowhere to be found in v[1..j], then dp(i,j) = 1
        2) Otherwise, we have two case:
        2a) s[i] is in the shortest subsequence. We find k, the most
        immediate index in v[1..j] where v[k] == s[i].
        Then dp(i, j) = 1 + dp(i-1, k-1)
        2b) s[i] is not in the shortest subsequence. Then dp(i, j) = dp(i-1, j)
        We pick whichever is lower.
    */
    
    int n = s.length();
    int m = v.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<int>> next(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++) {
        int prev = -1;
        for (int j = 0; j < m; j++) {
            if (s[i] == v[j]) {
                prev = j;
            }

            next[i + 1][j + 1] = prev;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1e9;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (next[i][j] == -1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
            }
        }
    }

    return dp[n][m];
}
// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
    Time complexity: O(N * M)
    Space compleity: O(N * M)
    
    where N and M are the lengths of the two input strings
*/
#include <vector>

int solve(string s, string v) {
    /*
        We establish the relationship between the sub problems and the
        problem at hand. Let dp(i, j) be the length of the shortest subsequence
        that is in s[1..i] that is not in v[1..j]. Here we have the following
        relationship: dp(i, j) = ...
        1) If letter s[i] is nowhere to be found in v[1..j], then dp(i,j) = 1
        2) Otherwise, we have two case:
        2a) s[i] is in the shortest subsequence. We find k, the most
        immediate index in v[1..j] where v[k] == s[i].
        Then dp(i, j) = 1 + dp(i-1, k-1)
        2b) s[i] is not in the shortest subsequence. Then dp(i, j) = dp(i-1, j)
        We pick whichever is lower.
    */
    
    int n = s.length();
    int m = v.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<int>> next(n + 1, vector<int>(m + 1));
    
    for (int i = 0; i < n; i++) {
        int prev = -1;
        for (int j = 0; j < m; j++) {
            if (s[i] == v[j]) {
                prev = j;
            }
            next[i + 1][j + 1] = prev;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1e9;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (next[i][j] == -1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}






