#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

typedef unordered_map<int, deque<int>> Graph;

unordered_map<int, bool> visited;

bool dfs(int src, Graph& graph, set<int>& stack) {
    const auto& tmp = graph[src];
    visited[src] = true;
    stack.insert(src);

    for (auto it = tmp.begin(); it != tmp.end(); ++it) {

        if (stack.find(*it) != stack.end()) {
            return true;
        }

        if (!visited[*it]) {
            if (dfs(*it, graph, stack)) {
                return true;
            }
        }
    }

    stack.erase(src);

    return false;
}

bool isBroken(Graph& graph) {
    visited.clear();
    set<int> stack;

    for (auto it = graph.begin(); it != graph.end(); ++it) {
        if (!visited[it->first]) {
            if (dfs(it->first, graph, stack)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    size_t q;
    cin >> q;

    Graph graph;

    size_t n;
    int parent, child;
    while (q--) {
        graph.clear();

        cin >> n;

        while (n--) {
            cin >> parent >> child;
            graph[parent].push_back(child);
        }

        cout << isBroken(graph) << ' ';
    }
}
