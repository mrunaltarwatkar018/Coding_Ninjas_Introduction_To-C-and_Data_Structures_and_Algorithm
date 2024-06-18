/* =================================================================================================================== */
/* 
    Question  : k Reverse
                
                Given a singly linked list of integers, reverse the nodes of 
                the linked list 'k' at a time and return its modified list.

                'k' is a positive integer and is less than or equal to the 
                length of the linked list. If the number of nodes is not a 
                multiple of 'k,' then left-out nodes, in the end, should be 
                reversed as well.

                Example :   
                            Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

                            For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

                            For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4

                Note :
                        No need to print the list, it has already been taken 
                        care. Only return the new head to the list.

                Input format : 
                                The first line contains an Integer 't' which denotes the 
                                number of test cases or queries to be run. Then the test 
                                cases follow.

                                The first line of each test case or query contains the 
                                elements of the singly linked list separated by a single 
                                space.

                                The second line of input contains a single integer 
                                depicting the value of 'k'.

                Remember/Consider :
                                While specifying the list elements for input, -1 
                                indicates the end of the singly linked list and 
                                hence, would never be a list element

                Output Format : 
                                For each test case/query, print the elements of the 
                                updated singly linked list.

                                Output for every test case will be printed in a 
                                separate line.

                Constraints :   1 <= t <= 10^2
                                0 <= M <= 10^5
                                Where M is the size of the singly linked list.
                                0 <= k <= M
                                
                                Time Limit: 1 sec

                Sample Input 1 :    1
                                    1 2 3 4 5 6 7 8 9 10 -1   
                                    4
                                          
                Sample Output 1 :   4 3 2 1 8 7 6 5 10 9

                Sample Input 2 :    2
                                    1 2 3 4 5 -1
                                    0
                                    10 20 30 40 -1
                                    4
                                          
                Sample Output 2 :   1 2 3 4 5 
                                    40 30 20 10 
                                                
*/


#include <iostream>

class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

/*
    Time Complexity : O(n)
    Space Complexity : O(n/k)
    For each Linked List of size n,
    n/k or (n/k)+1 calls will be made during the recursion
*/

Node *kReverse( Node *head, int k ) {
    if ( k == 0 || k == 1 ) {
        return head;
    }

    Node *current = head;
    Node *fwd = NULL;
    Node *prev = NULL;

    int count = 0;

    /* Reverse first k nodes of linked List */

    while ( count < k && current != NULL ) {
        fwd = current -> next;
        current -> next = prev;
        prev = current;
        current = fwd;
        count++;
    }

    if ( fwd != NULL ) {
        head -> next = kReverse( fwd, k);
    }

    return prev;
}


// Another Approach 
void reverseLinkedList(Node *head, Node *tail)
{
    // Write your code here
    Node *current = head;
    if (current != tail)
    {
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

Node *kReverse1(Node *head, int k)
{
    // Write your code here
    if (head == NULL)
        return head;
    int count = k;
    Node *current = head;
    Node *prev = head;
    while (current != NULL)
    {
        while (count != 1 && count != 0 && prev->next != NULL)
        {
            prev = prev->next;
            count--;
        }
        reverseLinkedList(current, prev);
        prev = prev->next;
        current = prev;
        count = k;
    }
    return head;
}

using namespace std;

Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1) {
		Node *newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
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

int main()
{
	int t;
    cout << "Enter the Number of testCases : ";
	cin >> t;
	while (t--)
	{
        cout << "Enter the Input Linked List : ";
		Node *head = takeinput();
        int k;
        cout << "Enter the value of k : ";
        cin >> k;
		head = kReverse( head, k );
        cout << "Updated Linked List for Approach 1 : ";
        print(head);

        // head = kReverse1( head, k );
        // cout << "Updated Linked List for Approach 2 : ";
        // print(head);
	}

    return 0;
}