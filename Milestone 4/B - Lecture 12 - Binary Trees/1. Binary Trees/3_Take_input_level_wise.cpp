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

// take input as normal

BinaryTreeNode <int> * takeInput() {
    int rootData;
    cout << "Enter Data : " << endl;
    cin >> rootData;

    if ( rootData == -1 ) {
        return NULL;
    }  

    BinaryTreeNode <int> * root = new BinaryTreeNode <int> ( rootData );
    BinaryTreeNode <int> * leftChild = takeInput();
    BinaryTreeNode <int> * rightChild = takeInput();

    root -> left = leftChild;
    root -> right = rightChild;

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

   cout << endl << " Our Final Tree " << endl;
   printTree( root );
   delete root;
}




// output


/*
    Enter root Data : 
    1
    Enter left child of : 1
    2
    Enter right child of : 1
    3
    Enter left child of : 2
    4
    Enter right child of : 2
    5
    Enter left child of : 3
    6
    Enter right child of : 3
    7
    Enter left child of : 4
    -1
    Enter right child of : 4
    -1
    Enter left child of : 5
    8
    Enter right child of : 5
    9
    Enter left child of : 6
    -1
    Enter right child of : 6
    -1
    Enter left child of : 7
    -1
    Enter right child of : 7
    -1
    Enter left child of : 8
    -1
    Enter right child of : 8
    -1
    Enter left child of : 9
    -1
    Enter right child of : 9
    -1

    Our Final Tree
    1 : L2 R3
    2 : L4 R5
    4 :
    5 : L8 R9
    8 :
    9 :
    3 : L6 R7
    6 : 
    7 :
*/