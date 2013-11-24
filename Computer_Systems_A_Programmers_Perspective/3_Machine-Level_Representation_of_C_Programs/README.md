Machine-Level Representation of C Programs
==========================================

3.1 A Historical Perspective
----------------------------

3.2 Program Encodings
---------------------

The GCC command invokes a sequence of programs to turn the source code into executable code.
1. The C preprocessor expands the source code to include any files specified with __#include__ commands and to expand any macros. 
2. The compiler generates assembly code versions of the two source files having names __p1.s__ and __p2.s__. 
3. The assembler converts the assembly code into binary object code files __p1.o__ and __p2.o__.
4. The linker merges these two object files along with code implementating standard Unix library functions and generates the final executable file.

### 3.2.1 Machine-Level Code

Whereas C provides a model where objects of different data types can be declared and allocated in memory, assembly code views the memory as simply a large, byte-addressable array.

### 3.2.2 Code Examples

### 3.2.3 A Note on Formatting

3.3 Data Formats
----------------

3.4 Accessing Information
-------------------------

### 3.4.1 Operand Specifiers

Different operand possibilities can be classified into three types. 
* Immediate is for constant values.
* Register denotes the contents of one of the registers.
* Memory reference.

### 3.4.2 Date Movement Instructions

### 3.4.3 Data Movement Example

3.5 Arithmetic and Logical Operations
-------------------------------------

### 3.5.1 Load Effective Address

### 3.5.2 Unary and Binary Operations

### 3.5.3 Shift Operations

### 3.5.4 Dicussion

### 3.5.5 Special Arithmetic Operations

3.6 Control
-----------

### 3.6.1 Condition Codes

### 3.6.2 Accessing the Condition Codes

### 3.6.3 Jump Instructions and their Encodings

### 3.6.4 Translating Conditional Branches

### 3.6.5 Loops

### 3.6.6 Switch Statements

3.7 Procedures
--------------

### 3.7.1 Stack Frame Structure

### 3.7.2 Transferring Control

### 3.7.3 Register Usage Conventions

Caller save and callee save registers.

### 3.7.4 Procedure Example

### 3.7.5 Recursive Procedures

3.8 Array Allocation and Access
-------------------------------

### 3.8.1 Basic Principles

### 3.8.2 Pointer Arithmetic

### 3.8.3 Arrays and Loops
