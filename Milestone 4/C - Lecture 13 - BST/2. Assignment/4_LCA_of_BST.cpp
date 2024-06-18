/* =================================================================================================================== */
/* 
    Question  : LCA of BST
                
                Given a binary tree and data of two nodes, find 'LCA' 
                (Lowest Common Ancestor) of the given two nodes in the 
                BST.

                LCA :
                        LCA of two nodes A and B is the lowest or deepest 
                        node which has both A and B as its descendants. 

                Note :
                        It is defined that each node is a descendant to itself, 
                        so, if there are two nodes X and Y and X has a direct 
                        connection from Y, then Y is the lowest common 
                        ancestor.

                Note :
                        1.  If out of 2 nodes only one node is present, return 
                            that node. 
                        2.  If both are not present, return -1.
                        3.  all the node data will be unique.


                Input format : 
                                The first line of input contains data of the nodes of 
                                the tree in level order form. The data of the nodes of 
                                the tree is separated by space. If any node does not 
                                have left or right child, take -1 in its place. Since -1 
                                is used as an indication whether the left or right nodes 
                                exist, therefore, it will not be a part of the data of 
                                any node.
                                The following line of input contains two integers, 
                                denoting the value of data of two nodes of given BST.

                Output Format : 
                                The first and only line of output contains the data 
                                associated with the lowest common ancestor node. 

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
                                    2 10
                                          
                Sample Output 1 :   
                                    8

                Sample Input 2 :    
                                    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
                                    2 6
                                          
                Sample Output 2 :   
                                    5

                Sample Input 3 :    
                                    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
                                    12 78
                                          
                Sample Output 3 :   
                                    -1
*/


#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

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

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
    
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

// One Method
// int getLCA(BinaryTreeNode<int> *root, int val1, int val2)
// {
//     // Write your code here
//     if (root == NULL)
//         return -1;
//     if (root->data == val1 || root->data == val2)
//         return root->data;

//     int left = getLCA(root->left, val1, val2);
//     int right = getLCA(root->right, val1, val2);

//     if (left == -1 && right == -1)
//         return -1;
//     else if (left != -1 && right == -1)
//         return left;
//     else if (left == -1 && right != -1)
//         return right;
//     else
//         return root->data;
// }


// Another Method

/*
    Time complexity : O(N)
    Space complexity : O(N)
    where N is the number of nodes in the input BST
*/
BinaryTreeNode<int> *getLCAHelper(BinaryTreeNode<int> *root, int a, int b) {
    if (root == NULL || root->data == a || root->data == b) {
        return root;
    }

    if (root->data < a && root->data < b) {
        return getLCAHelper(root->right, a, b);
    } else if (root->data > a && root->data > b) {
        return getLCAHelper(root->left, a, b);
    }

    BinaryTreeNode<int> *leftLCA = getLCAHelper(root->left, a, b);
    BinaryTreeNode<int> *rightLCA = getLCAHelper(root->right, a, b);
    
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    } else if (leftLCA != NULL) {
        return leftLCA;
    }

    return rightLCA;
}

int getLCA(BinaryTreeNode<int> *root, int val1, int val2) {
    BinaryTreeNode<int> *node = getLCAHelper(root, val1, val2);
    
    return (node == NULL) ? -1 : node->data;
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}