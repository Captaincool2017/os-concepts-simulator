#include "fifo.h"

void runFIFO(int frames, const std::vector<int>& pages) {
    std::queue<int> memoryQueue;
    std::unordered_set<int> memorySet;

    int pageFaults = 0;

    std::cout << "[FIFO] Step-by-step:\n";

    for (int page : pages) {
        std::cout << "Page " << page << ": ";

        if (memorySet.find(page) == memorySet.end()) {
            pageFaults++;
            std::cout << "Page Fault\t";

            if ((int)memorySet.size() == frames) {
                int oldest = memoryQueue.front();
                memoryQueue.pop();
                memorySet.erase(oldest);
            }

            memoryQueue.push(page);
            memorySet.insert(page);
        } else {
            std::cout << "Page Hit\t";
        }

        // Print current memory
        std::queue<int> temp = memoryQueue;
        std::cout << "[ ";
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << "]\n";
    }

    std::cout << "[FIFO] Total Page Faults: " << pageFaults << "\n";
}
