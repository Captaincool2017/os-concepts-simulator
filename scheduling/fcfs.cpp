#include "fcfs.h"

void runFCFS(const std::vector<Process>& processes) {
    int n = processes.size();
    std::vector<int> waitingTime(n), turnaroundTime(n);
    std::vector<std::string> gantt; // Stores the timeline as strings
    std::vector<int> startTimes(n); // For marking exact start times

    int currentTime = 0;

    std::cout << "[FCFS Scheduling]\n";

    for (int i = 0; i < n; ++i) {
        if (currentTime < processes[i].arrivalTime) {
            // CPU idle before next process arrives
            while (currentTime < processes[i].arrivalTime) {
                gantt.push_back("IDLE");
                ++currentTime;
            }
        }

        startTimes[i] = currentTime;
        waitingTime[i] = currentTime - processes[i].arrivalTime;

        for (int t = 0; t < processes[i].burstTime; ++t) {
            gantt.push_back("P" + std::to_string(processes[i].pid));
            ++currentTime;
        }

        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }

    // Print process table
    std::cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; ++i) {
        std::cout << processes[i].pid << "\t"
                  << processes[i].arrivalTime << "\t"
                  << processes[i].burstTime << "\t"
                  << waitingTime[i] << "\t"
                  << turnaroundTime[i] << "\n";
    }

    // Print Gantt Chart
    std::cout << "\nGantt Chart:\n| ";
    for (const auto& block : gantt) {
        std::cout << std::setw(5) << block << "| ";
    }

    std::cout << "\n0";
    for (size_t i = 1; i <= gantt.size(); ++i) {
        std::cout << std::setw(7) << i;
    }
    std::cout << "\n";
}
