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

