Algorithm Analysis
==================

Two important tools are:
* the RAM model of computation
* the asymptotic analysis of worst-case complexity

2.1 The RAM model of Computation
--------------------------------

The _Random Access Machine_ or RAM mode assumes:
* Each simple operation (+, \*, -, =, if, call) takes exactly one time step.
* Loops and subroutines are not considered simple operations. Instead, they are the composition of many single-step operations.
* Each memory access takes exactly one time step.

### 2.1.1 Best, Worst, and Average-Case Complexity

* The __worst-case complexity__ is the function defined by the maximum number of steps taken in any instance of size _n_.
* The __best-case complexity__ is the function defined by the minimum number of steps taken in any instance of size _n_.
* The __average-case complexity__ is the function defined by the average number of steps over all instances of size _n_.

2.2 The Big Oh Notation
-----------------------

The Big Oh notation are:
* _f(n) = O(g(n))_ means _c&sdot;g(n)_ is an __upper bound__ on _f(n)_.
* _f(n) = &Omega;(g(n))_ means _c&sdot;g(n)_ is an __lower bound__ on _f(n)_.
* _f(n) = &Theta;(g(n))_ means _c<sub>1</sub>&sdot;g(n)_ is an upper bound on _f(n)_ and _c<sub>2</sub>&sdot;g(n)_ is a lower bound on _f(n)_.

2.3 Growth Rates and Dominance Relations
----------------------------------------

### 2.3.1 Dominance Relations

A faster-growing function **dominates** a slower-growing one.

Functions listed in order of increasing dominance:

* Constant functions, _f(n) = 1_
* Logarithmic functions, _f(n) = log n_
* Linear functions, _f(n) = n_
* Superlinear functions, _f(n) = n lg n_
* Quadratic functions, _f(n) = n<sup>2</sup>_
* Cubic functions, _f(n) = n<sup>3</sup>_
* Exponiential functions, _f(n) = c<sup>n</sup>_
* Factorial functions, _f(n) = n!_


