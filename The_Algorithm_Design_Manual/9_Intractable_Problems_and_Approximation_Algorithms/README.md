Intractable Problems and Approximation Algorithms
=================================================

9.1 Problems and Reductions
---------------------------

Reductions are operations that convert one problem into another.

### 9.1.1 The Key Idea

A translation of instances from one type of problem to instances of another such that the answers are preserved is reduction.

Reductions are a way to show that two problems are essentially identical. A fast algorithm (or the lack of one) for one of the problems implies a fast algorithm (or the lack of one) for the other.

### 9.1.2 Decision Problems

The simplest interesting class of problems have answers restricted to true and false. There are called **decision problems**.

9.2 Reductions for Algorithms
-----------------------------

9.3 Elementary Hardness Reductions
----------------------------------

### 9.3.1 Hamiltonian Cycle

### 9.3.2 Independent Set and Vertex Cover

### 9.3.3 Clique

9.4 Satifiability
-----------------

### 9.4.1 3-Satisfiability

9.5 Creative Reductions
-----------------------

We must transform every instance ofa known NP-complete problem into an instance of the problem we are interested in.

### 9.5.1 Integer Programming

### 9.5.2 Vertex Cover

9.6 The Art of Proving Hardness
-------------------------------

Advice for proving hardness of a given problem:

* Make your source problem as simple as possible.
* Make your target problem as hard as possible.
* Select the right source problem for the right reason.
* Amplify the penalties for making the undesired selection.
* Think strategically at a high level, then build gadgets to enforce tactics.
* When you get stuck, alternate between looking for an algorithm or a reduction.

9.9 P vs. NP
------------

### 9.9.2 The Classes P and NP

The **P** stands for polynomial-time.

### 9.9.4 NP-hard vs. NP-complete?

A problem is NP-hard if it is at least as hard as any problem in NP. A problem is NP-complete if it is NP-hard, and also in NP itself.

9.10 Dealing with NP-complete Problems
--------------------------------------

Three options:   
* Algorithms fast in the average case.
* Heuristics
* Approximation algorithms
