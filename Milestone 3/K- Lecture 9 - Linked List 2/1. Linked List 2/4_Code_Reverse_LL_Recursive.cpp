/* =================================================================================================================== */
/* 
    Question  : Code : Reverse LL (Recursive)
                
                Given a singly linked list of integers, reverse it using 
                recursion and return the head to the modified list. You have 
                to do this in O(N) time complexity where N is the size of the 
                linked list.

                Note :  
                        No need to print the list, it has already been taken 
                        care. Only return the new head to the list.

                Input format : 
                                The first line contains an Integer 't' which denotes the 
                                number of test cases or queries to be run. Then the test 
                                cases follow.

                                The first and the only line of each test case or query 
                                contains the elements of the singly linked list 
                                separated by a single space.

                Remember/Consider :
                                    While specifying the list elements for input, -1 
                                    indicates the end of the singly linked list and 
                                    hence, would never be a list element

                Output Format : 
                                For each test case/query, print the elements of 
                                the sorted singly linked list.

                                Output for every test case will be printed in a 
                                separate line.

                Constraints :   1 <= t <= 10^2
                                0 <= M <= 10^54
                                Where M is the size of the singly linked list.
                                
                                Time Limit: 1 sec

                Sample Input 1 :    1
                                    1 2 3 4 5 6 7 8 -1 
                                          
                Sample Output 1 :    8 7 6 5 4 3 2 1

                Sample Input 2 :    2
                                    10 -1
                                    10 20 30 40 50 -1  
                                          
                Sample Output 2 :   10
                                    50 40 30 20 10 
                                                
*/

#include<iostream>

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail -> next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseLinkedList(Node *head, Node *tail) {
    // Write your code here
    Node *current = head;
    if (current != tail) {
        int temp = current->data;
        current->data = tail->data;
        tail->data = temp;
        while (current->next != tail)
            current = current->next;
        if (head->next == tail)
            return;
        reverseLinkedList(head->next, current);
    }
    else
        return;
}

Node *reverseLinkedListRec(Node *head) {
    // Write your code here
    if (head == NULL)
        return head;
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    reverseLinkedList(head, tail);
    return head;
}


int main()
{
    int t;
    cout << "Enter the number of test cases : ";
    cin >> t;
    while(t--)
    {
        cout << "Enter the nodes of the FIRST Linked List : ";
        Node *head = takeinput();
        head = reverseLinkedListRec(head);
        cout << "Updated Linked List : ";
        print(head);
    }
    return 0;
}