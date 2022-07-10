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
struct Tunnel {int endVertex, distance, kg;};
typedef vector<deque<Tunnel>> Graph;

Graph graph;
ll maxDistance;
int target, minWeight = -1;

bool thereIsPathForThisWeight(int kg) {
    const int n = graph.size();

    //initialize distances and visited vector
    vector<ll> distances(n, INT_MAX);
    vector<bool> visited(n, false);
    distances[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.emplace(0, 0);

    //proceed with Dijkstra
    ll newDist;
    int current;

    while (!Q.empty()) {

        current = Q.top().second;
        visited[current] = true;

        if (current == target) {
            break;
        }

        for (auto tunnel = graph[current].begin(); tunnel != graph[current].end(); ++tunnel) {

            if (tunnel->kg > kg || visited[tunnel->endVertex]) {
                continue;
            }

            auto& distNeighbour = distances[tunnel->endVertex];

            newDist = (ll)distances[current] + tunnel->distance;

            if (newDist < distNeighbour) {
                Q.emplace(newDist, tunnel->endVertex);
                distNeighbour = newDist;
            }
        }

        while (!Q.empty() && visited[Q.top().second]) {
            Q.pop();
        }
    }

    return distances[target] <= maxDistance;
}

void binarySearchMinWeight(int lowerBound, int upperBound)
{
    if (upperBound < lowerBound) {
        return;
    }

    int mid = lowerBound + (upperBound - lowerBound) / 2;

    if (thereIsPathForThisWeight(mid))
    {
        minWeight = mid;
        binarySearchMinWeight(lowerBound, mid - 1);
    }
    else {
        binarySearchMinWeight(mid + 1, upperBound);
    }
}

int main() {
    int n, m;
    cin >> n >> m >> maxDistance;

    graph.resize(n);
    target = n - 1;

    int startVertex, maxWeight = INT_MIN;
    Tunnel tunnel;
    while (m--) {
        cin >> startVertex >> tunnel.endVertex >> tunnel.kg >> tunnel.distance;
        --startVertex;
        --tunnel.endVertex;
        graph[startVertex].push_back(tunnel);
        maxWeight = max(tunnel.kg, maxWeight);
    }

    binarySearchMinWeight(0, maxWeight);

    cout << minWeight;

    return 0;
}