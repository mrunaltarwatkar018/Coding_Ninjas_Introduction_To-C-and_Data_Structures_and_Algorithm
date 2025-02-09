/* =================================================================================================================== */
/* 
    Question  : Level wise linkedlist
                
                Given a binary tree, write code to create a separate linked 
                list for each level. You need to return the array which 
                contains head of each level linked list.

                Input format : 
                                The first line of input contains data of the nodes of 
                                the tree in level order form. The data of the nodes of 
                                the tree is separated by space. If any node does not 
                                have left or right child, take -1 in its place. Since -1 
                                is used as an indication whether the left or right nodes 
                                exist, therefore, it will not be a part of the data of 
                                any node.

                Output Format : 
                                Each level linked list is printed in new line 
                                (elements are separated by space).

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
                                          
                Sample Output 1 :   
                                    5 
                                    6 10 
                                    2 3 
                                    9

                                   
*/


#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// One Method

// vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
// {
//     // Write your code here
//     vector<Node<int> *> v = {NULL};
//     if (root == NULL)
//         return v;
//     else
//         v.clear();
//     queue<BinaryTreeNode<int> *> pendingNodes;
//     pendingNodes.push(root);
//     while (pendingNodes.size() != 0)
//     {
//         int n = pendingNodes.size();
//         Node<int> *head = NULL;
//         Node<int> *tail = NULL;
//         while (n != 0)
//         {
//             BinaryTreeNode<int> *front = pendingNodes.front();
//             pendingNodes.pop();
//             Node<int> *newNode = new Node<int>(front->data);
//             if (head == NULL)
//             {
//                 head = newNode;
//                 tail = newNode;
//             }
//             else
//             {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//             if (front->left != NULL)
//                 pendingNodes.push(front->left);
//             if (front->right != NULL)
//                 pendingNodes.push(front->right);
//             n--;
//         }
//         v.push_back(head);
//     }
//     return v;
// }


// Another Method

/*
    Time Complexity : O(N)
    Space Complexity : O(H)

    where N is the number of nodes in the tree
    and H is the height of Nodes in the tree
*/

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int> *> output;

    if (root == NULL) {
        return output;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    int currentLevelRemaining = 1;
    int nextLevelCount = 0;

    Node<int> *currentLevelHead = NULL;
    Node<int> *currentLevelTail = NULL;

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *first = pendingNodes.front();
        pendingNodes.pop();

        Node<int> *newNode = new Node<int>(first->data);

        if (currentLevelHead == NULL) {
        currentLevelHead = newNode;
        currentLevelTail = newNode;
        } else {
            currentLevelTail->next = newNode;
            currentLevelTail = newNode;
        }

        if (first->left != NULL) {
            pendingNodes.push(first->left);
            nextLevelCount++;
        }

        if (first->right != NULL) {
            pendingNodes.push(first->right);
            nextLevelCount++;
        }
        currentLevelRemaining--;

        if (currentLevelRemaining == 0) {
            output.push_back(currentLevelHead);
            currentLevelHead = NULL;
            currentLevelTail = NULL;
            currentLevelRemaining = nextLevelCount;
            nextLevelCount = 0;
        }
    }
    return output;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}