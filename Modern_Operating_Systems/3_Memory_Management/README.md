Memory Management
=================

3.1 No Memory Abstraction
-------------------------

3.2 A Memory Abstraction: Address Spaces
----------------------------------------

Exposing memory to processes has several major drawbacks.

1. If user programs can address every byte of memory, they can easily trash the operating system, intentionally or by accident, bringing the system to a grinding halt.
2. It is difficult to have multiple programs running at once.

### 3.2.1 The Notion of an Address Space

An **address space** is the set of addresses that a process can use to address memory.

### 3.2.2 Swapping

Two approaches to dealing with memory overload are **swapping** and **virtual memory**.

### 3.2.3 Managing Free Memory

Two ways to keep track of memory usage: bitmaps and free lists.

Algorithms to allocate memory for a created process:   
* first fit
* next fit
* best fit
* worst fit
* quick fit

3.3 Virtual Memory
------------------

### 3.3.1 Paging

These program-generated addresses are called **virtual addresses** and form the **virtual address space**.

The virtual address space is divided into fixed-size units called **pages**. The corresponding units in the physical memory are called **page frames**.

### 3.3.2 Page Tables

### 3.3.3 Speeding Up Paging

**Translation Lookaside Buffers**

### 3.3.4 Page Tables for Large Memories

**Multilevel Page Tables**

**Inverted Page Tables**

3.4 Page Replacement Algorithms
-------------------------------

### 3.4.1 The Optimal Page Replacement Algorithm

### 3.4.2 The Not Recently Used Page Replacement Algorithm

### 3.4.3 The First-In, First-Out (FIFO) Page Replacement Algorithm

### 3.4.4 The Second-Chance Page Replacement Algorithm

### 3.4.5 The Clock Page Replacement Algorithm

### 3.4.6 The Least Recently Userd(LRU) Page Replacment Algorithm

Throw out the page that has been unused for the longest time.

### 3.4.10 Summary of Page Replacement Algorithms

The two best algorithms are aging and WSClock. They are based on LRU and the working set. Both give good paging performance and can be implemented efficiently.

3.5 Design Issues for Paging Systems
------------------------------------

### 3.5.1 Local versus Global Allocation Policies

