/*
        Time Complexity of Kruskal’s Algorithm:

        In our code, we have the following three steps: 
        (Here, the total number of vertices is n, and 
        the total number of edges is E)

        ●   Take input in the array of size E.
        
        ●   Sort the input array on the basis of edge-weight. 
            This step has the time complexity of O(E log(E)).
            
        ●   Pick (n-1) edges and put them in MST one-by-one. 
            Also, before adding the edge to the MST, we checked 
            for cycle detection for each edge. For cycle detection, 
            in the worst-case time complexity of E edges will be 
            O(E.n), as discussed earlier.

        Hence, the total time complexity of Kruskal’s algorithm becomes 
        O(E log(E) + n.E). This time complexity is bad and needs to be 
        improved. We can’t reduce the time taken for sorting, but the 
        time taken for cycle detection can be improved using another 
        algorithm named ​Union by Rank and Path Compression​. You need 
        to explore this on yourselves. The basic idea in these algorithms 
        is that we will be avoiding the formation of skewed-tree structure, 
        which reduces the time complexity for each vertex to O(log(E)).

*/