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


        // To insert the new elements in the Priority Queue
        void insert(int element) {
            // to insert an element in last index of RRAY
            pq.push_back(element);

            int childIndex = pq.size() - 1;

            while (childIndex > 0) {

                int parentIndex = ( childIndex - 1 ) / 2;

                /* 
                    if value of ChildIndex is less than the value of ParentIndex, then 
                    SWAP the Both Values of ChildIndex with ParentIndex 
                */
                if ( pq[childIndex] < pq[parentIndex] ) {
                    int temp = pq[childIndex];
                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;
                }
                else {
                    break;
                }
                childIndex = parentIndex;
            }
        }

};