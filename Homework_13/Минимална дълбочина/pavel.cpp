#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adjacencyList(n);

    std::vector<int> degrees(n, 0);

    int start, end;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> start >> end;

        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);

        ++degrees[start];
        ++degrees[end];
    }

    std::queue<int> leaves;

    for (int i = 0; i < n; ++i) {
        if (degrees[i] == 1) {
            leaves.push(i);
        }
    }

    int currentLeavesSize, leavesSize = n;
    while (leavesSize > 2) {
        currentLeavesSize = leaves.size();
        leavesSize -= currentLeavesSize;

        for (int i = 0, front; i < currentLeavesSize; ++i) {
            front = leaves.front();
            leaves.pop();

            std::for_each(adjacencyList[front].begin(),
                          adjacencyList[front].end(),
                          [&degrees, &leaves](int neighbour) {
                              if (--degrees[neighbour] == 1) {
                                  leaves.push(neighbour);
                              }
                          });
        }
    }

    std::set<int> sorted;

    while (!leaves.empty()) {
        sorted.insert(leaves.front());
        leaves.pop();
    }

    std::for_each(sorted.begin(), sorted.end(),
                  [](int element) { printf("%d ", element); });

    return 0;
}
