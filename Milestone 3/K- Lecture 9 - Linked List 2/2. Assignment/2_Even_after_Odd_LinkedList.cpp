/* =================================================================================================================== */
/* 
    Question  : Even after Odd Linked List
                
                For a given singly linked list of integers, arrange the 
                elements such that all the even numbers are placed after 
                the odd numbers. The relative order of the odd and even 
                terms should remain unchanged.

                Note :  
                        No need to print the list, it has already been taken 
                        care. Only return the new head to the list.

                Input format : 
                                The first line contains an Integer 't' which denotes the 
                                number of test cases or queries to be run. Then the test 
                                cases follow.

                                The first line of each test case or query contains the 
                                elements of the singly linked list separated by a single 
                                space.

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
                                
                                Time Limit: 1 sec

                Sample Input 1 :    1
                                    1 4 5 2 -1    
                                    100 
                                          
                Sample Output 1 :   1 5 4 2

                Sample Input 2 :    2
                                    1 11 3 6 8 0 9 -1
                                    10 20 30 40 -1
                                          
                Sample Output 2 :   1 11 3 9 6 8 0
                                    10 20 30 40
                                                
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

Node *evenAfterOdd( Node *head ) {
    if( head == NULL ) {
        return head;
    }

    Node *evenHead = NULL;
    Node *oddHead = NULL;
    Node *evenTail = NULL;
    Node *oddTail = NULL;

    while ( head != NULL ) {
        if ( head -> data % 2 == 0 ) {
            if ( evenHead == NULL ) {
                evenHead = head;
                evenTail = head;
            } else {
                evenTail -> next = head;
                evenTail = evenTail -> next;
            }
        } else {
            if ( oddHead == NULL ) {
                oddHead = head;
                oddTail = head;
            } else {
                oddTail -> next = head;
                oddTail = oddTail -> next;
            }
        }
        head = head -> next;
    }

    if ( oddHead == NULL ) {
        return evenHead;
    } else {
        oddTail -> next = evenHead;
    }

    if ( evenHead != NULL ) {
        evenTail -> next = NULL;
    }

    return oddHead;
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
        cout << "Updated Linked List : ";
		head = evenAfterOdd( head );
        print( head );
	}
    return 0;
}