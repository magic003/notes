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
