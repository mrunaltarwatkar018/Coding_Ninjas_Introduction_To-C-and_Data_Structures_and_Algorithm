/*
    Time Complexity of Prim’s Algorithm:

    Here, n is the number of vertices, and E is the number of edges.

    ●   The time complexity for finding the minimum weighted vertex is 
        O(n) for each iteration. So for (n-1) edges, it becomes O(n^​2).

    ●   Similarly, for exploring the neighbor vertices, the time taken 
        is O(n​^2).

    It means the time complexity of Prim’s algorithm is O(n​^2). We can 
    improve this in the following ways:

    ●   For exploring neighbors, we are required to visit each and every 
        vertex because of the adjacency matrix. We can improve this by 
        using an adjacency list instead of a matrix.

    ●   Now, the second important thing is the time taken to find the 
        minimum weight vertex, which is also taking a time of O(n​^2). 
        Here, out of the available list, we are trying to figure out 
        the one with minimum weight. This can be optimally achieved 
        using a ​priority queue​ where the priority will be taken as 
        weights of the vertices. This will take O(log(n)) time complexity 
        to remove a vertex from the priority queue.

    These optimizations can lead us to the time complexity of 
    O((n+E)log(n)), which is much better than the earlier one. 
    Try to write the optimized code by yourself.


*/