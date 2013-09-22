Weighted Graph Algorithms
=========================

6.1 Minimum Spanning Trees
--------------------------

A spanning tree of a graph G = (V, E) is a subset of edges from E forming a tree connecting all vertices of V.   

The minimum spanning tree is the spanning tree whose sum of edge weights is as small as possible.   

There can be more than one minimum spanning tree in a graph.

### 6.1.1 Prim's Algorithm

The complexity can be O(m + nlgn) if a priority-queue data structure is used.

### 6.1.2 Kruskal's Algorithm

Kruskal's algorithm is an alternate approach to find minimum spanning trees that proves more efficent on **sparse** graphs.

It runs in O(mlgm) time if the union-find data structure is used.

### 6.1.3 The Union-Find Data Structure

Both unions and finds are in O(logn).

### 6.1.4 Variations on Minimum Spanning Trees

6.3 Shortest Paths
------------------

### 6.3.1 Dijkstra's Algorithm

The complexity is O(n<sup>2</sup>).

Dijkstra works correctly only on graphs without negative-cost edges.

### 6.3.2 All-Pairs Shortest Path

The Floyd-Warshall all-pairs shortest path runs in O(n<sup>3</sup>) time.

### 6.3.3 Transitive Closure

