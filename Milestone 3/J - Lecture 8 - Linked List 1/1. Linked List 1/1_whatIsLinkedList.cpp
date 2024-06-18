#include<iostream>
using namespace std;

// Creation of pointer variable with number of nodes are two

class Node {
    public :
        int data;
        Node *next;

        Node( int data ) {
            this -> data = data;
            next = NULL;
        }
};

int main() {
    // Statically

    Node n1(1);
    Node * head = & n1;     // a pointer variable which holds the address of "n1" variable

    Node n2(2);

    n1.next = & n2;         // "n1" represents or store the address of "n2" variable

    cout << n1.data << " " << n2.data << endl;

    // Dynamically
    Node *n3 = new Node(10);
    Node *head = n3;        // a pointer variable which holds the address of "n3" variable
    Node *n4 = new Node(20);
    n3 -> next = n4;
    


}