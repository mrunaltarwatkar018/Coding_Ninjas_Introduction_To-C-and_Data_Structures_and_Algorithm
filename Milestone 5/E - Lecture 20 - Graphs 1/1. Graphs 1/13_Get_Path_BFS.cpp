
/*
        Get Path - BFS

        Approach: 
        It is the same problem as the above, just we have to code the same
        using BFS.

        Approach: 
        Using BFS will provide us the shortest path between the two vertices.
        We will use the queue over here and do the same until the end vertex 
        gets inserted into the queue. Here, the problem is how to figure out 
        the node, which led us to the end vertex. To overcome this, we will 
        be using a map. In the map, we will store the resultant node as the 
        index, and its key will be the node that led it into the queue.
        For example: If the graph was such that 0 was connected to 1 and 0 
        was connected to 2, and currently, we are on node 0 such that node 
        1 and node 2 are not visited.

        So our map will look like as follows:
                -----------------
                |   1   |   0   |
                -----------------
                |   2   |   0   |
                -----------------

        This way, as soon as we reach the end vertex, we can figure out the 
        nodes by running the loop until we reach the start vertex as the key 
        value of any node.

        Try to code it yourselves, and for the solution, refer to the specific 
        tab of the same.


*/