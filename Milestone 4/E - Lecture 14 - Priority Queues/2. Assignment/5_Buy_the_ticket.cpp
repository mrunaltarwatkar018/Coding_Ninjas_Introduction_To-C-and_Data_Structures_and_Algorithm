/* =================================================================================================================== */
/* 
    Question  : Buy the ticket
                
                You want to buy a ticket for a well-known concert which is 
                happening in your city. But the number of tickets available 
                is limited. Hence the sponsors of the concert decided to 
                sell tickets to customers based on some priority.

                A queue is maintained for buying the tickets and every 
                person is attached with a priority (an integer, 1 being 
                the lowest priority).

                The tickets are sold in the following manner -

                    1.  The first person (pi) in the queue requests 
                        for the ticket.
                    2.  If there is another person present in the queue who 
                        has higher priority than pi, then ask pi to move at end 
                        of the queue without giving him the ticket.
                    3.  Otherwise, give him the ticket (and don't make him stand 
                        in queue again).
                
                Giving a ticket to a person takes exactly 1 second and it 
                takes no time for removing and adding a person to the queue. 
                And you can assume that no new person joins the queue.
                
                Given a list of priorities of N persons standing in the 
                queue and the index of your priority (indexing starts from 0). 
                Find and return the time it will take until you get the ticket.

                Input format : 
                        The first line of input contains an integer, that 
                        denotes the value of total number of people standing 
                        in queue or the size of the array of priorities. 
                        Let us denote it with the symbol N.
                        
                        The following line contains N space separated integers, 
                        that denote the value of the elements of the array of 
                        priorities.
                        
                        The following contains an integer, that denotes the 
                        value of index of your priority. Let us denote it 
                        with symbol k.

                Output Format : 
                        The first and only line of output contains the time 
                        required for you to get the ticket.

                Constraints :  
                        Time Limit: 1 sec


                Sample Input 1 :    
                        3
                        3 9 4
                        2
                                          
                Sample Output 1 :   
                        2

                    Explanation of Sample Output 1 :
                        Person with priority 3 comes out. But there is a 
                        person with higher priority than him. So he goes 
                        and then stands in the queue at the end. Queue's 
                        status :  {9, 4, 3}. Time : 0 secs.

                        Next, the person with priority 9 comes out. And there 
                        is no person with higher priority than him. So he'll 
                        get the ticket. Queue's status :  {4, 3}. Time : 1 secs.

                        Next, the person with priority 4 comes out 
                        (which is you). And there is no person with 
                        higher priority than you. So you'll get the ticket. 
                        Time : 2 secs.

                Sample Input 2 :    
                        5
                        2 3 2 2 4
                        3
                                          
                Sample Output 2 :   
                        4
*/


#include <iostream>
#include <vector>
using namespace std;

// One Method

// #include<bits/stdc++.h>
// #include<climits>
// int buyTicket(int *arr, int n, int k) {
//     // Write your code here
//     priority_queue<int> pq;
//     for(int i=0;i<n;i++){
//         pq.push(arr[i]);
//     }
//     int count=0;
//     while(!pq.empty()) {
//         for(int i=0;i<n;i++) {
//             if(arr[i]>=pq.top()) {
//                 count++;
//                 if(i==k){
//                     return count;
//                 }
//                 arr[i]=INT_MIN;
//                 pq.pop();
//             }
//         }
//     }
//     return count;
// }


// Another Method

/*
Time complexity: O(N * log(N))
Space complexity: O(N)
where N is the number of people in the queue
*/

#include <queue>

int buyTicket(int *arr, int n, int k) {
    queue<int> peopleQueue;

    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++) {
        peopleQueue.push(arr[i]);
        maxHeap.push(arr[i]);
    }

    int count = 0;

    while (!maxHeap.empty()) {
        if (peopleQueue.front() == maxHeap.top()) {
                if (k == 0) {
                    return count + 1;
                } else {
                    count++;
                    peopleQueue.pop();
                    maxHeap.pop();
                    k--;
                }
        } else {
            peopleQueue.push(peopleQueue.front());
            peopleQueue.pop();

            if (k == 0) {
                k = peopleQueue.size() - 1;
            } else {
                k--;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}