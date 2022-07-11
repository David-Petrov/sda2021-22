#include <deque>
#include <iostream>
#include <queue>
#include <set>

struct Job {
    static size_t ID;
    size_t id;
    size_t offset;
    size_t duration;

    Job(size_t offset, size_t duration)
        : id(ID++), offset(offset), duration(duration) {}
    Job(const Job& job)
        : id(job.id), offset(job.offset), duration(job.duration) {}
};
size_t Job::ID = 0;

struct SortByOffset {
    bool operator()(const Job& lhs, const Job& rhs) const {
        return lhs.offset <= rhs.offset;
    }
};

struct SortByDuration {
    bool operator()(const Job& lhs, const Job& rhs) const {
        return lhs.duration > rhs.duration ||
               (lhs.duration == rhs.duration && lhs.id > rhs.id);
    }
};

int main() {
    size_t n;
    std::cin >> n;

    std::set<Job, ::SortByOffset> incoming_jobs;
    std::priority_queue<Job, std::deque<Job>, ::SortByDuration> available_jobs;

    size_t tempOffset, tempDuration;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> tempOffset >> tempDuration;
        incoming_jobs.emplace(tempOffset, tempDuration);
    }

    unsigned long long time = 0;

    while (!incoming_jobs.empty()) {
        if (available_jobs.empty() && time < incoming_jobs.begin()->offset) {
            time = incoming_jobs.begin()->offset;
        }

        while (!incoming_jobs.empty() &&
               incoming_jobs.begin()->offset <= time) {
            available_jobs.push(*incoming_jobs.begin());
            incoming_jobs.erase(incoming_jobs.begin());
        }

        time += available_jobs.top().duration;
        printf("%zu ", available_jobs.top().id);
        available_jobs.pop();
    }

    while (!available_jobs.empty()) {
        printf("%zu ", available_jobs.top().id);
        available_jobs.pop();
    }

    return 0;
}
