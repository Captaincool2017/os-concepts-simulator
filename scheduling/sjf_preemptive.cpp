#include "sjf_preemptive.h"

void runSJFPreemptive(const std::vector<Process>& input) {
    std::vector<Process> processes = input;
    int n = processes.size();
    std::vector<int> remaining(n);
    for (int i = 0; i < n; ++i) remaining[i] = processes[i].burstTime;

    int complete = 0, t = 0, minm = 1e9, shortest = 0;
    bool check = false;
    std::vector<int> waitingTime(n, 0), turnaroundTime(n, 0);

    std::vector<std::tuple<int, int, int>> gantt; // (pid, start, end)
    int prev = -1, start = 0;

    std::cout << "[SJF Preemptive Scheduling]\n";

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if (processes[j].arrivalTime <= t &&
                remaining[j] < minm &&
                remaining[j] > 0) {
                minm = remaining[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            if (prev != -1) {
                gantt.emplace_back(processes[prev].pid, start, t);
                prev = -1;
            }
            t++;
            continue;
        }

        // Gantt chart tracking
        if (prev != shortest) {
            if (prev != -1)
                gantt.emplace_back(processes[prev].pid, start, t);
            prev = shortest;
            start = t;
        }

        remaining[shortest]--;
        minm = remaining[shortest];
        if (minm == 0) minm = 1e9;

        if (remaining[shortest] == 0) {
            complete++;
            check = false;
            int finish_time = t + 1;
            waitingTime[shortest] = finish_time - processes[shortest].burstTime - processes[shortest].arrivalTime;
            if (waitingTime[shortest] < 0) waitingTime[shortest] = 0;
            turnaroundTime[shortest] = waitingTime[shortest] + processes[shortest].burstTime;
        }

        t++;
    }

    if (prev != -1)
        gantt.emplace_back(processes[prev].pid, start, t);

    // Output process metrics
    std::cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; ++i) {
        std::cout << processes[i].pid << "\t"
                  << processes[i].arrivalTime << "\t"
                  << processes[i].burstTime << "\t"
                  << waitingTime[i] << "\t"
                  << turnaroundTime[i] << "\n";
    }

    // Gantt chart
    std::cout << "\nGantt Chart:\n|";
    for (const auto& [pid, _, __] : gantt)
        std::cout << "  P" << pid << "  |";
    std::cout << "\n";

    std::cout << "0";
    for (const auto& [_, __, end] : gantt)
        std::cout << std::setw(7) << end;
    std::cout << "\n";
}
