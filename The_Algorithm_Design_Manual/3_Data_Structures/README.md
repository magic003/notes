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
