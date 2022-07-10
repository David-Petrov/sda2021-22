#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

typedef long long int ll;
struct Edge { int endVertex, distance; };
typedef vector<deque<Edge>> Graph;

int main() {
    int n, m;
    cin >> n >> m;

    ++n; //we will be adding an extra vertex and connect it to all the vertices in T with a 0-weight-edge
    Graph graph(n);

    int startVertex, endVertex, distance;
    while (m--) {
        cin >> startVertex >> endVertex >> distance;
        graph[startVertex].push_back({endVertex, distance});
        graph[endVertex].push_back({startVertex, distance});
    }

    int k;
    cin >> k;
    vector<int> T(k);

    while (k--) {
        cin >> T[k];
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    for (const int vertex : T) {
        graph[n - 1].push_back({ vertex, 0 });
    }

    //dijkstra
    //initialize distances and visited vector
    vector<ll> distances(n, INT_MAX);
    distances[n - 1] = 0;
    vector<bool> visited(n, false);

    //initialize a priority queue to store shotest distances
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> unvisited;
    for (int i = 0; i < n; ++i) {
        unvisited.emplace(distances[i], i);
    }

    //proceed with Dijkstra
    ll newDist;
    int current;

    while (!unvisited.empty()) {
        current = unvisited.top().second;
        visited[current] = true;

        for (auto edge = graph[current].begin(); edge != graph[current].end(); ++edge) {

            if (visited[edge->endVertex]) {
                continue;
            }

            auto& distEndVertex = distances[edge->endVertex];
            newDist = (ll)distances[current] + edge->distance;

            if (newDist < distEndVertex) {
                unvisited.emplace(newDist, edge->endVertex);
                distEndVertex = newDist;
            }
        }

        while (!unvisited.empty() && visited[unvisited.top().second]) {
            unvisited.pop();
        }
    }
    //end Dijkstra and print results

    for (const int vertex : queries) {
        cout << distances[vertex] << '\n';
    }


    return 0;
}