
/*
        Get Path - DFS

        Problem statement: 
        Given an undirected graph G(V, E) and two vertices v1 and
        v2(as integers), find and print the path from v1 to v2 (if exists). 
        Print nothing if there is no path between v1 and v2.

        Find the path using DFS and print the first path that you encountered 
        irrespective of the length of the path.

        V is the number of vertices present in graph G, and vertices are 
        numbered from 0 to V-1.

        E is the number of edges present in graph G.

        Print the path in reverse order. That is, print v2 first, then 
        intermediate vertices and v1 at last.

        Example: Suppose the given input is:
                    4 4
                    0 1
                    0 3
                    1 2
                    2 3
                    1 3
                
                The output should be: 
                    3 0 1

                Explanation: 
                    Here, v1 = 1 and v2 = 3. The connected vertex pairs are (0, 1), (0, 3), 
                    (1, 2) and (2, 3). So, according to the question, we have to print the 
                    path from vertex v1 to v2 in reverse order using DFS only; hence the 
                    path comes out to be {3, 0, 1}.

                Approach: 
                    We have to solve this problem by using DFS. Suppose, if the start and
                    end vertex are the same, then we simply need to put the start in the 
                    solution array and return the solution array. If this is not the case, 
                    then from the start vertex, we will call DFS on the direct connections 
                    of the same. If none of the paths leads to the end vertex, then we do 
                    not need to push the start vertex as it is neither directly nor indirectly 
                    connected to the end vertex, hence we will simply return NULL. In case
                    any of the neighbors return a non-null entry, it means that we have a path 
                    from that neighbor to the end vertex, hence we can now insert the start 
                    vertex into the solution array.
                    
                    Try to code it yourself, and for the answer, refer to the solution tab of 
                    the same.



*/