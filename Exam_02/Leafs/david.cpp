#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

using Graph = unordered_map<int, list<int>>;

Graph graph;
vector<long long> sums;
vector<bool> visited;


void dfs(int src) {
    if (visited[src]) return;

    visited[src] = true;

    for (auto it = graph[src].begin(); it != graph[src].end(); ++it) {
        dfs(*it);
        sums[src] += (sums[*it] + *it + 1);
    }
}

int main() {
    int m, t;
    cin >> m >> t;

    unordered_map<int, int> degrees;

    int start, end;
    for(int i = 0; i < m; ++i) {
        cin >> start >> end;
        --start; --end;

        graph[start].push_back(end);

        graph[end];//just to invoke key creation

        degrees[end]++;
    }

    vector<int> queries(t);
    for (int& q : queries) {
        cin >> q;
    }

    int n = graph.size();
    sums.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; ++i) {
        if (degrees[i] == 0) {
            dfs(i);
       }
    }

    for (const int q : queries) {
        cout << sums[q - 1] << '\n';
    }
    


    return 0;
}
