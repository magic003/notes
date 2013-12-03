Introduction
============

Most computers have two modes of opertaion: kernel mode and user mode. The operating system is the most fundamental piece of software and runs in kernel mode. In this mode, it has complete access to all the hardware and can execute any instruction the machine is capable of executing.

1.1 What is an Operating System?
--------------------------------

### 1.1.1 The Operating System as na Extended Machine

### 1.1.2 The Operating System as a Resource Manager

Resource management includes **multiplexing** (sharing) resources in two different ways: in time and in space.

1.2 History of Operating Systems
--------------------------------

1.3 Computer Hardware Review
----------------------------

### 1.3.1 Processors

### 1.3.2 Memory

### 1.3.3 Disks

### 1.3.4 Tapes

### 1.3.5 I/O Devices

There are three ways the driver can be put into the kernel. 
* Relink the kernel with new driver and then reboot the system. Many older UNIX systems work like this.
* Make an entry in an operating system file telling it that it needs the driver and then reboot the system. At boot time, the operating system goes and finds the drivers it needs and loads them. Windows works this way.
* Accept new drivers while running and install them on the fly without the need to reboot. Hot pluggable devices, such as USB devices always need dynamically loaded drivers.

### 1.3.6 Buses

### 1.3.7 Booting the Computer

1.4 The Operating System Zoo
----------------------------

### 1.4.1 Mainframe Operating Systems

### 1.4.2 Server Operating Systems

### 1.4.3 Multiprocessor Operating Systems

### 1.4.4 Personal Computer Operating Systems

### 1.4.5 Handheld Computer Operating Systems

### 1.4.6 Embedded Operating Systems

### 1.4.7 Sensor Node Operating Systems

### 1.4.8 Real-Time Operating Systems

### 1.4.9 Smart Card Operating Systems

1.5 Operating System Concepts
-----------------------------

### 1.5.1 Processes

### 1.5.2 Address Spaces

### 1.5.3 Files

Two kinds of special files exist: block special files and character special files. Block special files are used to model devices that consist of a collection of randomly addressable blocks, such as disks. Character special files are used to model printers, modems and other devices that accept or output a character stream.

A pipe is a sort of psuedofile that can be used to connect two processes.

### 1.5.4 Input/Output

### 1.5.5 Protection

### 1.5.6 Shell

### 1.5.7 Ontogeny Recapitulates Phylogeny

1.6 System Calls
----------------

1.7 Operating System Structure
------------------------------

### 1.7.1 Monolithic Systems

### 1.7.2 Layered Systems

### 1.7.3 Microkernels

### 1.7.4 Client-Server Model

### 1.7.5 Virtual Machines

### 1.7.6 Exokernels

1.8 The World According to C
----------------------------

1.9 Research of Operating Systems
---------------------------------

1.12 Summary
------------
