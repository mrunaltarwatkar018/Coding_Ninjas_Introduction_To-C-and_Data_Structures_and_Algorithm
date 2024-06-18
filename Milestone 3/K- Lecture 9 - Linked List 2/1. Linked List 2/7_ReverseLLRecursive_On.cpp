/* METHOD 3 : Reverse Linked List */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "GeneralClass.cpp"


// Best possible approach in order to reverse a Linked List ( as compare to last two approaches )
Node * reverseLL_3( Node *head ) {

    if(head == NULL || head -> next == NULL) {
		return head;
	}

    Node *smallAns = reverseLL_3(head -> next );

    Node *tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    return smallAns;
}

Node* takeInput_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

int main() {
    cout << "Enter the nodes of the INPUT Linked List : ";
	Node *head = takeInput_Better();
    cout << "Updated Reversed Linked List : ";
	head = reverseLL_3(head);
	print(head);
}
