/* =================================================================================================================== */
/* 
    Question  : Code : Max Priority Queue
                
                Implement the class for Max Priority Queue which includes 
                following functions -
                
                1.  getSize -
                        Return the size of priority queue i.e. number of elements 
                        present in the priority queue.

                2.  isEmpty -
                        Check if priority queue is empty or not. Return true or 
                        false accordingly.

                3.  insert -
                        Given an element, insert that element in the priority 
                        queue at the correct position.

                4.  getMax -
                        Return the maximum element present in the priority 
                        queue without deleting. Return -Infinity if priority 
                        queue is empty.

                5.  removeMax -
                        Delete and return the maximum element present in the 
                        priority queue. Return -Infinity if priority queue is 
                        empty.

                Note : main function is given for your reference which 
                we are using internally to test the code.
*/


#include <iostream>
using namespace std;

// One Method 

// #include <vector>
// class PriorityQueue {
//     // Declare the data members here
//     vector<int> pq;

//     public:
//     PriorityQueue()
//     {
//         // Implement the constructor here
//     }

//     /**************** Implement all the public functions here ***************/

//     int getSize()
//     {
//         // Implement the getSize() function here
//         return pq.size();
//     }

//     bool isEmpty()
//     {
//         // Implement the isEmpty() function here
//         return pq.size() == 0;
//     }

//     void insert(int element)
//     {
//         // Implement the insert() function here
//         pq.push_back(element);
//         int childIndex = pq.size() - 1;
//         while (childIndex > 0)
//         {
//             int parentIndex = (childIndex - 1) / 2;
//             if (pq[parentIndex] < pq[childIndex])
//             {
//                 int temp = pq[parentIndex];
//                 pq[parentIndex] = pq[childIndex];
//                 pq[childIndex] = temp;
//             }
//             else
//                 break;
//             childIndex = parentIndex;
//         }
//     }

//     int getMax()
//     {
//         // Implement the getMax() function here
//         if (isEmpty())
//             return 0;
//         return pq[0];
//     }

//     int removeMax()
//     {
//         // Implement the removeMax() function here
//         if (isEmpty())
//             return 0;
//         int max = pq[0];
//         pq[0] = pq[pq.size() - 1];
//         pq.pop_back();
//         int parentIndex = 0;
//         while (parentIndex < pq.size())
//         {
//             int leftChildIndex = 2 * parentIndex + 1;
//             int rightChildIndex = 2 * parentIndex + 2;
//             int maxIndex;
//             if (leftChildIndex < pq.size() && rightChildIndex < pq.size())
//                 maxIndex = (pq[leftChildIndex] >= pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;
//             else if (leftChildIndex < pq.size())
//                 maxIndex = leftChildIndex;
//             else
//                 break;
//             if (pq[maxIndex] > pq[parentIndex])
//             {
//                 int temp = pq[maxIndex];
//                 pq[maxIndex] = pq[parentIndex];
//                 pq[parentIndex] = temp;
//             }
//             else
//                 break;
//             parentIndex = maxIndex;
//         }
//         return max;
//     }
// };


// Another Method

/*
    Time complexity     : O(log(N)) [for insert and removeMax functions]
                        : O(1) [for all other functions]
    Space complexity : O(1) [for all functions]

    where N is the size of the Priority Queue
*/

#include <climits>
#include <vector>
class PriorityQueue {
    vector<int> data;

    public:
        void insert(int element) {
            data.push_back(element);

            int childIndex = data.size() - 1;

            while (childIndex > 0) {
                int parentIndex = (childIndex - 1) / 2;

                if (data[parentIndex] > data[childIndex]) {
                    return;
                }

                int temp = data[childIndex];
                data[childIndex] = data[parentIndex];
                data[parentIndex] = temp;
                childIndex = parentIndex;
            }
        }

        int getMax() {
            if (data.size() == 0) {
                return INT_MIN;
            }
            return data[0];
        }

        int removeMax() {
            if (data.size() == 0) {
                return INT_MIN;
            }

            int ans = data[0];
            data[0] = data[data.size() - 1];
            data.pop_back();

            int parentIndex = 0;
            int leftIndex = parentIndex * 2 + 1;
            int rightIndex = leftIndex + 1;

            while (leftIndex < data.size()) {
                int maxIndex = parentIndex;

                if (data[leftIndex] > data[maxIndex]) {
                    maxIndex = leftIndex;
                }

                if (rightIndex < data.size() && data[rightIndex] > data[maxIndex]) {
                    maxIndex = rightIndex;
                }

                if (maxIndex == parentIndex) {
                    break;
                }

                int temp = data[maxIndex];
                data[maxIndex] = data[parentIndex];
                data[parentIndex] = temp;
                parentIndex = maxIndex;
                leftIndex = parentIndex * 2 + 1;
                rightIndex = leftIndex + 1;
            }

            return ans;
        }
        
        int getSize() {
            return data.size();
        }

        bool isEmpty() {
            return data.size() == 0;
        }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}