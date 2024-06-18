#include<iostream>
using namespace std;
#include <vector>



class PriorityQueue {
    
    vector <int> pq;

    public :

        PriorityQueue() {

        }

        bool isEmpty() {
            return pq.size() == 0;
        }


        // Return the size of PriorityQueue - number of elements present 
        int getSize() {
            return pq.size();
        }

        // Return the Minimum element of priority Queue
        int getMin() {

            // To check Priority Queue is Empty or not
            if ( isEmpty() ) {
                return 0;   // Priority Queue is Empty
            }
            return pq[0];
        }

};