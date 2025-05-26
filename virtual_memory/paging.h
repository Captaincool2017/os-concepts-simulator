#ifndef PAGING_H
#define PAGING_H

#include <vector>
#include <iostream>

const int PAGE_SIZE = 1024;
const int VIRTUAL_MEMORY_SIZE = 16 * 1024;
const int NUM_PAGES = VIRTUAL_MEMORY_SIZE / PAGE_SIZE;

struct PageTableEntry {
int frameNumber = -1;
bool valid = false;
};

void simulatePaging(const std::vector<int>& virtualAddresses);

#endif // PAGING_H
