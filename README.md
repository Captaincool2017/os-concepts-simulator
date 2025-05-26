# OS Concepts Simulator

A modular, command-line based C++ project simulating core Operating System concepts:

- CPU Scheduling Algorithms
- Page Replacement Algorithms
- Virtual Memory Paging
- System Call Simulation with PCB Table
- Multithreading using Producer–Consumer model

## 🧠 Features

### 🕒 CPU Scheduling
Simulates classic algorithms:
- FCFS (First-Come, First-Served)
- SJF (Non-preemptive & Preemptive)
- Priority Scheduling (Non-preemptive & Preemptive)
- Round Robin (with configurable time quantum)

### 📦 Page Replacement
Includes:
- FIFO
- LRU
- Optimal

### 🧮 Virtual Memory Paging
- Translates virtual addresses to physical addresses
- Uses a page table with basic frame allocation
- Reports invalid address access

### 🧵 Multithreading
- Implements Producer–Consumer problem
- Uses mutex & condition variables

### 🔧 System Calls Simulation
- Fork, Exit, Wait
- Simulates PCB table and process states (READY, RUNNING, TERMINATED)

## 🗂️ Project Structure

```
os-concepts-simulator/
├── main.cpp
├── Makefile
├── LICENSE
├── memory/
│   ├── fifo.cpp
│   ├── lru.cpp
│   └── optimal.cpp
├── scheduling/
│   ├── fcfs.cpp
│   ├── priority.cpp
│   ├── rr.cpp
│   ├── sjf.cpp
│   └── sjf_preemptive.cpp
├── syscalls/
│   ├── context.cpp
│   ├── pcb.h
│   └── syscalls.h
├── threads/
│   └── prod_cons.cpp
├── virtual_memory/
│   ├── paging.cpp
│   └── paging.h
└── README.md
```

## ▶️ Build & Run

```bash
make
./build/main.exe <algorithm> [quantum]
```

### Examples:
```bash
./build/main.exe fcfs
./build/main.exe rr 2
./build/main.exe fifo
./build/main.exe paging
```

## 📄 Example Output
```
[SJF Scheduling]
PID     Arrival Burst   Waiting Turnaround
1       0       5       0       5
...
```

```
[Paging Simulation]
VirtAddr    Page#   Offset  PhysAddr    Frame#
1024        1       0       256         0
...
```

## 📌 Resume Bullet

> Built a modular OS Concepts Simulator in C++ to demonstrate scheduling, memory management, system calls, and multithreading with synchronization. Designed for educational use and extendable architecture.

## 💡 Possible Extensions
- Deadlock Detection (Banker's algorithm)
- Disk Scheduling (SCAN, LOOK, etc.)
- File System Simulation (e.g. inode/FAT-based)
- CLI Shell Interface for interactive module selection

---
MIT License
