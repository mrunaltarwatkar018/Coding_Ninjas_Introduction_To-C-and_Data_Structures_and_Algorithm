
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

// inorder
void inorder(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;

	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);

	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}


BinaryTreeNode<int> * buildTree( int * in, int * pre, int size ) {
    return buildTreeHelper( in, pre, 0, size - 1, 0, size - 1 );
}



int main() {
	/*
            BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
            BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
            BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
            root->left = node1;
            root->right = node2;
	*/

	int in[] = {4,2,5,1,8,6,9,3,7};
	int pre[] = {1,2,4,5,3,6,8,9,7};

	BinaryTreeNode<int>* root = buildTree(in, pre, 9);
	printTree(root);

    cout << endl;
    cout << endl;

    cout << "Number of Nodes : " << numNodes(root);

    cout << endl;
    cout << endl;

    cout << "Construct Tree From Preorder and Inorder : ";

	inorder(root);

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

 Our Final Tree
For Normal tree  Printing

1 : L2 R3
2 : L4 R5
4 :
5 :
3 : L6 R7
6 : L8 R9
8 :
9 :
7 :


For Level wise tree  Printing

1:L : 2,R:3
2:L : 4,R:5
3:L : 6,R:7
4:L : -1,R:-1
5:L : -1,R:-1
6:L : 8,R:9
7:L : -1,R:-1
8:L : -1,R:-1
9:L : -1,R:-1


Number of Nodes : 9
*/