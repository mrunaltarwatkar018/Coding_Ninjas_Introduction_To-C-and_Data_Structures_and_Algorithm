/* =================================================================================================================== */
/* 
    Question  : Print ith node
                For a given singly linked list of integers and a position 'i', 
                print the node data at the 'i-th' position.

                Note :
                    Assume that the Indexing for the singly linked list always starts from 0.

                    If the given position 'i',  is greater than the length of the given singly 
                    linked list, then don't print anything.

                Input format : 
                                The first line contains an Integer 't' which denotes the 
                                number of test cases or queries to be run. Then the test 
                                cases follow.

                                The first line of each test case or query contains the 
                                elements of the singly linked list separated by a single space. 

                                The second line contains the value of 'i'. It denotes the position 
                                in the given singly linked list.

                Remember/Consider :
                                While specifying the list elements for input, -1 
                                indicates the end of the singly linked list and hence, 
                                would never be a list element.

                Output Format : 
                                For each test case, print the node data at the 'i-th' 
                                position of the linked list(if exists).

                                Output for every test case will be printed in a separate line.

                Constraints :   1 <= t <= 10^2
                                0 <= N <= 10^5
                                i >= 0
                                Time Limit: 1 sec

                Sample Input 1 : 1     
                                 3 4 5 2 6 1 9 -1  
                                 3    
                                          
                Sample Output 1 : 2

                Sample Input 2 :    2
                                    3 4 5 2 6 1 9 -1 
                                    0
                                    9 8 4 0 7 8 -1
                                    3
                                            
                Sample Output 2 :   3
                                    0
                                
*/

#include <iostream>

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

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void printIthNode(Node *head, int i)
{
    //Write your code here
	int j = 0;
	Node *current = head;
	while ( current != NULL ) {
		if ( j == i ) {
			cout << current -> data;
			break;
		}
		current = current -> next;
		j++;
	}
} 

int main()
{
	int t;
    cout << "Enter the number of test cases : ";
	cin >> t;
	while (t--)
	{   
        cout << "Enter the nodes of the Linked List : ";
		Node *head = takeinput();
		int pos;
        cout << "Enter the position of singly linked list : ";
		cin >> pos;
        cout << "the node data at the i-th position of the linked list : ";
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}
