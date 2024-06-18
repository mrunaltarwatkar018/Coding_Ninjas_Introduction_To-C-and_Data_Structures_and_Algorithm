#include <iostream>
using namespace std;
#include "1_Binary_Trees_Introduction.h"


#include <queue>


// take Input level wise
BinaryTreeNode <int> * takeInputLevelWise() {

    int rootData;
    cout << "Enter root Data : " << endl;
    cin >> rootData;

    if ( rootData == -1 ) {
        return NULL;
    }  

    BinaryTreeNode <int> * root = new BinaryTreeNode <int> ( rootData );

    queue <BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push( root );

    while ( pendingNodes.size() != 0 ) {
        
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of : " << front -> data << endl;
        int leftChildData;
        cin >> leftChildData;

        if ( leftChildData != -1 ) {
            BinaryTreeNode <int> * child = new BinaryTreeNode <int> ( leftChildData );
            front -> left = child;
            pendingNodes.push( child );
        }

        cout << "Enter right child of : " << front -> data << endl;
        int rightChildData;
        cin >> rightChildData;

        if ( rightChildData != -1 ) {
            BinaryTreeNode <int> * child = new BinaryTreeNode <int> ( rightChildData );
            front -> right = child;
            pendingNodes.push( child );
        }

    }

    return root;

}

void printTree( BinaryTreeNode <int> * root ) {

    // base case
    if ( root == NULL ) {
        return;
    }

    cout << root -> data << " : ";

    if ( root -> left != NULL ) {
        cout << "L" << root -> left -> data << " ";
    }

    if ( root -> right != NULL ) {
        cout << "R" << root -> right -> data;
    }

    cout << endl;

    printTree( root -> left );
    printTree( root -> right );

}

// Another Method

/*
    Time complexity: O(N)
    Space complexity: O(N)
    where N is the number of nodes in the input tree
*/
#include <queue>
void printLevelWise(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    
    while (!pendingNodes.empty()) {
    BinaryTreeNode<int> *frontNode = pendingNodes.front();
    pendingNodes.pop();

    if (frontNode == NULL) {
        cout << "\n";
        if (!pendingNodes.empty()) {
            pendingNodes.push(NULL);
        }
    } else {
        cout << frontNode->data << ":";
        cout << "L : ";

        if (frontNode->left) {
                pendingNodes.push(frontNode->left);
                cout << frontNode->left->data << ",";
            } else {
                cout << -1 << ",";
            }

            cout << "R:";
            
            if (frontNode->right) {
                pendingNodes.push(frontNode->right);
                cout << frontNode->right->data << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}


// count the nodes
int numNodes ( BinaryTreeNode <int> * root ) {
    // base case

    if ( root == NULL ) {
        return 0;
    }

    return 1 + numNodes ( root -> left ) + numNodes( root -> right );
}

// Traversal
/*  Inorder traversal : LEFT -> ROOT -> RIGHT   */
void inOrder( BinaryTreeNode<int> * root ) {
    if ( root == NULL ) {
        return;
    }

    inOrder( root -> left );
    cout << root -> data << " ";
    inOrder( root -> right );
}


int main() {

    /*
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	
    root->left = node1;
    
	root->right = node2;

    printTree( root );

    delete root;
    */

    BinaryTreeNode <int> * root = takeInputLevelWise();
    cout << endl << endl;

    printTree( root );
    cout << endl << endl;
    cout << "Number of Nodes : " << numNodes(root) << endl;
    cout << "Inorder Traversal Output : ";
    inOrder( root );
    delete root;
}


// Input :  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 


// output

/*
    Enter root Data : 
    1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    Enter left child of : 1
    Enter right child of : 1
    Enter left child of : 2
    Enter right child of : 2
    Enter left child of : 3
    Enter right child of : 3
    Enter left child of : 4
    Enter right child of : 4
    Enter left child of : 5
    Enter right child of : 5
    Enter left child of : 6
    Enter right child of : 6
    Enter left child of : 7
    Enter right child of : 7
    Enter left child of : 8
    Enter right child of : 8
    Enter left child of : 9
    Enter right child of : 9


    1 : L2 R3
    2 : L4 R5
    4 :
    5 :
    3 : L6 R7
    6 : L8 R9
    8 :
    9 :
    7 :


    Number of Nodes : 9
    Inorder Traversal Output : 4 2 5 1 8 6 9 3 7 
*/