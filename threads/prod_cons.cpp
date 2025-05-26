// threads/prod_cons.cpp
#include "prod_cons.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

namespace {
    const int MAX_BUFFER_SIZE = 5;
    std::queue<int> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    bool done = false;

    void producer() {
        int data = 0;
        while (data < 10) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return buffer.size() < MAX_BUFFER_SIZE; });

            buffer.push(data);
            std::cout << "[Producer] Produced: " << data << "\n";
            data++;

            lock.unlock();
            cv.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        std::unique_lock<std::mutex> lock(mtx);
        done = true;
        lock.unlock();
        cv.notify_all();
    }

    void consumer() {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return !buffer.empty() || done; });

            while (!buffer.empty()) {
                int value = buffer.front();
                buffer.pop();
                std::cout << "          [Consumer] Consumed: " << value << "\n";
            }

            if (done && buffer.empty()) break;

            lock.unlock();
            cv.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    }
}

void runProducerConsumer() {
    std::cout << "=== Running Producer-Consumer Thread Simulation ===\n";
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}
