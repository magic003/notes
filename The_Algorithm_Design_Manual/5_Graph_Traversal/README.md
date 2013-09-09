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


