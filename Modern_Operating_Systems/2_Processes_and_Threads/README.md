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
