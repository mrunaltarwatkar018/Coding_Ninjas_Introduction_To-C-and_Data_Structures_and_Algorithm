#include <iostream>
#include <queue>
#include "3_TreeNodeClass.h"
using namespace std;

TreeNode <int> * takeInputLevelWise() {
    int rootData;
    cout << "Enter The Root Data : " << endl;
    cin >> rootData;

    TreeNode<int> * root = new TreeNode<int> (rootData);

    queue <TreeNode<int>*> pendingNodes;

    pendingNodes.push( root );

    while ( pendingNodes.size() != 0 ) {

        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
		cout << "Enter number of children of " << front -> data << " : " << endl;
        int numChild;
        cin >> numChild;

        for ( int i = 0; i < numChild; i++ ) {

            int childData;
			cout << "Enter " << i << "th child of " << front->data << " : " << endl;
            cin >> childData;
            TreeNode<int> * child = new TreeNode<int>(childData);
            front -> children.push_back( child );
            pendingNodes.push( child );

        }

    }

    return root;

}

TreeNode <int>* takeInput() {

    int rootData;
    cout <<  "Enter Data : " << endl;
    cin >> rootData;

	TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter the number of children of " << rootData << " : " << endl;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {

        TreeNode<int>* child = takeInput();
		root -> children.push_back(child);

    }

    return root;

}

void printTree( TreeNode<int>* root ) {

    // 'h' case not a base case
    if ( root == NULL ) {
        return;
    }

    cout << root -> data << " : ";

    for ( int i = 0; i < root -> children.size(); i++ ) {
        cout << root -> children[i] -> data << ", ";
    }

    cout << endl;

    for ( int i = 0; i < root -> children.size(); i++ ) {
        printTree( root -> children[i] );
    }

}


/*
    Time Complexity : O(N)
    Space Complexity : O(M)

    where N is the number of nodes in the tree and
    M is the maximum number of nodes in a level

*/

void printLevelWisee( TreeNode<int> * root ) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push( root );

    while ( !pendingNodes.empty() ) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << " : ";

        for ( int i = 0; i < front -> children.size(); i++ ) {

            if ( i < (( front -> children.size()) - 1 )) {
            
                cout << front -> children[i] -> data << ", ";
            
            } else {

                cout << front -> children[i] -> data;

            }

            pendingNodes.push( front -> children[i] );
        }

        cout << "\n";
    }

}

int main() {

    cout << endl;
    cout << " ****** Taking The Inputs ****** " << endl;
    cout << endl;

	TreeNode<int>* root = takeInputLevelWise();


    cout << endl;
    cout << " ****** Final Tree Structure After Taking The Inputs ****** " << endl;
    cout << endl;
    
    printTree( root );


    // To Do delete the Tree
}