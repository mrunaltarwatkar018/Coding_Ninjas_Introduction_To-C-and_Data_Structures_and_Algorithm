#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int> * findNode(BinaryTreeNode<int>* root, int data) {
    if (root == NULL) {
        return false;
    }
    
    if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return findNode(root->left, data);
    } else {
        return findNode(root->right, data);
    }
}

void printBetweenK1K2 ( BinaryTreeNode<int> * root, int k1, int k2 ) {
    if (root == NULL) {
        return;
    }

    if ( root -> data >= k1 && root -> data <= k2 ) {
        cout << root -> data << endl;
    }

    if ( root -> data > k1 ) {
        printBetweenK1K2(root -> left, k1, k2);
    }

    if ( root -> data <= k2 ) {
        printBetweenK1K2( root -> right, k1, k2);
    }
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    printBetweenK1K2(root, 2, 6);
    BinaryTreeNode<int> * search = findNode(root, 3);
    cout << search -> data << endl;
    delete root;
}