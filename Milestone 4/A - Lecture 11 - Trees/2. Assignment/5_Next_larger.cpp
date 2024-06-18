/* =================================================================================================================== */
/* 
    Question  : Next Larger
                
                Given a generic tree and an integer n. Find and return the 
                node with next larger element in the tree i.e. find a node 
                with value just greater than n.

                Note: Return NULL if no node is present with the value greater than n.

                Input format : 
                                The first line of input contains data of the nodes of 
                                the tree in level order form. The order is: data for 
                                root node, number of children to root node, data of 
                                each of child nodes and so on and so forth for each 
                                node. The data of the nodes of the tree is separated 
                                by space.  
                                The following line contains an integer, that denotes the 
                                value of n.

                Output Format : 
                                The first and only line of output contains data of the node, 
                                whose data is just greater than n.

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    10 3 20 30 40 2 40 50 0 0 0 0 
                                    18 
                                          
                Sample Output 1 :   
                                    20

                Sample Input 2 :    
                                    10 3 20 30 40 2 40 50 0 0 0 0 
                                    21 
                                          
                Sample Output 2 :   
                                    30
                                   
*/


#include <iostream>
#include <queue>
#include <vector>
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

/*
    Time complexity : O(N)
    Space Complexity : O(H)

    where N is the number of nodes in the tree and 
    H is the height/depth of the tree
*/

#include <climits>

TreeNode<int> *getNextLargerElement( TreeNode<int> *root, int n ) {
    if ( root == NULL ) {
        return root;
    }

    bool flag = false;

    TreeNode<int> *nextLarger = NULL;

    if ( root -> data > n ) {
        flag = true;
        nextLarger = root;
    }


    for ( int i = 0; i < root -> children.size(); i++ ) {

        TreeNode<int> *temp = getNextLargerElement( root -> children[i], n );

        if ( nextLarger == NULL ) {
            nextLarger = temp;
        } else if ( temp != NULL && temp -> data < nextLarger -> data ) {
            flag = true;
            nextLarger = temp;
        }
    }

    return nextLarger;
}


/*
// Another Approach
#include <climits>
void getNextLarger(TreeNode<int> *root, TreeNode<int> **nextLarger, int *num, int x)
{
    if (root->data > x && root->data <= *num)
    {
        *num = root->data;
        *nextLarger = root;
    }
    for (int i = 0; i < root->children.size(); i++)
        getNextLarger(root->children[i], nextLarger, num, x);
}
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    TreeNode<int> *nextLarger;
    int num = INT_MAX;
    getNextLarger(root, &nextLarger, &num, x);
    return nextLarger;
}
*/

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}