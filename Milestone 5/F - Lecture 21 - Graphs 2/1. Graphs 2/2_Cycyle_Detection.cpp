/*
        Cycle Detection

        While inserting a new edge in the MST, we have to check if 
        introducing that edge makes the MST cyclic or not. If not, 
        then we can include that edge, otherwise not.

        Now, let’s figure out a way to detect the cycle in a graph. 
        The following are the possible cases:

        ●   By including an edge between the nodes A and B, if both 
            the nodes A and B are not present in the graph, then it 
            is safe to include that edge as including it, will not 
            bring a cycle to the graph.
        ●   Out of two vertices, if anyone of them has not been visited 
            (or not present in the MST), then that vertex can also be 
            included in the MST.
        ●   If both the vertices are already present in the graph, 
            they can introduce a cycle in the MST. It means we can’t 
            use this method to detect the presence of the cycle.

        Let’s think of a better approach. We have already solved the ​
        hasPath ​question in the previous module, which returns true 
        if there is a path present between two vertices v1 and v2, 
        otherwise false.

        Now, before adding an edge to the MST, we will check if a 
        path between two vertices of that edge already exists in 
        the MST or not. If not, then it is safe to add that edge 
        to the MST.

        As discussed in previous lectures, the time complexity of 
        the ​hasPath ​function is O(E+V), where E is the number of 
        edges in the graph and, V is the number of vertices. So, 
        for (n-1) edges, this function will run (n-1) times, leading 
        to bad time complexity, as in the worst case, E = V​^2.

        Now, moving on to a better approach for cycle detection in 
        the graph.

*/