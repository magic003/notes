Representing and Manipulating Information
=========================================

2.1 Information Storage
-----------------------

Every byte of memory is identified by a unique number, known as its address, and the set of all possible addresses is known as the virtual address space.

### 2.1.1 Hexadecimal Notation

### 2.1.2 Words

Every computer has a word size, indicating the nominal size of integer and pointer data.

### 2.1.3 Data Sizes

### 2.1.4 Addressing and Byte Ordering

The least significant byte comes first is referred as __little endian__.
The most significant byte comes first is referred as big __big endian__.

### 2.1.5 Representing Strings

### 2.1.6 Representing Code

Binary code is seldom portable across different combinations of machine and operating system.

### 2.1.7 Boolean Algebras and Rings

### 2.1.8 Bit-Level Operations in C

### 2.1.9 Logical Operations in C

### 2.1.10 Shift Operations in C

2.2 Integer Representations
---------------------------

### 2.2.1 Integral Data Types

### 2.2.2 Unsigned and Tow's Complement Encodings

### 2.2.3 Conversions Between Signed and Unsigned

The cast from a signed value to unsigned value does not change the bit representation of the argument, just how these bits are interpreted as a number.

### 2.2.4 Signed vs. Unsigned in C

### 2.2.5 Expanding the Bit Representation of a Number

To convert an unsigned number to a larger data type, we can simply add leading 0s to the representation. This operation is known as __zero extension__. For converting two's complement number to a larger data type, the rule is to perform a __sign extension__.

### 2.2.6 Truncating Numbers
