/* =================================================================================================================== */
/* 
    Question  : Pair sum in a BST
                
                GGiven a binary search tree and an integer S, find pair of 
                nodes in the BST which sum to S. You can use extra space of 
                the order of O(log n).

                Note :
                        1.  Assume BST contains all unique elements.
                        2.  In a pair, print the smaller element first.

                Input format : 
                                The first line of input contains data of the nodes of 
                                the tree in level order form. The data of the nodes of 
                                the tree is separated by space. If any node does not 
                                have left or right child, take -1 in its place. Since -1 
                                is used as an indication whether the left or right nodes 
                                exist, therefore, it will not be a part of the data of 
                                any node.   
                                The following line of input contains an integer, that 
                                denotes the value of S.

                Output Format : 
                                You have to print each pair in a different line 
                                (pair elements separated by space). The order of 
                                different pairs, to be printed, does not matter. 

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
                                    12
                                          
                Sample Output 1 :   
                                    2 10
                                    5 7
*/

#include <iostream>
#include <queue>

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

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

// One Method
// #include <stack>
// int countnodes(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;

//     return 1 + countnodes(root->left) + countnodes(root->right);
// }
// void printNodesSumToS(BinaryTreeNode<int> *root, int s)
// {

//     int totalnodes = countnodes(root);
//     int count = 0;

//     stack<BinaryTreeNode<int> *> inorder;
//     stack<BinaryTreeNode<int> *> revinorder;

//     BinaryTreeNode<int> *temp = root;

//     while (temp)
//     {
//         inorder.push(temp);

//         temp = temp->left;
//     }
//     temp = root;
//     while (temp)
//     {
//         revinorder.push(temp);

//         temp = temp->right;
//     }

//     while (count < totalnodes - 1)
//     {
//         BinaryTreeNode<int> *top1 = inorder.top();
//         BinaryTreeNode<int> *top2 = revinorder.top();
//         if (top1->data + top2->data == s)
//         {
//             cout << top1->data << " " << top2->data << endl;

//             BinaryTreeNode<int> *top = top1;
//             inorder.pop();
//             count++;
//             if (top->right)
//             {
//                 top = top->right;
//                 while (top)
//                 {
//                     inorder.push(top);
//                     top = top->left;
//                 }
//             }
//             top = top2;
//             revinorder.pop();
//             count++;
//             if (top->left)
//             {
//                 top = top->left;
//                 while (top)
//                 {
//                     revinorder.push(top);
//                     top = top->right;
//                 }
//             }
//         }
//         else if (top1->data + top2->data > s)
//         {
//             BinaryTreeNode<int> *top = top2;
//             revinorder.pop();
//             count++;
//             if (top->left)
//             {
//                 top = top->left;
//                 while (top)
//                 {
//                     revinorder.push(top);
//                     top = top->right;
//                 }
//             }
//         }
//         else
//         {
//             BinaryTreeNode<int> *top = top1;
//             inorder.pop();
//             count++;
//             if (top->right)
//             {
//                 top = top->right;
//                 while (top)
//                 {
//                     inorder.push(top);
//                     top = top->left;
//                 }
//             }
//         }
//     }
// }

// Another Method

/*
    Time complexity: O(N * log(N))
    Space complexity: O(H)
    where N is the number of nodes in the input binary tree
    and H is the height of the input binary tree
*/

#include <stack>

int countNodes(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if (root == NULL) {
        return;
    }

    int totalCount = countNodes(root);
    int count = 0;

    stack<BinaryTreeNode<int> *> inorder;
    stack<BinaryTreeNode<int> *> revInorder;

    BinaryTreeNode<int> *currentNode = root;

    while (currentNode != NULL) {
        inorder.push(currentNode);
        currentNode = currentNode->left;
    }

    currentNode = root;
    while (currentNode != NULL) {
        revInorder.push(currentNode);
        currentNode = currentNode->right;
    }
    
    while (count < totalCount - 1) {
        BinaryTreeNode<int> *inorderTop = inorder.top();
        BinaryTreeNode<int> *revInorderTop = revInorder.top();
        if (inorderTop->data + revInorderTop->data == s) {
            cout << inorderTop->data << " " << revInorderTop->data << endl;

            BinaryTreeNode<int> *top = inorderTop;
            inorder.pop();
            count++;
            if (top->right != NULL) {
                top = top->right;
                while (top != NULL) {
                    inorder.push(top);
                    top = top->left;
                }
            }

            top = revInorderTop;
            revInorder.pop();
            count++;
            if (top->left != NULL) {
                top = top->left;
                while (top != NULL) {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        } else if (inorderTop->data + revInorderTop->data > s) {
            BinaryTreeNode<int> *top = revInorderTop;
            revInorder.pop();
            count++;
            if (top->left != NULL) {
                top = top->left;
                while (top != NULL) {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        } else {
            BinaryTreeNode<int> *top = inorderTop;
            inorder.pop();
            count++;
            if(top -> right != NULL) {
                top = top -> right;
                while (top != NULL ) {
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
    }
}


int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}