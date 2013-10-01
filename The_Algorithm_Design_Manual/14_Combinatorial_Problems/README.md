Combinatorial Problems
======================

14.1 Sorting
------------

The simplest approach to external sorting loads the data into a B-tree and then does an in-order traversal of the tree to read the keys off in sorted order. Real high-performance sorting algorithms are based on multiway-mergesort.

The best general-purpose internal sorting algorithm is quicksort.

14.2 Searching
--------------

Two basic approaches are __sequential__ search and __binary search__. 

A sequential search is the simplest algorithm, and likely to be fastest on up to about 20 elements. Beyond 100 elements, binary search will clearly be more efficient.

14.3 Median and Selection
-------------------------

14.4 Generating Permutations
----------------------------

There are two different paradigms for constructing permutations: ranking/unranking and incremental change methods. The latter are more efficient.

14.5 Generating Subsets
-----------------------

There are three primary alternative:

* Lexicographic order
* Gray code
* Binary counting

The best way to construct all k-subsets is in lexicographic order.

14.6 Generating Partitions
--------------------------

The easiest way to generate integer partitions is to construct them in lexicographically decreasing order.

14.7 Generating Graphs
----------------------

There are three primary models of random graphs:

* Random edge generation
* Random edge selection
* Preferential attachment


