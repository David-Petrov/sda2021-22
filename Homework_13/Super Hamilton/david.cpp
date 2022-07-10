#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct Node {
    int id;
    char val;
    bool operator<(const Node& other) const { return id < other.id; }
};

vector<set<Node>> graph;
vector<bool> visited;
int validPaths = 0;
int requiredKeysCount = 0;

void searchForPrincess(Node start, int keys = 0) {
    if (visited[start.id]) return;

    visited[start.id] = true;
    for (auto it = graph[start.id].begin(); it != graph[start.id].end(); ++it) {

        if (it->val == 'e') {
            if (keys == requiredKeysCount) ++validPaths;
            continue;
        }

        searchForPrincess(*it, keys + 1);
    }
    visited[start.id] = false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Node>> matrix(n, vector<Node>(m));

    pair<int, int> start;


    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;

            matrix[i][j] = { i * m + j, c };

            if (matrix[i][j].val == 's') start = { i, j };
            else if (matrix[i][j].val == '-') ++requiredKeysCount;
        }
    }

    graph.resize(n * m);
    visited.resize(n * m, false);

    queue<pair<int, int>> q;
    q.push(start);

    pair<int, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        Node curNode = matrix[cur.first][cur.second];

        for (const auto next : { 
            pair<int, int>{cur.first - 1, cur.second},
            pair<int, int>{cur.first + 1, cur.second},
            pair<int, int>{cur.first, cur.second - 1},
            pair<int, int>{cur.first, cur.second + 1},
            
        }) {
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;

            Node node = matrix[next.first][next.second];

            if (visited[node.id] || node.val == 'x') continue;

            graph[curNode.id].insert(node);
            graph[node.id].insert(curNode);
            q.push(next);
        }

        visited[curNode.id] = true;
    }

    visited.clear();
    visited.resize(n * m, false);
    searchForPrincess(matrix[start.first][start.second]);

    cout << validPaths;

    return 0;
}
