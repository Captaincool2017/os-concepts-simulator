#include "lru.h"


void runLRU(int frames, const std::vector<int>& pages) {
    std::list<int> memory;
    std::unordered_map<int, std::list<int>::iterator> pageMap;
    int pageFaults = 0;

    std::cout << "[LRU] Step-by-step:\n";

    for (int page : pages) {
        std::cout << "Page " << page << ": ";

        if (pageMap.find(page) == pageMap.end()) {
            pageFaults++;
            std::cout << "Page Fault\t";

            if ((int)memory.size() == frames) {
                int lru = memory.back();
                memory.pop_back();
                pageMap.erase(lru);
            }

            memory.push_front(page);
            pageMap[page] = memory.begin();
        } else {
            std::cout << "Page Hit\t";

            memory.erase(pageMap[page]);
            memory.push_front(page);
            pageMap[page] = memory.begin();
        }

        std::cout << "[ ";
        for (int p : memory) {
            std::cout << p << " ";
        }
        std::cout << "]\n";
    }

    std::cout << "[LRU] Total Page Faults: " << pageFaults << "\n";
}
