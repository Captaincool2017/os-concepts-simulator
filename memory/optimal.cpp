#include "optimal.h"

void runOptimal(int frames, const std::vector<int>& pages) {
    int pageFaults = 0;
    std::vector<int> memory;

    std::cout << "[Optimal] Step-by-step:\n";

    for (size_t i = 0; i < pages.size(); ++i) {
        int page = pages[i];
        bool found = false;

        for (int p : memory) {
            if (p == page) {
                found = true;
                break;
            }
        }

        std::cout << "Page " << page << ": ";

        if (!found) {
            pageFaults++;
            std::cout << "Page Fault\t";

            if ((int)memory.size() == frames) {
                int farthest = i + 1, indexToReplace = -1;

                for (int j = 0; j < frames; ++j) {
                    int k;
                    for (k = i + 1; k < (int)pages.size(); ++k) {
                        if (pages[k] == memory[j]) break;
                    }

                    if (k == (int)pages.size()) {
                        indexToReplace = j;
                        break;
                    } else if (k > farthest) {
                        farthest = k;
                        indexToReplace = j;
                    }
                }

                if (indexToReplace == -1) indexToReplace = 0;
                memory[indexToReplace] = page;
            } else {
                memory.push_back(page);
            }
        } else {
            std::cout << "Page Hit\t";
        }

        std::cout << "[ ";
        for (int p : memory) {
            std::cout << p << " ";
        }
        std::cout << "]\n";
    }

    std::cout << "[Optimal] Total Page Faults: " << pageFaults << "\n";
}
