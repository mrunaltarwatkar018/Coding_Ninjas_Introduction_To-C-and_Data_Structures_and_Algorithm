/*

        Time Complexity of All Operations in BST 

        1. For comparison == O(h)  where h = height

        2. For insertion = O(h)  where h = height

        3. For deletion = O(h)  where h = height

                (d + d' + d') < 2h 
                        where 
                            d = d work to find the node
                            d' + d' = to find the minimum and then to delete the minimum

            Therefore, For deletion = O(h)  where h = height



        4.  For balanced Tree (BST)
                    For every Node
                            | height of node's left subTree - height of node's right subTree | <= 1
                        i.e.    | h(node's left subTree) - h(node's right subTree) | <= 1


        5.  We want BST should be BALANCED
                because Height for a Balanced Tree is O(logN)

                    i.e. For Balanced BST -> SEARCH, INSERTION, DELETION is O(logN)


        6.  For maintaing Balanced Tree i.e. BST, 
                we have many Types of BAlanced BST
                            1.  AVL Tree  ( Recommanded )  ( in short, using rotation we have to make a balanced tree )
                            2.  RED Balanced Tree
                            3.  2-4 Tree

*/