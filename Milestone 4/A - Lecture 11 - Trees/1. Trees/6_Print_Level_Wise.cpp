/* =================================================================================================================== */
/* 
    Question  : Print Level Wise
                
                Given a generic tree, print the input tree in level wise order.

                For printing a node with data N, you need to follow the exact format -

                Input format : 
                                The first line of input contains data of the nodes of 
                                the tree in level order form. The order is: data for root 
                                node, number of children to root node, data of each of 
                                child nodes and so on and so forth for each node. The 
                                data of the nodes of the tree is separated by space.

                Output Format : 
                                The first and only line of output contains the elements 
                                of the tree in level wise order, as described in the 
                                task.

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    10 3 20 30 40 2 40 50 0 0 0 0  
                                        
                Sample Output 1 :   
                                    10:20,30,40
                                    20:40,50
                                    30:
                                    40:
                                    40:
                                    50:
                                
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}


void printLevelWise(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL) {
        return;
    }

    queue<TreeNode<int> *> q;
    q.push( root );
    while ( q.size() != 0 ) {

        TreeNode<int> *front = q.front();
        q.pop();
        cout << front -> data << ":";

        for (int i = 0; i < front -> children.size(); i++) {

            if (i == 0) {

                cout << front->children[i]->data;

            } else {

                cout << "," << front->children[i]->data;

            }

            q.push(front->children[i]);

        }

        cout << "\n";

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

    printLevelWise(root);

    cout << endl << endl;

    printLevelWisee( root );


}