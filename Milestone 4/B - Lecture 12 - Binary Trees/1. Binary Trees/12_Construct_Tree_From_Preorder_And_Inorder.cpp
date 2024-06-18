/*
    Construct a binary tree from preorder and inorder traversal

        Consider the following example to understand this better-

        Input   :
            Inorder traversal : {4, 2, 1, 7, 5, 8, 3, 6}
            Preorder traversal : {1, 2, 4, 3, 5, 7, 8, 6}

        Output: Below binary tree…

                                1
                              /   \
                             2      3
                           /       /   \
                          4       5      6
                                /   \
                               7      8



        The idea is to start with the root node, which would be the first item in the preorder
        sequence and find the boundary of its left and right subtree in the inorder array.
        Now all keys before the root node in the inorder array become part of the left
        subtree, and all the indices after the root node become part of the right subtree.
        We repeat this recursively for all nodes in the tree and construct the tree in the
        process.

        To illustrate, consider below inorder and preorder sequence -

        Inorder: {4, 2, 1, 7, 5, 8, 3, 6}

        Preorder: {1, 2, 4, 3, 5, 7, 8, 6}

        The root will be the first element in the preorder sequence, i.e. 1. Next, we locate
        the index of the root node in the inorder sequence. Since 1 is the root node, all
        nodes before 1 must be included in the left subtree, i.e., {4, 2}, and all the nodes
        after one must be included in the right subtree, i.e. {7, 5, 8, 3, 6}. Now the problem
        is reduced to building the left and right subtrees and linking them to the root node.

        Left subtree    :                   Right subtree   :

        Inorder : {4, 2}                    Inorder : {7, 5, 8, 3, 6}

        Preorder : {2, 4}                   Preorder : {3, 5, 7, 8, 6}

        Follow the above approach until the complete tree is constructed. Now let us look
        at the code for this problem:


        BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
            if (inS > inE) {            // Base case
                return NULL;
            }

            int rootData = pre[preS]; // Root’s data will be first element of the preorder array
            int rootIndex = -1; // initialised root’s index to -1 and searched for it’s value
            for (int i = inS; i <= inE; i++) { // in inorder list
                if (in[i] == rootData) {
                    rootIndex = i;
                    break;
                }
            }

            // Initializing the left subtree’s indices for recursive call

            int lInS = inS;
            int lInE = rootIndex - 1;
            int lPreS = preS + 1;
            int lPreE = lInE - lInS + lPreS;

            // Initializing the right subtree’s indices for recursive call

            int rPreS = lPreE + 1;
            int rPreE = preE;
            int rInS = rootIndex + 1;
            int rInE = inE;

            // Recursive calls follows

            BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

            root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE); // over left subtree
            root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE); // over right subtree
            return root; // finally returned the root
        }


        BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) { 
            // this is the function called
            // from the main() with inorder and preorder traversals in the form of arrays and their
            // size which is obviously same for both

            return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1); 
            
            // These arguments are of the
            // form (inorder_array, preorder_array, inorder_start, inorder_end, preorder_start,
            // preorder_end) in the helper function for the same written above.
        }

        Now, try to construct the binary tree when inorder and postorder traversals are
        given…

*/




