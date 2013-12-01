Concurrent Programming with Threads
===================================

11.1 Basic Thread Concepts
--------------------------

11.2 Thread Control
-------------------

11.3 Shared Variables in Threaded Programs
------------------------------------------

### 11.3.1 Threads Memory Model

Registers are never shared, while virtual memory is always shared.

### 11.3.2 Mapping Variables to Memory

### 11.3.3 Shard Variables

11.4 Synchronizing Threads with Semaphores
------------------------------------------

11.5 Synchronizing Threads with Mutex and Condition Variables
-------------------------------------------------------------

Pthreads provides a family of synchronization operations on mutex and condition variables. In general, we prefer semaphores over their Pthreads counterparts because they are more elegant and simpler to reason about. 

Semaphores can be used for both sharing and signaling. Pthreads provides one set of functions (based on mutext variables) for sharing, and another set (based on condition variables) for signaling.

### 11.5.1 Mutex Variables

### 11.5.2 Condition Variables

### 11.5.3 Barrier Synchronization

### 11.5.4 Timeout Waiting

11.6 Thread-safe and Reentrant Functions
----------------------------------------

Four classes of thread-unsafe functions:
1. Failing to protect shared variables.
2. Relying on state across multiple function invocations.
3. Returning a pointer to a static variable.
4. Calling thread-unsafe functions.

### 11.6.1 Reentrant Functions

__Reentrant functions__ are characterized by the property that they do not reference any shared data when they are called by multiple threads.

Reentrant functions are typically more efficient than non-reentrant thread-safe functions because they requires no synchronization operations.

### 11.6.2 Thread-safe Library Functions

11.7 Other Synchronization Errors
---------------------------------

### 11.7.1 Races

A __race__ occurs when the correctness of a program depends on one thread reaching point x in its control flow before another thread reaches point y.

### 11.7.2 Deadlocks

11.8 Summary
------------
