/*
Return all connected components

Problem statement: Given an undirected graph G(V, E), find and 
print all the connected components of the given graph G. V is 
the number of vertices present in graph G, and vertices are 
numbered from 0 to V-1. E is the number of edges present in 
graph G.

You need to take input in the main and create a function that 
should return all the connected components. And then print them 
in the main, not inside a function.

Print different components in a new line. And each component 
should be printed in increasing order (separated by space). 
The order of different components doesn't matter.

Example: 

    Suppose the given input is:
            4 3
            0 1
            1 3
            0 3

    The output should be:
            0 1 3
            2

Explanation:  
        As we can see that {0, 1, 3} is one connected component, 
        and {2} is the other one. So, according to the question, 
        we just have to print the same.

Approach: 
        For this problem, start from vertex 0 and traverse until 
        vertex n-1. If the vertex is not visited, then run DFS/BFS 
        on it and keep track of all the connected vertices through 
        that node. This way, we will get all the distinct connected 
        components, and we can print them at last.

    This problem is left for you to solve. For the code, refer to the 
    solution tab of the same.

*/