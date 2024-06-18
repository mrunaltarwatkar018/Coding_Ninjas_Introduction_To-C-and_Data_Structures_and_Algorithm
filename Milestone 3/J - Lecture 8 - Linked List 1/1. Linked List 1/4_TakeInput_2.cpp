#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *next;

        Node( int data ) {
            this -> data = data;
            next = NULL;
        }
};

void print( Node *head ) {
    while ( head != NULL ) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node* takeInput_Better() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    // -1 indicates the termination of the linked list
    while( data != -1 ) {
        Node * newNode = new Node(data);
        if ( head == NULL ) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = tail -> next;
            // OR
            // tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main() {
    cout << "Enter the Numbers : ";
    Node *head = takeInput_Better();
    cout << "Linked List : ";
    print(head);
}


// Here, Time complexity of takeInput() is : O(n) which good for inserting "n" number of nodes
