// syscalls/pcb.h
#pragma once
#include <string>

enum ProcessState {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

struct PCB {
    int pid;
    int ppid;
    ProcessState state;
    std::string name;
};
