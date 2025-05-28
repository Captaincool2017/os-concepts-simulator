#include "include/os_sim.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./main.exe <algorithm|syscall> [quantum]\n";
        std::cout << "Available scheduling algorithms: fcfs, sjf, sjf_preemptive, rr, priority, priority_preemptive\n";
        std::cout << "Available memory algorithms: fifo, lru, optimal\n";
        std::cout << "Available syscall demo: syscall\n";
        std::cout << "Available threads demo: threads\n";
        std::cout << "Available virtual memory paging demo: paging\n";
        std::cout << "Example: ./build/main.exe rr 4\n";
        return 1;
    }

    std::string algorithm = argv[1];

    // 🔹 Scheduling algorithms
    std::vector<Process> processes = {
        {1, 0, 5},
        {2, 1, 3},
        {3, 2, 8},
        {4, 3, 6}
    };

    if (algorithm == "fcfs") {
        runFCFS(processes);
    } else if (algorithm == "sjf") {
        runSJF(processes);
    } else if (algorithm == "sjf_preemptive") {
        runSJFPreemptive(processes);
    } else if (algorithm == "rr") {
        if (argc < 3) {
            std::cerr << "Please provide a time quantum for Round Robin\n";
            return 1;
        }
        int quantum = std::stoi(argv[2]);
        runRR(processes, quantum);
    } else if (algorithm == "priority") {
        std::vector<PriorityProcess> p = {
            {1, 0, 4, 2},
            {2, 1, 3, 1},
            {3, 2, 1, 3}
        };
        runPriority(p);
    } else if (algorithm == "priority_preemptive") {
        std::vector<PriorityProcess> p = {
            {1, 0, 4, 2},
            {2, 1, 3, 1},
            {3, 2, 1, 3}
        };
        runPriorityPreemptive(p);
    }

    // 🔹 Memory management algorithms
    else if (algorithm == "fifo" || algorithm == "lru" || algorithm == "optimal") {
        std::vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
        int frames = 3;

        if (algorithm == "fifo") {
            std::cout << "=== Running FIFO ===\n";
            runFIFO(frames, pages);
        } else if (algorithm == "lru") {
            std::cout << "=== Running LRU ===\n";
            runLRU(frames, pages);
        } else if (algorithm == "optimal") {
            std::cout << "=== Running Optimal ===\n";
            runOptimal(frames, pages);
        }
    }

    // 🔹 Syscall simulation
    else if (algorithm == "syscall") {
        std::cout << "=== Running Syscall Simulation ===\n";
        syscallDemo();
    }

    // 🔹 Threads simulation
    else if (algorithm == "threads") {
        runProducerConsumer();
    }

    // 🔹 Virtual memory paging simulation
    else if (algorithm == "paging") {
        std::vector<int> virtualAddresses = {
        0, 1023, 1024, 2047, 4095, 8191, 16383, 16384, 17000, -1
        };
        simulatePaging(virtualAddresses);
    }

    // ❌ Unknown algorithm
    else {
        std::cerr << "Unknown algorithm: " << algorithm << "\n";
        return 1;
    }

    return 0;
}
