/* =================================================================================================================== */
/* 
    Question  : Node with maximum child sum
                
                Given a generic tree, find and return the node for which 
                sum of its data and data of all its child nodes is maximum. 
                In the sum, data of the node and data of its immediate child 
                nodes has to be taken.

                Input format : 
                                The first line of input contains data of the nodes 
                                of the tree in level order form. The order is: data 
                                for root node, number of children to root node, 
                                data of each of child nodes and so on and so forth 
                                for each node. The data of the nodes of the tree is 
                                separated by space. 

                Output Format : 
                                The first and only line of output contains the data 
                                of the node with maximum sum, as described in the task.

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
                                          
                Sample Output 1 :   
                                    1
                                   
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

template <typename T>

class MaxNodePair {
    public :
        TreeNode<T> *node;
        int sum;
};

MaxNodePair<int> *maxSumNodeHelper(TreeNode<int> *root) {

    if (root == NULL) {
        MaxNodePair<int> *pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }

    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++) {

        sum += root -> children[i] -> data;

    }

    MaxNodePair<int> *ans = new MaxNodePair<int>();
    ans->node = root;
    ans->sum = sum;

    for (int i = 0; i < root->children.size(); i++) {

        MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]);

        if (childAns->sum > ans->sum) {
            ans = childAns;
        }
    }

    return ans;

}
    
TreeNode<int> *maxSumNode(TreeNode<int> *root) {

    return maxSumNodeHelper(root)->node;
    
}

// Another Approach

/*
void maxSum(TreeNode<int> *root, TreeNode<int> **maxNode, int *max)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
        sum += root->children[i]->data;
    if (sum > *max)
    {
        *max = sum;
        *maxNode = root;
    }
    for (int i = 0; i < root->children.size(); i++)
        maxSum(root->children[i], maxNode, max);
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    TreeNode<int> *maxNode;
    int max = 0;
    maxSum(root, &maxNode, &max);
    return maxNode;
}
*/

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}