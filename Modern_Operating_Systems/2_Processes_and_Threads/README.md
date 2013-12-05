Processes and Threads
=====================

2.1 Processes
-------------

### 2.1.1 The Process Model

A process is just an instance of an executing program, including the current values of the program counter, registers and variables.

### 2.1.2 Process Creation

There are four principal events that cause processes to be created:
1. System initialization.
2. Execution of a process creation system call by a running process.
3. A user request to create a new process.
4. Initiation of a batch job.

### 2.1.3 Process Termination

### 2.1.4 Process Hierarchies

### 2.1.5 Process States

Three states: running, ready and blocked.

### 2.1.6 Implementation of Processes

To implement the process model, the operating system maintains a table, called the process table, with one entry per process.

### 2.1.7 Modeling Multiprogramming

2.2 Threads
-----------

### 2.2.1 Thread Usage

### 2.2.2 The Classical Thread Model

Processes are used to group resources together; threads are the entities scheduled for execution on the CPU.

Each stack has its own stack.

### 2.2.3 POSIX Threads

### 2.2.4 Implementing Threads in User Space

Advantages of user space threads:
* It can be implemented on an operating system that does not support threads.
* Thread scheduling is very fast.
* It allows each process to have its own customized scheduling algorithm.

Problems:
* How blocking system calls are implemented.
* Page faults
* If a thread starts running, no other thread in that process will ever run unless the first thread gives up the CPU.

### 2.2.5 Implementing Threads in ther Kernel

### 2.2.6 Hybrid Implementations

### 2.2.7 Scheduler Activations

### 2.2.8 Pop-Up Threads

### 2.2.9 Making Single-Threaded Code Multithreaded

2.3 Interprocess Communication
------------------------------

Three issues for IPC:
* How one process can pass information to another.
* Make sure two or more processes do not get in each other's way.
* When dependencies are present.

### 2.3.1 Race Conditions

### 2.3.2 Critical Regions

We need four conditions to hold to have a good solution:

1. No two processes may be simultaneously inside their critical regions.
2. No assumptions may be made about speeds or the number of CPUs.
3. No process running outside its critical region may block other processes.
4. No process should have to wait forever to enter its critical region.

### 2.3.3 Mutual Exclusion with Busy Waiting

**Disabling Interrups**

It is often a useful technique within the operating system itself but is not appropriate as a general mutual exclusion machnism for user processes.

**Lock Variables**

It hasthe same fatal flaw in the spooler directory.

**Strict Alternation**

Continuously testing a variable until some value appears is called **busy waiting**.

**Peterson's Solution**

### 2.3.4 Sleep and Wakeup

**The Producer-Consumer Problem**

### 2.3.5 Semaphores

The operation is an **atomic action**.

**Solving the Producer-Consumer Problem Using Semaphores**

### 2.3.6 Mutexes

When the semaphore's ability to count is not needed, a simplified version of the semaphore, called a **mutex**, is sometimes used.

A **mutex** is a variable that can be in one of two states: unlocked or locked.

### 2.3.7 Monitors

Monitors have an important property that makes them useful for achieving mutual exclusion: only one process can be active in a monitor at any instant. Monitors are a programming language construct.

It is up to the compiler to implement mutual exclusion on monitor entries, but a common way is to use a mutex or a binary semaphore.

Condition variables, along with two operations on them, __wait__ and __signal__.

The operations __wait__ and __signal__ are very similar to __sleep__ and __wakeup__, but with one crucial difference: __sleep__ and __wakeup__ failed because while one process was trying to go to sleep, the other one was trying to wake it up. With monitors, that cannot happen. The automatic mutual exclusion on monitor procedures guarantees that if the producer inside a monitor procedure discorvers that the buffer is full, it will be able to complete the __wait__ operation without having to worry about the possibility that the scheduler may switch to the consumer just before the __wait__ completes.

### 2.3.8 Message Passing

### 2.3.9 Barriers

2.4 Scheduling
--------------

### 2.4.1 Introduction to Scheduling

### 2.4.2 Scheduling in Batch Systems

**First-Come First-Served**

**Shortest Job First**

**Shortest Remaining Time Next**

### 2.4.3 Scheduling in Interactive Systems

**Round-Robin Scheduling**

**Priority Scheduling**

**Multiple Queues**

**Shortest Process Next**

**Guaranteed Scheduling**

**Lottery Scheduling**

**Fair Share Scheduling**

### 2.4.4 Scheduling in Real-Time Systems

### 2.4.5 Policy versus Machanism

The scheduling algorithm is parameterized in some way, but the parameters can be filled in by user processes.

### 2.4.6 Thread Scheduling

2.5 Classical IPC Problems
--------------------------

### 2.5.1 The Dining Philosophers Problem

### 2.5.2 The Readers and Writers Problem

2.7 Summary
-----------

