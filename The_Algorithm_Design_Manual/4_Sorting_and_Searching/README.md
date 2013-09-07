Sorting and Searching
=====================

4.1 Applications of Sorting
---------------------------

The punch-line is: clever sorting alogrithms exist that run in __O(nlogn)__.

Sorting lies at the heart of many algorithms. Sorting the data is one of the first things any algorithm designer should try in the quest for efficiency.

4.3 Heapsort: Fast Sorting via Data Structures
----------------------------------------------

The time complexity of __Selection sort__ is O(n<sup>2</sup>).

If we use a better priority queue implementation, operations that find the smallest element take O(logn) each, instead of O(n). So it speeds up selection sort from O(n<sup>2</sup>) to O(nlogn).

Heapsort runs in worst-case O(nlogn) time. It is an in-place sort.

### 4.3.4 Faster Heap Construction

A heap can be constructed on _n_ elements by incremental insertion in _O(nlogn)_ time. It can be constructed in _O(n)_ time using buble_down procedure.

### 4.3.5 Sorting by Incremental Insertion

The faster sorting algorithms based on incremental insertion follow more efficient data structures. Insertion into a balanced search tree take O(logn) per operation, or a total of O(nlogn) to construct the tree. An in order travesal reads through the elements in sorted order to complete the job in linear time.

4.5 Mergesort: Sorting by Divide-and-Conquer
--------------------------------------------

Mergesort takes O(nlogn) time in the worst case.

Mergesort is a great algorithm for sorting linked lists, because it does not rely on random access to elements as does heapsort or quicksort. Its primary disadvantage is the need for an auxillary buffer when sorting arrays.

4.6 Quicksort: Sorting by Randomization
---------------------------------------

The worst case for quicksort is worse than heapsort or mergesort. Quicksort had better be good in average case.

### 4.6.2 Randomized Algorithms

Randomized quicksort runs in &Theta;(nlogn) time on any input, with high probability.

Randomization is a powerful tool to improve algorithms with bad worst-case but good average-case complexity.

### 4.6.3 Is Quicksort Really Quick?

Where a properly implemented quicksort is implemented well, it is typically 2-3 times faster than mergesort or heapsort.

4.7 Distribution Sort: Sorting via Bucketing
--------------------------------------------

### 4.7.1 Lower Bounds for Sorting

An &Omega;(nlogn) lower bound can be shown by observing that any sorting algorithm must behave differently during execution on each of the distinct n! permutations of n keys. The outcome of each pairwise comparison governs the run-time behavior of any comparison-based sorting algorithm. We can think of the set of all possible executions of such an algorithm as a tree with n! leaves. The minimum height tree corresponds to the fastest possible algorithm, and it happens that lg(n!) = &Theta;(nlogn).

4.9 Binary Search and Related Algorithms
----------------------------------------

### 4.9.1 Counting Occurrences

### 4.9.2 One-Sided Binary Search

One-sided binary search is most useful whenever we are looking for a key that lies close to our current position.

### 4.9.3 Square and Other Roots

4.10 Divide-and-Conquer
-----------------------

Two important algorithm design paradigms are based on breaking problems down into smaller problems:    
* Dynamic programming typically removes one element from the problem, solves the smaller problem, and then uses the solution to this smaller problem to add back the element in the proper way.
* Divide-and-conquer instead splits the problem in halves, solves each half, then stitches the pieces back together to form a full solution.
