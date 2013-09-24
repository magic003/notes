Combinatorial Search and Heuristic Methods
==========================================

7.1 Backtracking
----------------

At each step in the backtracking algorithm, we try to extend a given partial solution a = (a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>k</sub>) by adding another element at the end. After extending it, we must test whether what we now have is a solution: if so, we should print it or count it. If not, we must check whether the partial solution is still potentially extendible to some complete solution.

Backtracking constructs a tree of partial solutions, where each vertex represents a partial solution.

### 7.1.1 Constructing All Subsets

### 7.1.2 Constructing All Permutations

### 7.1.3 Constructing All Paths in a Graph

7.2 Search Pruning
------------------

Pruning is the technique of cutting off the search the instance we have established that a partial solution cannot be extended into a full solution.

7.3 Sudoku
----------


