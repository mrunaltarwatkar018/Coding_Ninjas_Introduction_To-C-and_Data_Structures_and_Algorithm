/*
    Graphs Terminology

        ●   Nodes are named as vertices, and the connections between them are called
            edges.

        ●   Two vertices are said to be adjacent if there exists a direct edge connecting
            them.

        ●   The degree of a node is defined as the number of edges that are incident to
            it.

        ●   A path is a collection of edges through which we can reach from one node to
            the other node in a graph.

        ●   A graph is said to be connected if there is a path between every pair of
            vertices.

        ●   If the graph is not connected, then all the connected subsets of the graphs
            are called connected components. Each component is connected within the
            self, but two different components of a graph are never connected.

        ●   The minimum number of edges in a graph can be zero, which means a graph
            could have no edges as well.

        ●   The minimum number of edges in a connected graph will be (n-1), where n is
            the number of nodes.

        ●   In a complete graph (where each node is connected to every other node by a
            direct edge), there are nC2 number of edges means (n * (n-1)) / 2 edges,
            where n is the number of nodes. It is the maximum number of edges that a
            graph can have. Hence, if an algorithm works on the terms of edges, let’s say
            O(E), where E is the number of edges, then in the worst case, the algorithm
            will take O(n2) time, where n is the number of nodes.
*/