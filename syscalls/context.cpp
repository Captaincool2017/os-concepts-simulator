#include "syscalls.h"
#include <iostream>
#include <thread>
#include <chrono>

std::vector<PCB> processTable;
int currentPID = 0;

int sys_fork() {
    int newPID = processTable.size();
    PCB parent = processTable[currentPID];

    PCB child;
    child.pid = newPID;
    child.ppid = parent.pid;
    child.state = READY;
    child.name = parent.name + "_child";

    processTable.push_back(child);
    std::cout << "Forked new process with PID " << newPID << "\n";
    return newPID;
}

void sys_exit() {
    processTable[currentPID].state = TERMINATED;
    std::cout << "Process " << currentPID << " exited.\n";
}

void sys_wait(int pid) {
    std::cout << "Waiting for PID " << pid << " to finish...\n";
    if (pid >= 0 && pid < (int)processTable.size()) {
        while (processTable[pid].state != TERMINATED) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulated blocking wait
        }
        std::cout << "Process " << pid << " finished.\n";
    }
}

void sys_printTable() {
    std::cout << "\nPID\tPPID\tState\t\tName\n";
    for (const auto& p : processTable) {
        std::cout << p.pid << "\t" << p.ppid << "\t";
        switch (p.state) {
            case NEW:        std::cout << "NEW\t\t"; break;
            case READY:      std::cout << "READY\t\t"; break;
            case RUNNING:    std::cout << "RUNNING\t\t"; break;
            case WAITING:    std::cout << "WAITING\t\t"; break;
            case TERMINATED: std::cout << "TERMINATED\t"; break;
        }
        std::cout << p.name << "\n";
    }
    std::cout << std::endl;
}

// 🔹 syscallDemo function for testing system call simulation
void syscallDemo() {
    // Create initial process
    PCB init;
    init.pid = 0;
    init.ppid = -1;
    init.state = RUNNING;
    init.name = "init";
    processTable.push_back(init);
    currentPID = 0;

    std::cout << "Initial process running with PID " << currentPID << "\n";
    sys_printTable();

    // Fork a child
    int childPID = sys_fork();
    sys_printTable();

    // Simulate child exit after delay
    std::cout << "Simulating child process work...\n";
    processTable[childPID].state = RUNNING;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    currentPID = childPID;
    sys_exit();
    sys_printTable();

    // Parent waits for child
    currentPID = 0;
    sys_wait(childPID);
    sys_printTable();
}
