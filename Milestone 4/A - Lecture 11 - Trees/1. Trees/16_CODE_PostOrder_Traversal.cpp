/* =================================================================================================================== */
/* 
    Question  : Code : PostOrder Traversal
                
                Given a generic tree, print the post-order traversal of 
                given tree.
                
                The post-order traversal is: visit child nodes first and 
                then root node.

                Input format : 
                                The first line of input contains data of 
                                the nodes of the tree in level order form. 
                                The order is: data for root node, number of 
                                children to root node, data of each of child 
                                nodes and so on and so forth for each node. 
                                The data of the nodes of the tree is separated 
                                by space.     

                Output Format : 
                                The first and only line of output contains the 
                                elements printed in post-order traversal. The 
                                elements in the output must be separated by a 
                                single space.

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    10 3 20 30 40 2 400 50 0 0 0 0    
                                        
                Sample Output 1 :   
                                    400 50 20 30 40 10
                                
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

// One Method
// void printPostOrder(TreeNode<int> *root)
// {
//     // Write your code here
//     if (root == NULL)
//         return;
//     for (int i = 0; i < root->children.size(); i++)
//         printPostOrder(root->children[i]);
//     cout << root->data << " ";
// }

// Another Method

/*
    Time complexity: O(N)
    Space complexity: O(H)
    where N is the number of nodes in the tree and
    H is the height/depth of the tree
*/

void printPostOrder(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < root -> children.size(); i++) {
        printPostOrder(root -> children[i]);
    }
    
    cout << root->data << " ";
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printPostOrder(root);
}




// Post-order traversal printing the tree (i.e. the root is going to say that first print the children and then me also )



/*
    In postorder traversal, we visit all the child nodes first (from left to right order) and
    then we visit the current node. You will be coding this yourself (very similar to
    preorder traversal) and for solution, refer the solution tab in the corresponding
    questions.
*/