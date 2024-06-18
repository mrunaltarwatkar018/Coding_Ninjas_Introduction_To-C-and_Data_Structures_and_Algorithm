// Creation of pointer variable with number of nodes are five

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


// NOTE :   To print the linked List, we have to pass the address of head 
//            which store the address of first linked list


// whenever we want to travel to hole the List and print it, the condition becomes :: 
void print( Node *head ) {
    Node *temp = head;
    while ( temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }


    temp = head;
    while ( temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
}


// whenwver we want to stop at Last Node and print it, the condition becomes :: 
void print1( Node *head ) {
    Node *temp = head;
    while ( temp -> next != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;

    }
}

int main() {
    // Statically
    Node n1(1);
    Node *head = &n1;       // a pointer variable which holds the address of "n1" variable

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next =&n2;       // "n1" represents or store the address of "n2" variable
    n2.next = &n3;      // "n2" represents or store the address of "n3" variable
    n3.next = &n4;      // "n3" represents or store the address of "n4" variable
    n4.next = &n5;      // "n4" represents or store the address of "n5" variable


    cout << "whenever we want to travel to hole the List and print it, the condition becomes :: " << "while ( head != NULL ) {....}" << endl;
    cout << "Output of print() function : ";
    print(head);

    cout << endl;
    cout << "whenwver we want to stop at Last Node and print it, the condition becomes :: " << "while ( head -> next != NULL ) {....}" << endl;
    cout << "Output of print1() function : ";
    print1(head);
}




// NOTE :
// In the case of Linked List, whenever we create the function in terms of Linked List,
// we have to pass the head variable which store the address of first Node along with second variable address


// whenever we want to travel to hole the List and print it, the condition becomes :: 
// while ( head != NULL)
// {
//     /* code */
// }


// whenwver we want to stop at Last Node and print it, the condition becomes :: 
// while ( head -> next != NULL)
// {
//     /* code */
// }