# Graph Problems: Polynomial-Time

## 15.1 Connected Components

Testing the connectivity of any undirected graph is a job for either depth-first or breadth-first search.

## 15.2 Topological Sorting

Three important facts about topological sorting are:    
1. Only DAGs can be topologically sorted.
2. Every DAG can be topologically sorted.
3. DAGs can often be topologically sorted in many different ways, especially when there are few constraints.

## 15.3 Minimum Spanning Tree

* Kruskal's algorithm
* Prim's algorithm
* Boruvka's algorithm

Prim's algorithm runs in O(n<sup>2</sup>), while Kruskal's algorithm takes O(mlogm) time. Thus Prim's alogirhm is faster on dense graphs, while Kruskal's is faster on sparse graphs.

Prim's algorithm can be implemented in O(m+nlgn) time using more advanced data structures, and a Prim's implementation using pairing heaps would be the fastest practical choice for both sparse and dense graphs.

## 15.4 Shortest Path

Dijkstra's algorithm assumes that all edges have positive cost. For graphs with edges of negative weight, you must use the more general but less efficient, Bellman-Ford algorithm.

The Floyd-Warshall algorithm is a slick O(n<sup>3</sup>) dynamic programming algorithm for all-pairs shortest path, which is faster and easier to program than Dijkstra.

## 15.5 Transitive Closure and Reduction

## 15.6 Matching

