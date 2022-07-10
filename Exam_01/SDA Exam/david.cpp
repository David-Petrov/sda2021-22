#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

using Graph = vector<list<int>>;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;
        Graph graph(n);
        vector<int> dists(n, -1);

        int start, end;
        while (m--) {
            cin >> start >> end;
            --start; --end;
            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        int ivan;
        cin >> ivan;
        --ivan;

        queue<int> q;

        q.push(ivan);
        dists[ivan] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto it = graph[v].begin(); it != graph[v].end(); ++it) {
                if (dists[*it] > -1) continue;

                dists[*it] = dists[v] + 1;
                q.push(*it);
            }
        }

        for (const int d : dists) {
            if(d != 0)
            cout << (d == -1 ? -1 : d * 6) << ' ';
        }

        cout << '\n';
    }


    return 0;
}
