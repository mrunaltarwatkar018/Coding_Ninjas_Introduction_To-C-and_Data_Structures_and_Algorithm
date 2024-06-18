/*
        Is connected?

        Problem statement: 
        Given an undirected graph G(V, E), check if the graph G is a
        connected graph or not. V is the number of vertices present 
        in graph G, and vertices are numbered from 0 to V-1. E is 
        the number of edges present in graph G.


                0               2               0               2
                |               |               |               |
                |               |               |               |
                |               |  4            |               |  4
                |               | /             |               |
                |               |/              |               |
                1 ------------- 3               1 ------------- 3

                Connected Graph                 Unconnectd Graph

        Example 1: 

        Suppose the given input is:
                    4 4
                    0 1
                    0 3
                    1 2
                    2 3
                    1 3

        The output should be: 
                    true

        Explanation: As the graph is connected, so according to the 
        question, the answer will be true.

        Example 2: 
        
        Suppose the given input is:
                    4 3
                    0 1
                    1 3
                    0 3

        The output should be: false

        Explanation: 
                The graph is not connected, even though vertices 0,1 
                and 3 are connected to each other, but there isn’t any 
                path from vertices 0,1,3 to vertex 2. Hence, according 
                to the question, the answer will be false.

        Approach: 
                This is very start-forward. Take any vertex as the 
                starting vertex as traverse the graph using either 
                DFS or BFS. In the end, check if all the vertices 
                are visited or not. If not, it means that the node 
                was not connected to the starting vertex, which means 
                it is a disconnected graph. Otherwise, it is a connected 
                graph. Try to code it yourselves, and for the code, refer 
                to the solution tab of the same.

                

*/