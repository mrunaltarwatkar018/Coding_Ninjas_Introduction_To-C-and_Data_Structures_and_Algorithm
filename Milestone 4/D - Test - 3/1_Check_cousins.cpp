/* =================================================================================================================== */
/* 
    Question  : Check cousins
                
                Given the binary Tree and two nodes say ‘p’ and ‘q’. 
                Determine whether the two nodes are cousins of each 
                other or not. Two nodes are said to be cousins of 
                each other if they are at same level of the Binary 
                Tree and have different parents.
                
                Do it in O(n).


                Input format : 
                        Line 1 : Nodes in level order form (separated by space). 
                                If any node does not have left or right child, 
                                take -1 in its place
                        Line 2 : integer value of p 
                        Line 3 : Integer value of q

                Output Format : 
                                true or false

                Constraints :   
                                1 <= N <= 10^5

                Sample Input 1 :    
                                    5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
                                    2
                                    4
                                          
                Sample Output 1 :   
                                    true
*/


#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}


// One way to solve

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

// Check cousins
// bool areSiblings(BinaryTreeNode<int>* root,int p, int q){
//     if(root==NULL) {
//         return false;
//     }

//     if(root->left && root->right) {
//         if((root->left->data==p && root->right->data==q) || (root->left->data==q && root->right->data==p)) {
//             return true;
//         }
//     }

//     return areSiblings(root->left,p,q) || areSiblings(root->right,p,q);
// }

// int getLevel(BinaryTreeNode<int>* root,int x){
//     if(root==NULL){
//         return -1;
//     }
//     if(root->data==x){
//         return 0;
//     }
//     int leftOutput=getLevel(root->left,x);
//     int rightOutput=getLevel(root->right,x);
//     if(leftOutput!=-1){
//         return 1+leftOutput;
//     }
//     else if(rightOutput!=-1){
//         return 1+rightOutput;
//     }
//     else{
//         return -1;
//     }
    
// }

// bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
//     // Write your code here
//     if(getLevel(root,p)==getLevel(root,q) && !(areSiblings(root,p,q))){
//         return true;
//     }
//     else{
//         return false;
//     }

// }


// Another Method
int depth(BinaryTreeNode<int> *root, int node){
    if(root == NULL)
        return -1;
    if(node == root->data)
        return 0;
    int left = depth(root->left, node);
    if(left != -1)
        return left + 1;
    else {
    int right = depth(root->right, node);
        if(right != -1)
            return right + 1;
        else
            return -1;
    }
}

bool isSibling(BinaryTreeNode<int> *root, int p, int q){
    if(root==NULL)
        return false;
    if(root -> left!=NULL && root -> right !=NULL){
        if(root->left->data == p && root->right->data == q)
            return true;
        else if(root->left->data == q && root->right->data == p)
            return true;
        else
            return isSibling(root->left, p, q) || isSibling(root->right, p, q);
    }
    if(root->right != NULL)
        return isSibling(root->right, p, q);
    else
        return isSibling(root->left, p, q);
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if(root==NULL)
        return false;
    return ((depth(root, p) == depth(root, q)) && (!isSibling(root, p, q)));
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}
