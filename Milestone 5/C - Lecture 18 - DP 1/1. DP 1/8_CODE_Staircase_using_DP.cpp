/* =================================================================================================================== */
/* 
    Question  : Code : Staircase using Dp
                
                A child is running up a staircase with n steps and can hop 
                either 1 step, 2 steps or 3 steps at a time. Implement a 
                method to count how many possible ways the child can run 
                up to the stairs. You need to return all possible number 
                of ways.
                
                Time complexity of your code should be O(n).
                
                Since the answer can be pretty large print the answer % mod(10^9 +7)

                Input format : 
                        First line will contain T (number of test case).
                        Each test case is consists of a single line 
                        containing an integer N.

                Output Format : 
                        For each test case print the answer in new line

                Constraints :  
                        1 <= T <= 10
                        1 <= N <= 10^5

                Sample Input 1 :    
                        2
                        2
                        3
                                          
                Sample Output 1 :   
                        2
                        4

                Explanation of Sample Output 1 :
                        Test case 1:
                            To reach at top of 2nd stair, we have only two 
                            options i.e (2), (1,1)

                        Test case 2:
                            To reach at top of 3rd stair, we have four options 
                            i.e (1,1,1), (1,2) ,(2,1), (3)

                Sample Input 2 :    
                        2
                        5
                        10
                                          
                Sample Output 2 :   
                        13
                        274
*/


#include <bits/stdc++.h>
using namespace std;

// One Method

// #include<bits/stdc++.h>
// #include<cmath>
// using namespace std;
// void getSteps(int n,int i,int &count){
//     if(i==n){
//         count++;
//         return;
//     }
//     if(i>n){
//         return;
//     }
//     getSteps(n,i+1,count);
//     getSteps(n,i+2,count);
//     getSteps(n,i+3,count);
// }

// int getStepsDP(int n){
//     long long int *arr=new long long int[n+1];
//     int divisor=pow(10,9)+7;
//     arr[n]=1;
//     if(n>0){
//     arr[n-1]=1;
//     }
//     if(n>1){
//     arr[n-2]=2;
//     }
//     for(int i=n-3;i>=0;i--){
//         arr[i]=(arr[i+1]+arr[i+2]+arr[i+3])%divisor;
//     }
//     int ans=arr[0];
//     delete [] arr;
//     // long long int divisor=pow(10,9)+7;
//     return ans;
// }

// int main(){
    
//     // write your code here
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         int n;
//         cin>>n;
//         // int count=0;
//         // getSteps(n,0,count);
//         // cout<<count<<endl;
//         cout<<getStepsDP(n)<<endl;
//     }
//     return 0;
// }


// Another Method

/*
        Time complexity: O(N)
        Space complexity: O(1)
        Where N is the input given
*/

#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

int stairCase(int n) {
    if (n <= 1) {
        return 1;
    }

    long long a = 1, b = 1, c = 2;
    
    for (int i = 0; i <= n - 3; ++i) {
        long long d = (a + b + c) % mod;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<stairCase(n)<<endl;
    }
}