Introduction
============

1.1 Information is Bits in Context
----------------------------------

The source program is a sequence of bits, each with a value of 0 or 1, organized in 8-bit chunks called __bytes__. Each byte represents some text character.

All information in a system is represented as bunch of bits. The only thing that distinguishes different data objects is the context in which we view them.

1.2 Programs are Translated by Other Programs into Different Forms
------------------------------------------------------------------

1.3 It Pays to Understand How Compilation Systems Work
------------------------------------------------------

1.4 Processors Read and Interpret Instructions Stored in Memory
---------------------------------------------------------------

### 1.4.1 Hardware Organization of a System

**Buses**
Running throughout the system is a collection of electrical conduits called __buses__ that carry bytes of information back and forth between the components. Bueses are typically designed to transfer fixed-sized chunks of bytes known as words.

**I/O devices**
Input/output(I/O) devices are the sytem's connection to the external world.

Each I/O device is connected to the I/O bus by either a controller or an adapter.

**Main memory**
The main memory is a temporary storage device that holds both a program and the data it manipulates while the processor is executing the program.

**Processor**

The CPU or simply processor, is the engine that interprets instructions stored in main memory. At its core is a word-sized storage device called the program counter(PC). At any time point, it points at some instruction in main memory.

### 1.4.2 Running the hello Program

1.5 Caches Matter
-----------------

1.6 Storage Devices Form a Hierarchy
------------------------------------

1.7 The Operating System Manages the Hardware
---------------------------------------------

All attempts by an application program to manipulate the hardware must go through the operating system.

The operating system has two primary purposes: 1) To protect the hardware from misuse by runaway applications, and 2) to provide applications with simple and uniform mechanisms for manipulating complicated and often wildly different low-level hardware devices.

### 1.7.1 Processes

A process is the operating system's abstraction for a running program.

### 1.7.2 Threads

Each thread in the context of the process and sharing the same code and global data.

### 1.7.3 Virtual Memory

* Program code and data
* Heap
* Shared libraries
* Stack
* Kernal virtual memory

### 1.7.4 Files

A Unix file is a sequence of bytes, nothing more and nothing less.

1.8 Systems Communicate With Other Systems Using Networks
---------------------------------------------------------

