#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
using namespace std;

typedef vector<deque<int>> Graph;

vector<bool> visited;

void dfs(int src, Graph& graph) {

    if (visited[src]) return;

    visited[src] = true;

    for (auto it = graph[src].begin(); it != graph[src].end(); ++it) {
        if (!visited[*it]) {
            dfs(*it, graph);
        }
    }
}

int countComponents(Graph& graph) {
    vector<bool> stack(graph.size(), false);
    int counter = 0;

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            ++counter;
            dfs(i, graph);
        }
    }

    return counter;
}

int main() {
    size_t q;
    cin >> q;

    int n, m;
    while (q--) {
        cin >> n >> m;
        Graph graph(n);
        visited.clear();
        visited.resize(n, false);
        
        int parent, child;
        while (m--) {
            cin >> parent >> child;
            graph[child].push_back(parent);
            graph[parent].push_back(child);
        }

        cout << countComponents(graph) << ' ';
    }
}