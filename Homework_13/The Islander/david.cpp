#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

typedef map<int, list<int>> Graph;
Graph graph;
unordered_set<int> visited;

void dfs(const int node) {
    if (!visited.insert(node).second) return;

    for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
        dfs(*it);
    }
}

bool isConnected() {
    visited.clear();
    dfs(graph.begin()->first);
    return visited.size() == graph.size();
}

int main() {
    int queries;
    cin >> queries;

    while (queries--) {
        int n, m;
        cin >> n >> m;
        
        graph.clear();
        map<int, int> degrees;

        int start, end;
        while (m--) {
            cin >> start >> end;
            graph[start].push_back(end);
            graph[end].push_back(start);
            ++degrees[start];
            ++degrees[end];
        }

        if (graph.size() != (size_t)n || !isConnected()) {
            cout << "none\n";
            continue;
        }

        int countOddDegreeNodes = 0;
        for (auto it = degrees.begin(); it != degrees.end(); ++it) {
            if (it->second % 2) {
                ++countOddDegreeNodes;
            }
        }

        switch (countOddDegreeNodes) {
        case 0:
            cout << "ecycle\n";break;
        case 2:
            cout << "epath\n";break;
        default:
            cout << "none\n";
        }
    }
    return 0;
}
