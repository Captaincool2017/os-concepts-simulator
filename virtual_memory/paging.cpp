#include "paging.h"

void simulatePaging(const std::vector<int>& virtualAddresses) {
    std::vector<PageTableEntry> pageTable(NUM_PAGES);
    int nextFreeFrame = 0;

    std::cout << "[Paging Simulation]\n";
    std::cout << "VirtAddr\tPage#\tOffset\tPhysAddr\tFrame#\n";

    for (int vAddr : virtualAddresses) {
        if (vAddr >= VIRTUAL_MEMORY_SIZE || vAddr < 0) {
            std::cout << vAddr << "\tInvalid virtual address\n";
            continue;
        }

        int pageNumber = static_cast<int>(vAddr / PAGE_SIZE);
        int offset = vAddr % PAGE_SIZE;

        if (!pageTable[pageNumber].valid) {
            pageTable[pageNumber].frameNumber = nextFreeFrame++;
            pageTable[pageNumber].valid = true;
        }

        int frameNumber = pageTable[pageNumber].frameNumber;
        int physicalAddress = frameNumber * PAGE_SIZE + offset;

        std::cout << vAddr << "\t\t"
                  << pageNumber << "\t"
                  << offset << "\t"
                  << physicalAddress << "\t\t"
                  << frameNumber << "\n";
    }
}
