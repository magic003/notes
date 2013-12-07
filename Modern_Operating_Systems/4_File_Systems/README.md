File Systems
============

Three essential requirements for long-term information storage:

1. It must be possible to store a very large amount of information.
2. The information must survive the termination of the process using it.
3. Multiple processes must be able to access the information concurrently.

Together, the abstractions of processes(and threads), address spaces, and files are the most important concepts relating to operating systems.

4.1 Files
---------

### 4.1.1 File Naming

### 4.1.2 File Structure

### 4.1.3 File Types

ASCII files and binary files.

### 4.1.4 File Access

Sequential access

Random access files

### 4.1.5 File Attributes

### 4.1.6 File Operations

### 4.1.7 An Example Program Using File System Calls

4.2 Directories
---------------

### 4.2.1 Single-Level Directory Systems

### 4.2.2 Hierarchical Directory Systems

### 4.2.3 Path Names

### 4.2.4 Directory Operations

Hard link and symbolic link

4.3 File System Implementation
------------------------------

### 4.3.1 File System Layout

**Important**: MBR, partition table, Boot block, superblock, I-nodes. 

### 4.3.2 Implementing Files

**Contiguous Allocation**

It is simple to implement and has high performance.

**Linked List Allocation**

**Linked List Allocation Using a Table in Memory**

**I-nodes**

### 4.3.3 Implementing Directories

### 4.3.4 Shared Files

### 4.3.5 Log-Structured File Systems

### 4.3.6 Jornaling File Systems

### 4.3.7 Virtual File Systems

4.4 File System Management and Optimaization
--------------------------------------------

### 4.4.1 Disk Space Management

### 4.4.2 File System Backups

### 4.4.3 File System Consistency

4.7 Summary
-----------

