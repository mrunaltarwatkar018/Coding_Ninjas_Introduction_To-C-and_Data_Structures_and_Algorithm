/* =================================================================================================================== */
/* 
    Question  : Running Median
                
                You are given a stream of 'N' integers. For every 'i-th' 
                integer added to the running list of integers, print 
                the resulting median.
                
                Print only the integer part of the median.

                Input format : 
                        The first line of input contains an integer 'N', 
                        denoting the number of integers in the stream.

                        The second line of input contains 'N' integers 
                        separated by a single space.

                Output Format : 
                        Print the running median for every integer added to 
                        the running list in one line (space-separated).

                Constraints :   
                        0 <= N <= 10 ^ 5
                        1 <= ARR[i] <= 10 ^ 5

                        Time Limit: 1 sec


                Sample Input 1 :    
                        6
                        6 2 1 3 7 5
                                          
                Sample Output 1 :   
                        6 4 2 2 3 4

                    Explanation of Sample Output 1 :
                        S = {6}, median = 6
                        S = {6, 2} -> {2, 6}, median = 4
                        S = {6, 2, 1} -> {1, 2, 6}, median = 2
                        S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
                        S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
                        S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

                Sample Input 2 :    
                        5
                        5 4 3 2 1
                                          
                Sample Output 2 :   
                        5 4 4 3 3
*/


#include <iostream>
using namespace std;

// One Method

// #include<queue>
// void findMedian(int *arr, int n)
// {
//     // Write your code here
//     if(n==0){
//         return;
//     }
//     priority_queue<int> maxQ;
//     priority_queue<int,vector<int>,greater<int>> minQ;
//     maxQ.push(arr[0]);
//     cout<<maxQ.top()<<" ";
//     for(int i=1;i<n;i++){
        
//         if(arr[i]<maxQ.top()){
//             maxQ.push(arr[i]);
//             if((maxQ.size()-minQ.size())>1){
//                 int temp=maxQ.top();
//                 maxQ.pop();
//                 minQ.push(temp);
                
//             }
            
//             }
              
        
//         else{
//             minQ.push(arr[i]);
//             if((minQ.size()-maxQ.size())>1){
//                 int temp=minQ.top();
//                 minQ.pop();
//                 maxQ.push(temp);
//             }
//         }
//         if(i%2==0){
//             if(maxQ.size()>minQ.size()){
//                 cout<<maxQ.top()<<" ";
//             }
//             else{
//                 cout<<minQ.top()<<" ";
//             }
//         }
//         else{
//             cout<<(maxQ.top()+minQ.top())/2<<" ";
//         }
        
        
//     }
// }



// Another Method

/*
    Time complexity: O(N * log(N))
    Space complexity: O(N)
    where N is the number of elements in the array
*/

#include <queue>

void findMedian(int* arr, int n) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;

    // For each element in the data stream
    for (int i = 0; i < n; i++) {
        if (maxHeap.size() && arr[i] > maxHeap.top()) {
            minHeap.push(arr[i]);
        } else {
        maxHeap.push(arr[i]);
        }

        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1) {
            if (maxHeap.size() > minHeap.size()) {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            } else {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        int median;
        int totalSize = maxHeap.size() + minHeap.size();

        // When number of elements is odd
        if (totalSize % 2 == 1) {
            if (maxHeap.size() > minHeap.size()) {
                median = maxHeap.top();
            } else {
                median = minHeap.top();
            }
        }

        // When number of elements is even
        else {
            median = 0;
            if (!maxHeap.empty()) median += maxHeap.top();
            if (!minHeap.empty()) median += minHeap.top();
            median /= 2;
        }

        cout << median << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}