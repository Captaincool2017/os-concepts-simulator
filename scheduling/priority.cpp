#include "priority.h"

void runPriority(const std::vector<PriorityProcess>& processes) {
    auto p = processes;
    int n = p.size();
    std::vector<bool> done(n, false);
    std::vector<int> waiting(n), turnaround(n), completion(n);
    int completed = 0;
    int currentTime = 0;
    std::vector<std::pair<int, int>> gantt; // {pid, startTime}

    std::cout << "[Priority Scheduling]\n";
    std::cout << "PID\tPriority\tArrival\tBurst\tWaiting\tTurnaround\n";

    while (completed < n) {
        int idx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (!done[i] && p[i].arrivalTime <= currentTime) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process available to schedule
            currentTime++;
            continue;
        }

        int start = currentTime;
        waiting[idx] = currentTime - p[idx].arrivalTime;
        if (waiting[idx] < 0) waiting[idx] = 0;

        currentTime += p[idx].burstTime;
        turnaround[idx] = currentTime - p[idx].arrivalTime;
        completion[idx] = currentTime;
        done[idx] = true;
        completed++;

        gantt.emplace_back(p[idx].pid, start);

        std::cout << p[idx].pid << "\t" << p[idx].priority << "\t\t"
                  << p[idx].arrivalTime << "\t" << p[idx].burstTime << "\t"
                  << waiting[idx] << "\t" << turnaround[idx] << "\n";
    }

    // Gantt Chart
    std::cout << "\nGantt Chart:\n| ";
    for (auto& [pid, _] : gantt) {
        std::cout << std::setw(5) << "P" + std::to_string(pid) << "| ";
    }
    std::cout << "\n" << gantt[0].second;
    for (size_t i = 0; i < gantt.size(); ++i) {
        int endTime = (i + 1 < gantt.size()) ? gantt[i + 1].second : completion[gantt[i].first - 1];
        std::cout << std::setw(7) << endTime;
    }
    std::cout << "\n";
}
