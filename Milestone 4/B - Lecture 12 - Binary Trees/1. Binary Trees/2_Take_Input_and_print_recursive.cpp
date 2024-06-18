#include <iostream>
using namespace std;
#include "1_Binary_Trees_Introduction.h"

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

   BinaryTreeNode <int> * root = takeInput();
   printTree( root );
   delete root;
}



// Output :

/*
    Enter Data : 
    1
    Enter Data : 
    2
    Enter Data : 
    4
    Enter Data :
    -1
    Enter Data :
    -1
    Enter Data :
    5
    Enter Data :
    6
    Enter Data :
    -1
    Enter Data :
    -1
    Enter Data :
    7
    Enter Data :
    -1
    Enter Data :
    -1
    Enter Data : 
    3
    Enter Data : 
    8
    Enter Data :
    -1
    Enter Data :
    -1
    Enter Data :
    -1
    1 : L2 R3
    2 : L4 R5
    4 :
    5 : L6 R7
    6 :
    7 :
    3 : L8
    8 :
*/