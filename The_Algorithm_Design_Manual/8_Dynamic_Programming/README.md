Dynamic Programming
===================

Algorithms for optimization problems require proof that they always return the best possible solution. Greedy algorithms that make the best local decision at each step are typically efficient but usually do not guarantee global optimality. Exhaustive search algorithms that try all possibilities and select the best always produce the optimum result, but usually at a prohibitive cost in terms of time complexity.

Dynamic programming is a technique for efficiently implementing a recursive algorithm by storing partial results.

8.1 Caching vs. Computation
---------------------------

Dynamic programming is essentially a tradeoff of space for time.

8.2 Approximate String Matching
-------------------------------

8.3 Longest Increasing Sequence
-------------------------------

8.5 The Partition Problem
-------------------------

8.6 Parsing Context-Free Grammars
---------------------------------

For any optimization problem on left-to-right objects, such as characters in a string, elements of a permutation, points around a polygon, or leaves in a search tree, dynamic programming likely leads to an efficient algorithm to find the optimal solution.

8.7 Limitations of Dynamic Programming: TSP
-------------------------------------------

### 8.7.1 When are Dynamic Programming Algorithms Correct?

### 8.7.2 When are Dyanmic Programming Algorithms Efficient?

Without an inherent left-to-right ordering on the objects, dynamic programming is usually doomed to require exponential space and time.
