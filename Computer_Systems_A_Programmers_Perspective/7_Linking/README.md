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


