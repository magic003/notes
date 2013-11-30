Exceptional Control Flow
========================

8.1 Exceptions
--------------

An exception is an abrupt change in the control flow in response to some change in the processor's state.

### 8.1.1 Exception Handling

### 8.1.2 Classes of Exceptions

Exceptions can be divided into four classes: interrupts, traps, faults and aborts.

Interrupts occur asynchronously as a result of signals from I/O devices that are external to the processor.

Traps are intentional exceptions that occur as a result of executing an instruction. The most important use of traps is to provide a procedure-like interface between user programs and the kernel known as a __system call__.

Faults result from error conditions that a handler might be able to correct. A classic example of a fault is the page fault exception, which occurs when an instruction references a virtual address whose corresponding physical page is not resident in memory and must be retreived from disk.

Aborts result from unrecoverable fatal errors. Abort handlers never reeturn control to the application program.

### 8.1.3 Exceptions in Intel Processors

8.2 Processes
-------------

### 8.2.1 Logical Control Flow

### 8.2.2 Private Address Space

### 8.2.3 User and Kernel Modes

### 8.2.4 Context Switches

The kernel maintains a context for each process. It consists of the values of objects such as the general-purpose registers, the floating-point registers, the program counter, user's stack, status registers, kernel's stack and various kernel data structure.

8.3 System Calls and Error Handling
-----------------------------------

8.4 Process Control
-------------------

8.5 Signals
-----------

### 8.5.1 Signal Terminology

### 8.5.2 Sending Signals

8.6 Nonlocal Jumps
------------------

8.7 Tools for Manipulating Processes
------------------------------------

8.8 Summary
-----------

