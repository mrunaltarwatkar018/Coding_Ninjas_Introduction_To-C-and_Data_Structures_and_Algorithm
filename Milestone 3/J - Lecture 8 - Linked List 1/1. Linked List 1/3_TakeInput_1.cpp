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

Node* takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    

    // -1 indicates the termination of the linked list
    while( data != -1 ) {
        Node * newNode = new Node(data);
        if ( head == NULL ) {
            head = newNode;
        } else {
            // head -> next = newNode;     // this line is correct only for the second node, not for all beacuse it is not connected "n" number of nodes.
            Node *temp = head;
            while ( temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin >> data;
    }
    return head;
}

int main() {
    cout << "Enter the Numbers : ";
    Node *head = takeInput();
    cout << "Linked List : ";
    print(head);
}


/*
    Here, Time complexity of takeInput() is : O(n^2) which is not good  for inserting "n" number of nodes
*/