/* =================================================================================================================== */
/* 
    Question  : Swap two Nodes of LL
                
                You have been given a singly linked list of integers along 
                with two integers, 'i,' and 'j.' Swap the nodes that are 
                present at the 'i-th' and 'j-th' positions.

                Note :  
                        Remember, the nodes themselves must be swapped 
                        and not the datas.

                        No need to print the list, it has already been taken 
                        care. Only return the new head to the list.

                Input format : 
                                The first line contains an Integer 't' which denotes the 
                                number of test cases or queries to be run. Then the test 
                                cases follow.

                                The first line of each test case or query contains the 
                                elements of the singly linked list separated by a single 
                                space.

                                The second line of input contains two integer values 
                                'i,' and 'j,' respectively. A single space will 
                                separate them.

                Remember/Consider :
                                While specifying the list elements for input, -1 
                                indicates the end of the singly linked list and 
                                hence, would never be a list element

                Output Format : 
                                For each test case/query, print the elements of the 
                                updated singly linked list.

                                Output for every test case will be printed in a 
                                separate line.

                Constraints :   1 <= t <= 10^2
                                0 <= M <= 10^5
                                Where M is the size of the singly linked list.
                                0 <= i <= M
                                0 <= j <= M
                                
                                Time Limit: 1 sec

                Sample Input 1 :    1
                                    3 4 5 2 6 1 9 -1    
                                    3
                                          
                Sample Output 1 :   3 4 5 6 2 1 9

                Sample Input 2 :    2
                                    10 20 30 40 -1
                                    1 2
                                    70 80 90 25 65 85 90 -1
                                    0 6
                                          
                Sample Output 2 :   10 30 20 40
                                    90 80 90 25 65 85 70
                                                
*/


#include <iostream>

class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
    where n is the size of singly linked list
*/

// Node *swapNodes( Node *head, int i, int j ) {
//     if ( i == j ) {
//         return head;
//     }

//     Node *currentNode = head, *prev = NULL;
//     Node *firstNode = NULL, *secondNode = NULL, *firstNodePrev = NULL, *secondNodeprev = NULL;
//     int pos = 0;

//     while ( currentNode != NULL ) {
//         if ( pos == 1 ) {
//             firstNodePrev = prev;
//             firstNode = currentNode;
//         } else if ( pos == j ) {
//             secondNodeprev = prev;
//             secondNode = currentNode;
//         }
//         prev = currentNode;
//         currentNode = currentNode -> next;
//         pos++;
//     }

//     if ( firstNodePrev != NULL ) {
//         firstNodePrev -> next = secondNode;
//     } else {
//         head = secondNode;
//     }

//     if ( secondNodeprev != NULL ) {
//         secondNodeprev -> next = firstNode;
//     } else {
//         head = firstNode;
//     }

//     Node *currentFirstNode = secondNode -> next;
//     secondNode -> next = firstNode -> next;
//     firstNode -> next = currentFirstNode;

//     return head;
// }

Node *swapNodes(Node *head, int i, int j)
{
    // Write your code here
    if (head == NULL)
        return head;
    int k = 0;
    Node *current = head;
    Node *val1 = NULL;
    Node *val2 = NULL;
    while (k <= i || k <= j)
    {
        if (k == i)
            val1 = current;
        if (k == j)
            val2 = current;
        current = current->next;
        k++;
    }
    int temp = val1->data;
    val1->data = val2->data;
    val2->data = temp;
    return head;
}


using namespace std;

Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1) {
		Node *newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print( Node *head ) {
    Node *temp = head;
    while ( temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
	int t;
    cout << "Enter the Number of testCases : ";
	cin >> t;
	while (t--)
	{
        cout << "Enter the Input Linked List : ";
		Node *head = takeinput();
        int i, j;
        cout << "Enter the value of M and N : ";
        cin >> i >> j;
		head = swapNodes( head, i, j );
        cout << "Updated Linked List : ";
        print(head);
	}
    return 0;
}