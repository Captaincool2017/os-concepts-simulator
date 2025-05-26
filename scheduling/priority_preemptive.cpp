#include "priority_preemptive.h"

void runPriorityPreemptive(std::vector<PriorityProcess> processes) {
    int n = processes.size();
    std::vector<int> remaining(n), waiting(n, 0), turnaround(n, 0);
    std::vector<bool> completed(n, false);
    std::vector<int> timeline;  // Gantt chart timeline (store pid each unit)

    for (int i = 0; i < n; ++i)
        remaining[i] = processes[i].burstTime;

    int completedCount = 0;
    int currentTime = 0;

    std::cout << "[Preemptive Priority Scheduling]\n";
    std::cout << "PID\tPriority\tArrival\tBurst\tWaiting\tTurnaround\n";

    while (completedCount < n) {
        int idx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrivalTime <= currentTime &&
                !completed[i] &&
                remaining[i] > 0 &&
                processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            timeline.push_back(-1);  // Idle
            currentTime++;
            continue;
        }

        timeline.push_back(processes[idx].pid);
        remaining[idx]--;
        currentTime++;

        if (remaining[idx] == 0) {
            completed[idx] = true;
            completedCount++;

            int finishTime = currentTime;
            turnaround[idx] = finishTime - processes[idx].arrivalTime;
            waiting[idx] = turnaround[idx] - processes[idx].burstTime;

            std::cout << processes[idx].pid << "\t" << processes[idx].priority << "\t\t"
                      << processes[idx].arrivalTime << "\t" << processes[idx].burstTime << "\t"
                      << waiting[idx] << "\t" << turnaround[idx] << "\n";
        }
    }

    // Print Gantt Chart
    std::cout << "\nGantt Chart:\n| ";
    for (int pid : timeline) {
        if (pid == -1) std::cout << std::setw(5) << "IDLE" << " | ";
        else std::cout << std::setw(5) << ("P" + std::to_string(pid)) << "| ";
    }
    std::cout << "\n0";
    for (size_t i = 1; i <= timeline.size(); ++i) {
        std::cout << std::setw(7) << i;
    }
    std::cout << "\n";
}
