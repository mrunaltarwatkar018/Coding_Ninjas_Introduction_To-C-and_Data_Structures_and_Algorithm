/* METHOD 2 : Reverse Linked List Using Another class which hasa complexity O(n) */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "GeneralClass.cpp"

class Pair {
	public :
		
			Node *head;
			Node *tail;
};

// Complexity Of the Following Operation is : O(n) which is quit good approach
Pair reverseLL_2(Node *head) {
	if(head == NULL || head -> next == NULL) {
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}

	Pair smallAns = reverseLL_2(head -> next);

	smallAns.tail -> next = head;
	head -> next = NULL;
	Pair ans;
	ans.head = smallAns.head;
	ans.tail = head;
	return ans;
}

Node* reverseLL_Better(Node *head) {
	return reverseLL_2(head).head;
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
	head = reverseLL_Better(head);
	print(head);
}
