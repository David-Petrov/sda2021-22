#include <cmath>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Query {
    size_t startTime, duration;
};

struct QueryLongerDuration {
    bool operator()(const Query& a, const Query& b) const {
        return a.duration > b.duration;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<Query> tasks(n);
    for (size_t i = 0; i < n; i++) {
        tasks[i].startTime = i;
        cin >> tasks[i].duration;
    }

    priority_queue<Query, vector<Query>, QueryLongerDuration> queuedForExecution;

    size_t currentIndex = 0;
    unsigned long long time = tasks[currentIndex].startTime;
    int minW = INT_MAX, maxW = INT_MIN, wTime;

    while (currentIndex < n || !queuedForExecution.empty()) {
        while (currentIndex < n && tasks[currentIndex].startTime <= time) {
            queuedForExecution.push(tasks[currentIndex++]);
        }

        if (queuedForExecution.empty()) {
            time = tasks[currentIndex].startTime;
            continue;
        }

        wTime = time - queuedForExecution.top().startTime + queuedForExecution.top().duration;
        
        minW = min(minW, wTime);
        maxW = max(maxW, wTime);

        time += queuedForExecution.top().duration;

        queuedForExecution.pop();
    }

    cout << minW << ' ' << maxW;

    return 0;
}