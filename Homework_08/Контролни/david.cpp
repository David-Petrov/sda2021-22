#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task {
    size_t startTime, duration;
};

struct TaskStartTimeEarlier {
    bool operator()(const Task& a, const Task& b) const {
        return a.startTime < b.startTime;
    }
};

struct TaskLonger {
    bool operator()(const Task& a, const Task& b) const {
        return a.duration > b.duration;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    long double waitSum = 0;
    vector<Task> tasks(n);
    for (size_t i = 0; i < n; i++) {
        cin >> tasks[i].startTime >> tasks[i].duration;
    }

    sort(tasks.begin(), tasks.end(), TaskStartTimeEarlier());

    priority_queue<Task, vector<Task>, TaskLonger> queuedForExecution;

    //start from the earliest task
    size_t currentIndex = 0;
    unsigned long long time = tasks[currentIndex].startTime;
    //while we have unqueued tasks OR queued for execution
    while (currentIndex < n || !queuedForExecution.empty()) {

        //queue tasks for execution in our minHeap
        while (currentIndex < n && tasks[currentIndex].startTime <= time) {
            queuedForExecution.push(tasks[currentIndex++]);
        }

        //if we couldn't enqueue any tasks and have none left, this means we have to simply wait and to nothing for the time of the next task
        if (queuedForExecution.empty()) {
            time = tasks[currentIndex].startTime;
            continue;
        }

        //otherwise execute the first priority task (the shortest one) and account for time change
        //cout << queuedForExecution.top().index << ' ';
        waitSum += time - queuedForExecution.top().startTime + queuedForExecution.top().duration;
        time += queuedForExecution.top().duration;

        queuedForExecution.pop();
    }

    cout << (unsigned long long)(waitSum / n);

    return 0;
}