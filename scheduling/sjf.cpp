#include "sjf.h"

void runSJF(const std::vector<Process>& input) {
    std::vector<Process> processes = input;
    int n = processes.size();
    std::vector<int> waitingTime(n), turnaroundTime(n);
    std::vector<bool> completed(n, false);
    std::vector<std::tuple<int, int, int>> gantt; // (pid, start, end)

    int currentTime = 0, completedCount = 0;

    std::cout << "[SJF Scheduling]\n";

    while (completedCount < n) {
        int idx = -1;
        int minBurst = 1e9;

        for (int i = 0; i < n; ++i) {
            if (!completed[i] && processes[i].arrivalTime <= currentTime) {
                if (processes[i].burstTime < minBurst ||
                    (processes[i].burstTime == minBurst && processes[i].arrivalTime < processes[idx].arrivalTime)) {
                    minBurst = processes[i].burstTime;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            int start = currentTime;
            waitingTime[idx] = currentTime - processes[idx].arrivalTime;
            currentTime += processes[idx].burstTime;
            int end = currentTime;

            turnaroundTime[idx] = waitingTime[idx] + processes[idx].burstTime;
            completed[idx] = true;
            completedCount++;

            gantt.emplace_back(processes[idx].pid, start, end);
        } else {
            currentTime++;  // No process ready yet
        }
    }

    std::cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; ++i) {
        std::cout << processes[i].pid << "\t"
                  << processes[i].arrivalTime << "\t"
                  << processes[i].burstTime << "\t"
                  << waitingTime[i] << "\t"
                  << turnaroundTime[i] << "\n";
    }

    // Gantt chart output
    std::cout << "\nGantt Chart:\n|";
    for (const auto& [pid, _, __] : gantt)
        std::cout << "  P" << pid << "  |";
    std::cout << "\n";

    std::cout << "0";
    for (const auto& [_, __, end] : gantt)
        std::cout << std::setw(7) << end;
    std::cout << "\n";
}
