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


        // To Remove Minimum value from the Queue
        // int removeMin() {
        //     // To check Priority Queue is Empty or not
        //     if ( isEmpty() ) {
        //         return 0;   // Priority Queue is Empty
        //     }
        //     int min = pq[0];
        //     pq[0] = pq[pq.size() - 1];
        //     pq.pop_back();

        //     // down-heapify
        //     int parentIndex = 0;

        //     while ( parentIndex < pq.size() ) {
        //         int leftChildIndex = 2 * parentIndex + 1;
        //         int rightChildIndex = 2 * parentIndex + 2;
        //         int minIndex;

        //         if ( leftChildIndex < pq.size() && rightChildIndex < pq.size() ) {
        //             minIndex = (pq[leftChildIndex] <= pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;
        //         }
        //         else if ( leftChildIndex < pq.size() ) {
        //             minIndex = leftChildIndex;
        //         }
        //         else {
        //             break;
        //         }

        //         if ( pq[minIndex] < pq[parentIndex] ) {
        //             int temp = pq[minIndex];
        //             pq[minIndex] = pq[parentIndex];
        //             pq[parentIndex] = temp;
        //         }
        //         else {
        //             break;
        //         }
        //         parentIndex = minIndex;
        //     }
        //     return min;
        // }




        // Heap Sort
        /*
            Time Complexity :   O(nlogn)
            Space Complexity :   O(n)
        */
        int removeMin() {
            // To check Priority Queue is Empty or not
            if(isEmpty()) {
                return 0;		// Priority Queue is empty
            }
            int ans = pq[0];
            pq[0] = pq[pq.size() - 1];
            pq.pop_back();

            // down-heapify

            int parentIndex = 0;
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndx = 2 * parentIndex + 2;
        
            while( leftChildIndex < pq.size() ) {

                int minIndex = parentIndex;

                if ( pq[minIndex] > pq[leftChildIndex] ) {
                    minIndex = leftChildIndex;
                }

                if ( rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex] ) {
                    minIndex = rightChildIndx;
                }

                if ( minIndex == parentIndex ) {
                    break;
                }

                int temp = pq[minIndex];
                pq[minIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            
                parentIndex = minIndex;
                leftChildIndex = 2 * parentIndex + 1;
                rightChildIndx = 2 * parentIndex + 2;
            }

            return ans;
        }

};


int main() {
	PriorityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout << p.getSize() << endl;
	cout << p.getMin() << endl;

	while( !p.isEmpty() ) {
		cout << p.removeMin() << " " ;

	}
	cout << endl;
}

/*
        OUTPUT :
            7
            4
            4 10 15 17 21 67 100 
*/



/*

    Heap Sort :

        For Insertion :

            Time Complexity :   O(nlogn)
            Space Complexity :  O(n)

        For Remove element :
            Time Complexity :   O(nlogn)
            Space Complexity :  O(n)

*/

