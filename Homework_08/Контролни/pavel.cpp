#include <deque>
#include <iostream>
#include <queue>
#include <set>

struct Homework {
    static size_t ID;
    size_t id;
    size_t offset;
    size_t duration;

    Homework(size_t offset, size_t duration)
        : id(ID++), offset(offset), duration(duration) {}
    Homework(const Homework& homework)
        : id(homework.id), offset(homework.offset),
          duration(homework.duration) {}
};
size_t Homework::ID = 0;

struct SortByOffset {
    bool operator()(const Homework& lhs, const Homework& rhs) const {
        return lhs.offset <= rhs.offset;
    }
};

struct SortByDuration {
    bool operator()(const Homework& lhs, const Homework& rhs) const {
        return lhs.duration > rhs.duration ||
               (lhs.duration == rhs.duration && lhs.id > rhs.id);
    }
};

int main() {
    size_t n;
    std::cin >> n;

    std::set<Homework, ::SortByOffset> incoming_homeworks;
    std::priority_queue<Homework, std::deque<Homework>, ::SortByDuration>
        available_homeworks;

    size_t tempOffset, tempDuration;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> tempOffset >> tempDuration;
        incoming_homeworks.emplace(tempOffset, tempDuration);
    }

    unsigned long long time       = 0;
    unsigned long long sumOfHoles = 0;

    while (!incoming_homeworks.empty()) {
        if (available_homeworks.empty() &&
            time < incoming_homeworks.begin()->offset) {
            time = incoming_homeworks.begin()->offset;
        }

        while (!incoming_homeworks.empty() &&
               incoming_homeworks.begin()->offset <= time) {
            available_homeworks.push(*incoming_homeworks.begin());
            incoming_homeworks.erase(incoming_homeworks.begin());
        }

        sumOfHoles += time - available_homeworks.top().offset + available_homeworks.top().duration;
        time += available_homeworks.top().duration;
        available_homeworks.pop();
    }

    while (!available_homeworks.empty()) {
        sumOfHoles += time - available_homeworks.top().offset + available_homeworks.top().duration;
        time += available_homeworks.top().duration;
        available_homeworks.pop();
    }

    printf("%llu\n", sumOfHoles / n);

    return 0;
}
