/* =================================================================================================================== */
/* 
    Question  : Code : K largest elements
                
                You are given with an integer k and an array of integers 
                that contain numbers in random order. Write a program to 
                find k largest numbers from given array. You need to save 
                them in an array and return it.

                Time complexity should be O(nlogk) and space complexity 
                should be not more than O(k).

                Order of elements in the output is not important.

                Input Format :
                    Line 1 : Size of array (n)
                    Line 2 : Array elements (separated by space)
                    Line 3 : Integer k

                Output Formats :
                    k largest elements
                
                Constraints :
                    Time Limit: 1 sec

                Sample Input 1 :
                    13
                    2 12 9 16 10 5 3 20 25 11 1 8 6 
                    4

                Sample Output 1 :
                    12
                    16
                    20
                    25
*/

#include <iostream>
#include <vector>
using namespace std;

// one Method
// #include<bits/stdc++.h>
// vector<int> kLargest(int arr[], int n, int k){
//     /* Don't write main().
//      * Don't read input, it is passed as function argument.
//      * Return output and don't print it.
//      * Taking input and printing output is handled automatically.
//      */
//     priority_queue<int,vector<int>,greater<int>> pq;
//     for(int i=0;i<k;i++){
//         pq.push(arr[i]);
//     }
//     for(int i=k;i<n;i++){
//         if(arr[i]>pq.top()){
//             pq.pop();
//             pq.push(arr[i]);
//         }
//     }
//     vector<int> ans;
//     while(!pq.empty()){
//         ans.push_back(pq.top());
//         pq.pop();
//     }
//     return ans;

// }

// Another Method

#include <queue>
vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < k; i++) {
        pq.push(input[i]);
    }

    for(int i = k; i < n; i++) {
        if(input[i] > pq.top()) {
            pq.pop();
            pq.push(input[i]);
        }
    }

    vector<int> output;

    while(!pq.empty()) {
        output.push_back(pq.top());
        pq.pop();
    }

    return output;
}

int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}
