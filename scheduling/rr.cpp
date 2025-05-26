#include "rr.h"

void runRR(const std::vector<Process>& input, int quantum) {
    std::vector<Process> processes = input;
    int n = processes.size();
    std::vector<int> remaining(n), waiting(n, 0), turnaround(n, 0);
    std::vector<std::tuple<int, int, int>> gantt; // {pid, start, end}

    for (int i = 0; i < n; ++i) remaining[i] = processes[i].burstTime;

    int time = 0;
    std::queue<int> q;
    std::vector<bool> inQueue(n, false);

    // Enqueue the first process
    q.push(0);
    inQueue[0] = true;

    std::cout << "[Round Robin Scheduling]\n";

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        int execTime = std::min(quantum, remaining[i]);
        gantt.emplace_back(processes[i].pid, time, time + execTime);

        remaining[i] -= execTime;
        time += execTime;

        for (int j = 0; j < n; ++j) {
            if (j != i && processes[j].arrivalTime <= time && remaining[j] > 0 && !inQueue[j]) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if (remaining[i] > 0) {
            q.push(i);
        } else {
            turnaround[i] = time - processes[i].arrivalTime;
            waiting[i] = turnaround[i] - processes[i].burstTime;
        }
    }

    // Print scheduling table
    std::cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; ++i) {
        std::cout << processes[i].pid << "\t"
                  << processes[i].arrivalTime << "\t"
                  << processes[i].burstTime << "\t"
                  << waiting[i] << "\t"
                  << turnaround[i] << "\n";
    }

    // Print Gantt chart
    std::cout << "\nGantt Chart:\n|";
    for (const auto& [pid, start, end] : gantt) {
        std::cout << std::setw(5) << "P" + std::to_string(pid) << " |";
    }
    std::cout << "\n" << std::get<1>(gantt[0]);
    for (const auto& entry : gantt) {
        std::cout << std::setw(7) << std::get<2>(entry); // end time
    }
    std::cout << "\n";
}
