/* =================================================================================================================== */
/* 
    Question  : Code : No. of balanced BTs
                
                Given an integer h, find the possible number of balanced 
                binary trees of height h. You just need to return the 
                count of possible binary trees which are balanced.
                
                This number can be huge, so, return output modulus 10^9 + 7.
                
                Write a simple recursive solution.

                Input format : 
                        The first and only line of input contains an integer, 
                        that denotes the value of h. Here, h is the height of 
                        the tree.

                Output Format : 
                        The first and only line of output contains the count of 
                        balanced binary trees modulus 10^9 + 7.

                Constraints :  
                       1 <= h <= 24
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
// int balancedBTs(int n) {
//     // Write your code here
//     if(n<=1){
//         return 1;
//     }
//     int divisor=(int)(pow(10,9))+7;
//     long long int *arr=new long long int[n+1];
//     arr[0]=1;
//     arr[1]=1;
//     for(int i=2;i<=n;i++){
//         arr[i]=(arr[i-1]*arr[i-1]%divisor+arr[i-2]*arr[i-1]%divisor+arr[i-1]*arr[i-2]%divisor)%divisor;
//     }
//     int ans=arr[n];
//     delete [] arr;
//     return ans;
// }


// Another Method

/*
        Time complexity: O(2^N)
        Space complexity: O(N)
        where N is the final height of the binary tree
*/
int balancedBTs(int n) {
    if (n <= 1) {
        return 1;
    }

    int mod = 1e9 + 7;
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);

    long long int temp1 = ((long long int)x * x) % mod; // Number of BTs made by attaching subtrees of height (n - 1) at both sides of root
    long long int temp2 = (2 * (long long int)x * y) % mod; // Number of BTs made by attaching subtrees of heights (n - 1) and (n - 2) at each side of root
    long long int ans = (temp1 + temp2) % mod;
    
    return ans;
}


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}