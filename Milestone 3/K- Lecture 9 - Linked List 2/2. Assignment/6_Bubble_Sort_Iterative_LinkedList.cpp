/* =================================================================================================================== */
/* 
    Question  : Bubble Sort (Iterative) LinkedList
                
                Given a singly linked list of integers, sort it using 
                'Bubble Sort.'

                Note :
                        No need to print the list, it has already been taken 
                        care. Only return the new head to the list.

                Input format : 
                                The first and the only line of each test case or query 
                                contains the elements of the singly linked list 
                                separated by a single space.

                Remember/Consider :
                                While specifying the list elements for input, -1 
                                indicates the end of the singly linked list and 
                                hence, would never be a list element

                Output Format : 
                                For each test case/query, print the elements of the 
                                sorted singly linked list.

                                Output for every test case will be printed in a 
                                separate line.

                Constraints :   0 <= M <= 10^3
                                Where M is the size of the singly linked list.
                                
                                Time Limit: 1 sec

                Sample Input 1 :    10 9 8 7 6 5 4 3 -1
                                          
                Sample Output 1 :    3 4 5 6 7 8 9 10 

                Sample Input 2 :    10 -5 9 90 5 67 1 89 -1
                                          
                Sample Output 2 :   -5 1 5 9 10 67 89 90 
                                                
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
    where N is the length if the input singly Linked List
*/


// Approach 1
int length ( Node *head ) {
    if ( head == NULL ) {
        return 0;
    }

    Node *temp = head;
    int size = 1 + length( temp -> next );
    return size;
}

Node *bubbleSort( Node *head ) {
    for ( int i = 0; length(head) > i; i++ ) {
        Node *prev = NULL, *curr = head;

        while ( curr -> next != NULL ) {
            if ( curr -> data > curr -> next -> data ) {
                if ( prev != NULL ) {
                    Node *temp = curr -> next -> next;
                    curr -> next -> next = curr;
                    prev -> next = curr -> next;
                    curr -> next = temp;
                    prev = prev -> next;
                } else {
                    head = curr -> next;
                    curr -> next = head -> next;
                    head -> next = curr;
                    prev = head;
                }
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }
    }

    return head;
}


// Approach 2
Node *bubbleSort2(Node *head) {
    // Write your code here
    if (head == NULL)
        return head;

    Node *current = head;
    Node *tail = head;

    while (tail->next != NULL)
        tail = tail->next;

    while (current != tail) {

        if (current->data > current->next->data) {
            int temp = current->next->data;
            current->next->data = current->data;
            current->data = temp;
        }

        if (current->next == tail) {
            tail = current;
            current = head;
        }

        else
            current = current->next;
    }

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
	
        cout << "Enter the Input Linked List : ";
		Node *head = takeinput();
        cout << "Updated Linked List for Approach 1 : ";
		head = bubbleSort( head );
        print(head);

        cout << "Updated Linked List for Approach 2 : ";
		head = bubbleSort2( head );
        print(head);

        
}