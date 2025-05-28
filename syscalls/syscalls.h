// syscalls/syscalls.h
#pragma once
#include "pcb.h"
#include <vector>

extern std::vector<PCB> processTable;
extern int currentPID;

void syscallDemo();
