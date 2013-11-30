Linking
=======

7.1 Compiler Drivers
--------------------

A compiler driver invokes the language preprocessor, compiler, assembler and linker.

7.2 Static Linking
------------------

To build the executable, the linker must perform two main tasks:

* Symbol resolution. Its purpose is to associate each symbol reference with exactly one symbol definition.
* Relocation. 

7.3 Object Files
----------------

Object files come in three forms:
* Relocatable object file. Contains binary code and data in a form that can be combined with other relocatable object files at compile time to create an executable object file.
* Executable object file. Contains binary code and data in a form that can be copied directly iinto memory and executed.
* Shared object file. A special type of relocatable object file that can be loaded into memory and linked dynamically, at either load time or run time.

7.4 Relocatable Object Files
----------------------------

7.5 Symbols and Symbol Tables
-----------------------------

There are three different kinds of symbols:
* Global symbols that are defined by module m and that can be referenced by other modules.
* Global symbols that are referenced by module m but defined by some other module.
* Local symbols that are defined and referenced exclusively by module m.

7.6 Symbol Resolution
---------------------

### 7.6.1 How Linkers Resolve Multiply-Defined Global Symbols

Functions and initialized global variables get strong symbols. Uninitialized global variables get weak symbols.

Unix linkers use the following rules for dealing with multiply-defined symbols:
* Rule 1: Multiple strong symbols are not allowed.
* Rule 2: Given a strong symbol and multiple weak symbols, choose the strong symbol.
* Rule 3: Given multiple weak symbols, choose any of the weak symbols.

### 7.6.2 Linking with Static Libraries

### 7.6.3 How Linkers Use Static Libraries to Resolve References

7.7 Relocation
--------------

Relocation consists of two steps:
* Relocating sections and symbol definitions. In this step, the linker merges all sections of the same type into a new aggregate section of the same type. When this step is complete, every instruction and global variable in the program has a unique run-time memory address.
* Relocating symbol references within sections. In this step, the linker modifies every symbol reference in the bodies of the code and data sections so that they point to the correct run-time addresses.

### 7.7.1 Relocation Entries

### 7.7.2 Relocating Symbol References

7.8 Executable Object Files
---------------------------

7.9 Loading Executable Object Files
-----------------------------------

The process of copying the program into memory and then running it is konwn as __loading__.

7.10 Dynamic Linking with Shared Libraries
------------------------------------------

A shared library is an object module that, at run time, can be loaded at an arbitrary memory address and linked with a program in memory. This process is known as __dynamic linking__, and is performed by a program called a dynamic linker.


Shard libraries are "shared" in two different ways. First, in any given file system, there is exactly one .so file for a particular library. Second, a single copy of the .text section of a shared library in memory can be shared by different running processes.

7.11 Loading and Linking Shared Libraries from Applications
-----------------------------------------------------------

7.14 Summary
------------

