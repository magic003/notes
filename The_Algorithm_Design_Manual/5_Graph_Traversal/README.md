Graph Traversal
===============

A graph G = (V, E) consists of a set of vertices V together with a set E of vertex pairs or edges.

5.1 Flavors of Graphs
---------------------

* Undirected vs. Directed: A graph G = (V,E) is undirected if edge (x,y) &isin; E implies that (y,x) is also in E. If not, it is directed.
* Weighted vs. Unweighted: Each edge (or vertex) in a weighted graph G is assigned a numerical value, or weight. In unweighted graphs, there is no cost distinction between various edges and vertices.
* Simple vs. Non-simple: Graphs that avoid self-loop and multiedge are called simple.
* Sparse vs. Dense: Graphs are sparse when only a small fraction of the possible vertex pairs actually have edges defined between them. Graphs where a large fraction of the vertex pairs define edges are called dense.
* Cyclic vs. Acyclic: An acyclic graph does not contain any cycles. Directed acyclic graphs are calls DAGs.
* Embedded vs. Topological: A graph is embedded if the vertices and edges are assigned geometric positions.
* Implicit vs. Explicit: Certain graphs are not explicitly constructed and then traversed, but built as we use them.
* Labeled vs Unlabeled: Each vertex is assigned a unique name or identifier in a labeled graph to distinguish it from all other vertices. In unlabeled graphs, no such distinctions have been made.

5.2 Data Strucutures for Graphs
-------------------------------

* Adjacency Matrix: We can represent G using an n &times; n matrix M, where element M[i,j] = 1 if (i,j) is an edge of G, and 0 if it isn't. This allows fast answers to the question "is (i,j) in G?", and rapid updates for edge insertion and deletion.
* Adjacency Lists: We can more efficiently represent sparse graphs by using linked lists to store the neighbors adjacent to each vertex. Adjacency lists are the right data structure for most applications of graphs.

5.5 Traversing a Graph
----------------------

Each vertex will exist in one of three states:
* undiscovered - the vertex is in its initial, virgin state.
* discovered - the vertex has been found but we have not yet checked out all its incident edges.
* processed - the vertex after we have visited all its incident edges.

5.6 Breadth-First Search
------------------------

There are two points to remember when using breadth-first search to find a shortest path from x to y:
1. the shortest path tree is only useful if BFS was performed with x as the root of the search.
2. BFS gives the shortest path only if the graph is unweighted.

5.8 Depth-First Search
----------------------

BFS uses **Queue** to store the discovered vertices, while DFS uses **Stack**.

DFS partitions the edges of an undirected graph into exactly two classes: tree edges and back edges. All edges fall into these two classes.

DFS organizes vertices by entry/exit times, and edges into tree and back edges. This organization is what gives DFS its real power.

5.10 Depth-First Search on Directed Graphs
------------------------------------------

### 5.10.1 Topological Sorting

### 5.10.2 Strongly Connected Components

The graph is strongly connect iff all verices in G can (1) reach v and (2) are reachable from v.
