Data Structures
===============

3.1 Contiguous vs. Linked Data Structures
-----------------------------------------

__Contiguously-allocated structures__ are composed of single slabs of memory, and include arrays, matrices, heaps and hash tables.

__Linked data structures__ are composed of distinct chunks of memory bound together pointers, and include lists, trees and graph adjancency lists.

### 3.1.1 Arrays

Advantages of contiguously-allocated arrays include:
* Constant time access given the index
* Space efficiency
* Memory locality

The downside of arrays is that we cannot adjust their size in the middle of program's execution. Use __dynamic arrays__.

### 3.1.3 Comparison

The relative advantages of linked lists over static arrays include:
* Overflow on linked structures can never occur unless the memory is actually full.
* Insertions and deletions are simpler than for contiguous(array) lists.
* With large records, moving pointers is easier and faster than moving the items themselves.

The relative advantages of arrays include:
* Linked structures require extra space for storing pointer fields.
* Linked lists do not allow efficient random access to items.
* Arrays allow better memory locality and cache performance than random pointer jumping.

3.2 Stacks and Queues
---------------------

Stacks and queues can be effectively implemented using either arrays or linked lists. The key issue is whether an upper bound on the size is known in advance.

3.4 Binary Search Trees
-----------------------

A binary search tree labels each node in a binary tree with a single key such that for any node labeled _x_, all nodes in the left subtree of _x_ have keys < _x_ while all nodes in the right subtree of _x_ have keys > _x_. For any binary tree on _n_ nodes, and any set of _n_ keys, there is __exactly__ one labeling that makes it a binary search tree.

### 3.4.2 How Good Are Binary Search Trees?

The shape (and more importantly height) of the tree is a function of the order in which we insert the keys. If the keys are inserted in sorted order, it will produce a linear height tree.

On average, the height is O(logn).

3.7 Hashing and Strings
-----------------------

### 3.7.1 Collision Resolution

Chaining is the easiest approach to collision resolution.

The alternative is open addressing.

### 3.7.2 Efficient String Matching via Hashing

Rabin-Karp algorithm for Substring Pattern Matching problem.

### 3.7.3 Duplicate Detection via Hashing

The key idea of hashing is to represent a large object using a single number.

3.8 Specialized Data Structures
-------------------------------

* String data structures: character strings are typically represented by arrays of characters, perhaps with a special character to mark the end of the string.
* Geometric data structures: geometric data typically consists of collections of data points and regions.
* Graph data structures: graphs are typically represented using either adjacency matrices or adjacency lists.
* Set data structures: subsets of items are typically represented using a dictionary to support fast membership queries. Alternately, bit vectors are boolean arrays such that the ith bit represents true if i is in the subset.
