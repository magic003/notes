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

7.5 Heuristic Search Methods
----------------------------

All methods have two commont components:   
* Solution space representation
* Cost function

### 7.5.1 Random Sampling

When might random sampling do well:   

* When there are a high proportion of acceptable solutions.
* When there is no coherence in the solution space.

### 7.5.2 Local Search

Greedy search or gradient descent search are great at finding local optima quickly, but often fail to find the globally best solution.

When local search does well:

* When there is great coherence in the solution space.
* Whenever the cost of incremental evaluation is much cheaper than global evaluation.

### 7.5.3 Simulated Annealing

7.8 Other Heuristic Search Methods
----------------------------------

7.9 Parallel Algorithms
-----------------------


