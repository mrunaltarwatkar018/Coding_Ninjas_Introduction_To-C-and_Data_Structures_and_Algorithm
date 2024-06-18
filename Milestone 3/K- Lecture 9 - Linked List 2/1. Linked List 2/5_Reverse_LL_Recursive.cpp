/* METHOD 1 : Reverse Linked List Using Another class which hasa complexity O(n^2) */

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};


// Complexity Of the Following Operation is : O(n^2) which is quit bad approach
Node * reverseLL( Node * head ) {

    // base case 0 or 1
    if( head == NULL || head -> next == NULL ) {
        return head;
    }

    Node *smallAns = reverseLL( head -> next );

    Node * temp = smallAns;
    while ( temp -> next != NULL ) {
        temp = temp -> next;
    }

    temp -> next = head;
    head -> next = NULL;
    return smallAns;
}

Node * takeInput_Better() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while ( data != -1 ) {
        Node *newNode = new Node( data );
        if ( head == NULL ) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;

            // OR 
            // tail = newNode;
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

int main() {
    cout << "Enter the nodes of the INPUT Linked List : ";
	Node *head = takeInput_Better();
	head = reverseLL(head);
    cout << "Updated Reversed Linked List : ";
	print(head);
}