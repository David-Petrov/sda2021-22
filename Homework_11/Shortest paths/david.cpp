#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

typedef int TInput;
typedef unsigned long long ull;
typedef vector<deque<pair<TInput, int>>> Graph;

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    TInput parent, child, dist;
    vector<pair<ull, ull>> distances(n, { -1, 0 });

    while (m--) {
        cin >> parent >> child >> dist;
        --parent;
        --child;

        graph[parent].emplace_back(child, dist);
    }

    const TInput start = 0;
    const TInput target = n - 1;

    distances[start] = { 0, 1 };
    
    set<pair<ull, TInput>> Q;
    for (int i = 0; i < n; ++i) {
        Q.insert({distances[i].first, i});
    }

    ull newDist;
    TInput current;
    set<pair<ull, TInput>>::iterator it;

    while (!Q.empty()) {
        current = Q.begin()->second;
        Q.erase(Q.begin());

        if (current == target) {
            break;
        }

        auto& neighbours = graph[current];

        for (auto neighbour = neighbours.begin(); neighbour != neighbours.end(); ++neighbour) {

            const auto& distCurrent = distances[current];
            auto& distNeighbour = distances[neighbour->first];

            it = Q.find({ distNeighbour.first, neighbour->first });

            if (it == Q.end()) {
                continue;
            }

            newDist = distCurrent.first + neighbour->second;

            if (newDist < distNeighbour.first) {

                //recalculate the distance in our set
                Q.erase(it);
                Q.emplace(newDist, neighbour->first);

                //also refresh it in the distances vector
                distNeighbour = { newDist, distCurrent.second };
            }
            else if (newDist == distNeighbour.first) {
                //or otherwise increase the counter modulo 10^9 + 7, if we've found another path of the same shortest distance
                (distNeighbour.second += distCurrent.second) %= 1000000007;
            }
        }
    }

    if (distances[target].first == (ull)-1) {
        cout << -1 << ' ' << 0;
    }
    else {
        cout << distances[target].first << ' ' << distances[target].second;
    }

    return 0;
}