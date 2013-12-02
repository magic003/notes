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

