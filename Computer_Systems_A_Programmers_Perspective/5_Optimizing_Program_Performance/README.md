Optimizing Program Performance
==============================

Writing an efficient program requires two types of activities. First, we must select the best set of algorithms and data structures. Second, we must write source code that the compiler can effectively optimize to turn into efficient executable code.

5.1 Capabilities and Limitations of Optimizing Compilers
--------------------------------------------------------

5.2 Expressing Program Performance
----------------------------------

5.3 Program Example
-------------------

5.4 Eliminating Loop Inefficiencies
-----------------------------------

5.5 Reducing Procedure Calls
----------------------------

5.6 Eliminating Unneeded Memory References
------------------------------------------

5.7 Understanding Modern Processors
-----------------------------------

### 5.7.1 Overall Operation

### 5.7.2 functional Unit Performance

### 5.7.3 A Closer Look at Processor Operation

5.8 Reducing Loop Overhead
--------------------------

5.9 Converting to Pointer Code
------------------------------

5.10 Enhancing Parallelism
--------------------------

5.11 Putting it Together
------------------------

5.12 Branch Prediction and Misprediction Penalties
--------------------------------------------------

5.13 Understanding Memory Performance
-------------------------------------

5.14 Life in the Real World: Performance Improvement Techniques
---------------------------------------------------------------

Basic strategies for optimizing program performance:
1. High-level design. Choose appropriate algorithms and data structures.
2. Basic coding principles. Avoid optimization blockers:
    * Eliminate excessive function calls. Move computations out of loops when possible.
    * Eliminate unnecessary memory references. Introduce temporary variables to hold intermediate results. Store a result in an array or global variable only when the final value has been computed.
3. Low-level optimizations.
    * Try various forms of pointer versus array code.
    * Reduce loop overhead by unrolling loops.
    * Find ways to make user of the pipelined functional units by techniques such as iteration splitting.

5.15 Identifying and Eliminating Performance Bottlenecks
--------------------------------------------------------

## 5.15.3 Amdahl's Low

To significantly speed up the entire system, we must improve the speed of a very large fraction of the overall system.

5.16 Summary
------------

