#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task {
    size_t index, startTime, duration;
};

struct TaskStartTimeEarlier {
    bool operator()(const Task& a, const Task& b) const {
        return a.startTime < b.startTime;
    }
};

struct TaskLonger {
    bool operator()(const Task& a, const Task& b) const {
        return a.duration > b.duration || (a.duration == b.duration && a.index > b.index);
    }
};

int main() {

    size_t n;
    cin >> n;

    vector<Task> tasks(n);
    for (size_t i = 0; i < n; i++) {
        tasks[i].index = i;
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
        cout << queuedForExecution.top().index << ' ';
        time += queuedForExecution.top().duration;
        queuedForExecution.pop();
    }

    return 0;
}
