# 🖥️ OS Concepts Simulator

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![C++](https://img.shields.io/badge/language-C++17-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)

A comprehensive, modular C++ simulator that brings core Operating System concepts to life through interactive command-line demonstrations. Perfect for students, educators, and anyone looking to understand OS internals through hands-on experimentation.

## 🎯 What This Project Does

This simulator recreates the fundamental algorithms and mechanisms that power modern operating systems, allowing you to:

- **Visualize** how different CPU scheduling algorithms affect process execution
- **Experiment** with page replacement strategies and their performance impacts  
- **Understand** virtual memory translation from virtual to physical addresses
- **Observe** multithreading synchronization in action with the classic Producer-Consumer problem
- **Explore** system call mechanics and process control block management

## 🧠 Core Features

### 🕒 CPU Scheduling Algorithms
Experience how the OS decides which process runs next:

- **FCFS** (First-Come, First-Served) - Simple queue-based scheduling
- **SJF** (Shortest Job First) - Both non-preemptive and preemptive variants
- **Priority Scheduling** - High-priority processes get CPU time first
- **Round Robin** - Time-sliced fair scheduling with configurable quantum

*Each algorithm shows detailed metrics: waiting time, turnaround time, and average performance*

### 📦 Memory Management & Page Replacement
See how the OS manages limited physical memory:

- **FIFO** - First page in, first page out
- **LRU** (Least Recently Used) - Evicts pages that haven't been accessed recently
- **Optimal** - Theoretical best-case replacement (future knowledge required)

*Compare hit rates and page fault frequencies across algorithms*

### 🧮 Virtual Memory Paging System
Watch address translation in real-time:

- Converts virtual addresses to physical memory locations
- Maintains page tables with frame allocation tracking  
- Detects and reports invalid memory access attempts
- Demonstrates the foundation of modern memory protection

### 🧵 Multithreading & Synchronization
Observe concurrent programming concepts:

- **Producer-Consumer** implementation with bounded buffer
- **Mutex locks** preventing race conditions
- **Condition variables** for thread coordination
- Real-time visualization of thread states and buffer contents

### 🔧 System Call Simulation
Experience kernel-level process management:

- **Fork** - Create new processes with unique PIDs
- **Exit** - Terminate processes and cleanup resources  
- **Wait** - Parent process synchronization with children
- **PCB Table** - Track process states (READY → RUNNING → TERMINATED)

## 🗂️ Project Architecture

```
os-concepts-simulator/
├── 📄 main.cpp              # Entry point and menu system
├── 📄 Makefile              # Build automation
├── 📄 LICENSE               # MIT License
├── 📁 scheduling/           # CPU scheduling algorithms
│   ├── fcfs.cpp            #   First-Come First-Served
│   ├── sjf.cpp             #   Shortest Job First
│   ├── sjf_preemptive.cpp  #   Preemptive SJF
│   ├── priority.cpp        #   Priority scheduling
│   └── rr.cpp              #   Round Robin
├── 📁 memory/               # Page replacement algorithms  
│   ├── fifo.cpp            #   First-In First-Out
│   ├── lru.cpp             #   Least Recently Used
│   └── optimal.cpp         #   Optimal replacement
├── 📁 virtual_memory/       # Address translation
│   ├── paging.cpp          #   Virtual-to-physical mapping
│   └── paging.h            #   Page table structures
├── 📁 syscalls/             # System call simulation
│   ├── context.cpp         #   Process context switching
│   ├── pcb.h               #   Process Control Block
│   └── syscalls.h          #   System call interface
├── 📁 threads/              # Multithreading demos
│   └── prod_cons.cpp       #   Producer-Consumer pattern
└── 📄 README.md            # This documentation
```

## 🚀 Quick Start

### Prerequisites
- **C++17** compatible compiler (g++, clang++, MSVC)
- **Make** build system
- Terminal/Command Prompt

### Build & Run
```bash
# Clone the repository
git clone https://github.com/Captaincool2017/os-concepts-simulator.git
cd os-concepts-simulator

# Build everything
make

# Run different simulations
./build/main.exe <algorithm> [parameters]
```

### 💡 Usage Examples

**CPU Scheduling:**
```bash
./build/main.exe fcfs                    # First-Come First-Served
./build/main.exe sjf                     # Shortest Job First  
./build/main.exe priority                # Priority Scheduling
./build/main.exe rr 3                    # Round Robin (quantum=3)
```

**Memory Management:**
```bash
./build/main.exe fifo                 # FIFO
./build/main.exe lru                  # LRU 
./build/main.exe optimal              # Optimal
```

**Other Simulations:**
```bash
./build/main.exe paging                  # Virtual memory paging
./build/main.exe syscalls                # System call simulation
./build/main.exe threads                 # Producer-Consumer threading
```

## 📊 Sample Output

### CPU Scheduling Results
```plaintext
[SJF Scheduling]
PID     Arrival Burst   Waiting Turnaround
1       0       5       0       5
2       1       3       4       7
3       2       8       12      20
4       3       6       5       11

Gantt Chart:
|  P1  |  P2  |  P4  |  P3  |
0      5      8     14     22
```

### Virtual Memory Paging
```plaintext
[Paging Simulation]
VirtAddr        Page#   Offset  PhysAddr        Frame#
0               0       0       0               0
1023            0       1023    1023            0
1024            1       0       1024            1
2047            1       1023    2047            1
4095            3       1023    3071            2
8191            7       1023    4095            3
16383           15      1023    5119            4
16384   Invalid virtual address
17000   Invalid virtual address
-1      Invalid virtual address
```

## 🎓 Educational Value

This simulator is designed for:

- **Computer Science Students** learning OS concepts
- **Educators** demonstrating algorithms in classroom settings  
- **Self-learners** exploring operating system internals
- **Interview Preparation** for system programming roles

Each module includes detailed comments explaining the theory behind the implementation.

## 🌟 Resume-Ready Description

> *"Developed a comprehensive Operating Systems Concepts Simulator in C++ featuring modular architecture for CPU scheduling (FCFS, SJF, Priority, Round Robin), memory management (FIFO, LRU, Optimal page replacement), virtual memory paging with address translation, multithreaded Producer-Consumer synchronization, and system call simulation with PCB management. Designed for educational use with extensible codebase and detailed performance metrics."*

## 🔧 Future Enhancements

**Planned Features:**
- 🔒 **Deadlock Detection** - Banker's algorithm implementation
- 💾 **Disk Scheduling** - SCAN, C-SCAN, LOOK algorithms  
- 📁 **File System Simulation** - inode and FAT-based models
- 🖥️ **Interactive CLI Shell** - Menu-driven module selection
- 📈 **Performance Graphing** - Visual algorithm comparisons
- 🌐 **Network Simulation** - Basic networking protocols

**Contribution Ideas:**
- Add more scheduling algorithms (CFS, EDF)
- Implement memory segmentation
- Create GUI visualization interface
- Add process migration simulation

## 🤝 Contributing

Contributions are welcome! Please feel free to:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)  
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

For major changes, please open an issue first to discuss what you would like to change.

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Your Name**  
Computer Science Student | OS Enthusiast  
📧 nishchaypallav2002@gmail.com | 🔗 [LinkedIn](https://www.linkedin.com/in/nishchaypallav/)

---

*Built with ❤️ for the Computer Science community*