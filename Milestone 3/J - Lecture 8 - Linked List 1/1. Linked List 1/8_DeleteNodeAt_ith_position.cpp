#include<iostream>
using namespace std;


// Inserting a Node at ith position

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

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

void print( Node *head ) {
    while ( head != NULL ) {
        cout << head -> data << " ";
        head = head -> next;
    } 
}

Node* insertNode( Node *head, int i, int data ) {
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if ( i == 0 ) {
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while ( temp != NULL && count < i - 1 ) {
        temp = temp -> next;
        count++;
    }    

    if ( temp != NULL ) {
        Node * a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }

    return head;

}

Node* deleteNode( Node *head, int pos ) {

    if ( head == NULL ) {
        return head;
    }

    if ( pos == 0 ) {
        return head -> next;
    }

    Node* curr = head;
    int currPos = 0;

    while ( curr != NULL && currPos < pos - 1 ) {
        ++currPos;
        curr = curr -> next;
    }

    if ( curr == NULL || curr -> next == NULL ) {
        return head;
    } 

    curr -> next = curr -> next -> next;

    return head;
}

int main() {
    cout << "Enter the Linked List : ";
    Node *head = takeInput_Better();
    cout << "Before updating : ";
    print(head);
    cout << endl;
    int i;
    cout << "Enter the position which you want to deleted the Node : ";
    cin >> i;
    head = deleteNode(head, i);
    cout << "Updated Linked List : ";
    print(head);
}