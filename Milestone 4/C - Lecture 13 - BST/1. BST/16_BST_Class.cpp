#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

class BST {
    BinaryTreeNode<int> * root;

    public : 

        BST() {
            root = NULL;
        }

        ~BST() {
            delete root;
        }

        void deleteData ( int data ) {
            if ( root == NULL ) {
                return;
            }

        }

        void insert ( int data ) {
            if ( root == NULL ) {
                root = new BinaryTreeNode<int> ( data );
            }

        }

    private :
        bool hasData( int data, BinaryTreeNode<int> * node ) {
            if ( root == NULL ) {
                return false;
            }

            if ( root -> data == data ) {
                return true;
            } else if ( data < node -> data ) {
                return hasData(data, node -> left );
            } else {
                return hasData(data, node -> right );
            }
        }

    public :

        bool hasData ( int data ) {
            return hasData(data, root);
        }
};