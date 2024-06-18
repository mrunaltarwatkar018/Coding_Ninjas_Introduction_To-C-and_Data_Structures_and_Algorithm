
/*  BFS : Breadth First Seacrh */

/*
        Breadth-first search(BFS) is an algorithm where we start from the selected node
        and traverse the graph level-wise or layer-wise, thus exploring the neighbor nodes
        (which are directly connected to the starting node), and then moving on to the next
        level neighbor nodes.

        As the name suggests:
        ●   We first move horizontally and visit all the nodes of the current layer.
        ●   Then move to the next layer.


     Layer 0        0       Source Node
                  / |  \
                /   |   \
              /     |    \
             1      2     3     Layer 1
           /  \     | \    \
          /    \    |   \   \
         /      \   |     \  \
        4       5   6       7   Layer 2

        This is an iterative approach. We will use the queue data structure to store the child
        nodes of the current node and then pop out the current node. This process will
        continue until we have covered all the nodes. Remember to put only those nodes in
        the queue which have not been visited.

*/

/*

        GRaph :

                    0
                  /   \
                 1     2
               /   \    \
              3     4   6
               \   /  /
                \ /  /
                 5 --

            BFS Order : 0 1 2 3 4 6 5
*/