/* =================================================================================================================== */
/* 
    Question  : Longest Leaf to root path
                
                Given a binary tree, return the longest path from leaf to 
                root. Longest means, a path which contain maximum number 
                of nodes from leaf to root.

                Input format : 
                        Elements in level order form (separated by space)
                        (If any node does not have left or right child, 
                        take -1 in its place)

                Output Format : 
                                Line 1 : Binary Tree 1 (separated by space)

                Constraints :   
                                1 <= N <= 10^5

                Sample Input 1 :    
                                    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
                                          
                Sample Output 1 :   
                                    9
                                    3
                                    6
                                    5
*/


#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


// One way to solve

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

// vector<int>* longestPath(BinaryTreeNode<int>* root) {
// 	// Write your code here
//     if ( root == NULL ) {
//         vector<int> * ans = new vector<int>();
//         return ans;
//     }

//     if ( root -> left == NULL && root -> right == NULL ) {
//         vector<int>* ans = new vector<int>();
//         ans -> push_back( root -> data );
//         return ans;
//     }

//     vector<int>* leftOutput = longestPath( root -> left );
//     vector<int>* rightOutput = longestPath( root -> right );

//     if ( rightOutput -> size() > leftOutput -> size() ) {
//         rightOutput -> push_back( root -> data );
//         delete leftOutput;
//         return rightOutput;
//     } else {
//         leftOutput -> push_back( root -> data );
//         delete rightOutput;
//         return leftOutput;
//     }

// }


/*
    vector<int>* longestPath(BinaryTreeNode<int>* root) {
        // Write your code here
        if(root==NULL){
            vector<int>* ans=new vector<int>();
            return ans;
        }
        if(root->left==NULL && root->right==NULL){
            vector<int>* ans=new vector<int>();
            ans->push_back(root->data);
            return ans;
        }
        vector<int>* leftOutput=longestPath(root->left);
        vector<int>* rightOutput=longestPath(root->right);
        if(rightOutput->size()>leftOutput->size()){
            rightOutput->push_back(root->data);
            delete leftOutput;
            return rightOutput;
        }
        else{
            leftOutput->push_back(root->data);
            delete rightOutput;
            return leftOutput;
        }

    }
*/


// Another Method
vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return NULL;
    }

    if (!root->left && !root->right) {
        vector<int>* output = new vector<int>();
        output->push_back(root -> data);
        return output;
    }

    vector<int>* leftAns = longestPath(root->left);
    vector<int>* rightAns = longestPath(root->right);

    if (!leftAns) {
        rightAns->push_back(root->data);
        return rightAns;
    } else if (!rightAns) {
        leftAns->push_back(root->data);
        return leftAns;
    } else {
        if (leftAns->size() < rightAns->size()) {
            rightAns->push_back(root->data);
            delete leftAns;
            return rightAns;
        } else {
            leftAns->push_back(root->data);
            delete rightAns;
            return leftAns;
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
