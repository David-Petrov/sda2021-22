#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

typedef vector<list<int>> Graph;

int main() {
    int n;
    cin >> n;

    Graph graph(n);
    vector<int> degrees(n, 0);

    int start, end;

    for (int i = 0; i < n - 1; ++i) {
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
        ++degrees[start];
        ++degrees[end];
    }

    queue<int> leaves;

    for (int node = 0; node < n; ++node) {
        if (degrees[node] == 1) {
            leaves.push(node);
        }
    }

    int unvisitedNodesCount = n;

    int leavesCount, leaf;
    while (unvisitedNodesCount > 2) {
        leavesCount = leaves.size();
        unvisitedNodesCount -= leavesCount;

        while(leavesCount--)
        {
            leaf = leaves.front();
            leaves.pop();

            for (auto it = graph[leaf].begin(); it != graph[leaf].end(); ++it)
            {
                if (--degrees[*it] == 1) {
                    leaves.push(*it);
                }
            }
        }
    }

    vector<int> result;

    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }

    sort(result.begin(), result.end());

    for (const int r : result) {
        cout << r << ' ';
    }

    return 0;
}
