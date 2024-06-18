/* =================================================================================================================== */
/* 
    Question  : Code : No. of balanced BTs using DP
                
                Given an integer h, find the possible number of balanced 
                binary trees of height h. You just need to return the 
                count of possible binary trees which are balanced.
                
                This number can be huge, so, return output modulus 10^9 + 7.
                
                Time complexity should be O(h).

                Input format : 
                        The first and only line of input contains an integer, 
                        that denotes the value of h. Here, h is the height of 
                        the tree.

                Output Format : 
                        The first and only line of output contains the count of 
                        balanced binary trees modulus 10^9 + 7.

                Constraints :  
                       1 <= h <= 10^6

                        Time Limit: 1 sec

                Sample Input 1 :    
                        3
                                          
                Sample Output 1 :   
                        15

                Sample Input 2 :    
                        4
                                          
                Sample Output 2 :   
                        315
*/


#include <iostream>
using namespace std;


// One Method

// #include<cmath>
// long long int helper(int n,long long int *arr){
//     if(n<=1){
//         return 1;
//     }
//     if(arr[n]!=-1){
//         return arr[n];
//     }
//     int divisor=pow(10,9)+7;
//     long long int smallOutput=((helper(n-1,arr)*helper(n-1,arr))%divisor)+((helper(n-1,arr)*helper(n-2,arr))%divisor)+((helper(n-2,arr)*helper(n-1,arr))%divisor);
// 	arr[n]=smallOutput%divisor;
//     return arr[n];
// }

// long long int balancedBTs(int n){
//     if(n<=1){
//         return 1;
//     }
//     long long int *arr=new long long int[n+1];
//     for(int i=0;i<=n;i++){
//         arr[i]=-1;
//     }
//     arr[0]=1;
//     arr[1]=1;
//     long long int ans=helper(n,arr);
//     delete [] arr;
//     return ans;
// }



// Another Method

/*
        Time complexity: O(N)
        Space complexity: O(N)
        where N is the final height of the binary tree
*/

#include <vector>

int balancedBTs(int n) {
    vector<long long int> dp(n + 1); // dp[i] represents number of balanced BTs of height i
    
    if (n <= 1) {
        return 1;
    }

    dp[0] = 1;
    dp[1] = 1;

    int mod = 1e9 + 7;

    for (int i = 2; i <= n; ++i) {
        long long int temp1 = dp[i - 1] * dp[i - 1];
        temp1 = temp1 % mod;

        long long int temp2 = 2 * dp[i - 1] * dp[i - 2];
        temp2 = temp2 % mod;

        dp[i] = (temp1 + temp2) % mod;
    }
    
    return dp[n];
}


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}