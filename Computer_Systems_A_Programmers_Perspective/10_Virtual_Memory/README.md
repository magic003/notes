Virtual Memory
==============

10.1 Physical and Virtual Addressing
------------------------------------

10.2 Address Spaces
-------------------

10.3 VM as a Tool for Caching
-----------------------------

VM systems handle this by partitioning the virtual memory into fixed-sized blocks called __virtual pages__. Similarly, physical memory is partitioned into __physical pages__. It is the same size as virtual pages.

The set of virtual pages is partitioned into three disjoint subsets:
* Unallocated: Pages that have not yet been allocated by the VM system.
* Cached: Allocated pages that are currently cached in physical memory.
* Uncached: Allocated pages that are not cached in physical memory.

### 10.3.1 DRAM Cache Organization

### 10.3.2 Page Tables

A __page table__ maps virtual pages to physical pages.

### 10.3.3 Page Hits

### 10.3.4 Page Faults

### 10.3.5 Allocating Pages

### 10.3.6 Locality to the Rescue Again

10.4 VM as a Tool for Memory Management
---------------------------------------

### 10.4.1 Simplifying Linking

### 10.4.2 Simplifying Sharing

### 10.4.3 Simplifying Memory Allocation

### 10.4.4 Simplifying Loading

10.5 VM as a Tool for Memory Protection
---------------------------------------

10.6 Address Translation
------------------------

### 10.6.1 Integrating Caches and VM

### 10.6.2 Speeding up Address Translation with a TLB

### 10.6.3 Multi-level Page Tables

### 10.6.4 Putting it Together: End-to-end Address Translation

10.7 Case Study: The Pentium/Linux Memory System
------------------------------------------------

10.8 Memory Mapping
-------------------

### 10.8.1 Shared Objects Revisited

### 10.8.2 The fork Function Revisited

### 10.8.3 The execve Function Revisited

### 10.8.4 User-level Memory Mapping with the mmap Function

10.9 Dynamic Memory Allocation
------------------------------

10.10 Garbage Collection
------------------------

### 10.10.1 Garbage Collector Basics

### 10.10.2 Mark&Sweep Garbage Collectors

### 10.10.3 Conservative Mark&Sweep for C Programs

10.11 Common Memory-related Bugs in C Programs
----------------------------------------------

### 10.11.1 Dereferencing Bad Pointers

### 10.11.2 Reading Uninitialized Memory

### 10.11.3 Allowing Stack Buffer Overflows

### 10.11.4 Assuming that Pointers and the Objects they Point to Are the Same Size

### 10.11.5 Making Off-by-one Errors

### 10.11.6 Referencing a Pointer Instead of the Object it Points to

### 10.11.7 Misunderstanding Pointer Arithmetic

### 10.11.8 Referencing Non-existent Variables

### 10.11.9 Referencing Data in Free Heap Blocks

### 10.11.10 Introducing Memory Leaks

10.12 Summary
-------------
