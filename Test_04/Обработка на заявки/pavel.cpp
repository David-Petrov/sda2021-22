#include <cstdint>
#include <deque>
#include <iostream>
#include <list>
#include <queue>

struct Task {
    size_t offset;
    size_t duration;

    Task(size_t offset, size_t duration) : offset(offset), duration(duration) {}
    Task(const Task& task) : offset(task.offset), duration(task.duration) {}
};

struct SortByDuration {
    bool operator()(const Task& lhs, const Task& rhs) const {
        return lhs.duration > rhs.duration;
    }
};

int main() {
    size_t n;
    std::cin >> n;

    std::list<Task> incoming_tasks;
    std::priority_queue<Task, std::deque<Task>, ::SortByDuration>
        available_tasks;

    size_t tempDuration;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> tempDuration;
        incoming_tasks.emplace_back(i, tempDuration);
    }

    unsigned long long time    = 0;
    unsigned long long minWait = -1, maxWait = 0;

    while (!incoming_tasks.empty()) {
        if (available_tasks.empty() && time < incoming_tasks.begin()->offset) {
            time = incoming_tasks.begin()->offset;
        }

        while (!incoming_tasks.empty() &&
               incoming_tasks.begin()->offset <= time) {
            available_tasks.push(*incoming_tasks.begin());
            incoming_tasks.erase(incoming_tasks.begin());
        }

        minWait = std::min(minWait, time - available_tasks.top().offset + available_tasks.top().duration);
        maxWait = std::max(maxWait, time - available_tasks.top().offset + available_tasks.top().duration);
        time += available_tasks.top().duration;
        available_tasks.pop();
    }

    while (!available_tasks.empty()) {
        minWait = std::min(minWait, time - available_tasks.top().offset + available_tasks.top().duration);
        maxWait = std::max(maxWait, time - available_tasks.top().offset + available_tasks.top().duration);
        time += available_tasks.top().duration;
        available_tasks.pop();
    }

    printf("%llu %llu\n", minWait, maxWait);

    return 0;
}
