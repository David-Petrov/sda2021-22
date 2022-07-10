#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <list>
using namespace std;

typedef long long int ll;

class WeightedQuickUnion {
    int count;
    vector<int> parent;
    vector<int> size;

public:
    WeightedQuickUnion(int n) : count(n), parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int p) {
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    void connect(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) {
            return;
        }

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }
};

struct CostGain { ll cost, gain; };
struct Road { 
    int id, start, end;
    CostGain costGain;
};

struct RoadCostGreater {
    bool operator()(const Road& first, const Road& second) const {
        return first.costGain.cost > second.costGain.cost 
            || (first.costGain.cost == second.costGain.cost && first.costGain.gain < second.costGain.gain);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    WeightedQuickUnion uni(n);
    priority_queue<Road, vector<Road>, RoadCostGreater> roads;

    Road road;
    for (int i = 0; i < m; ++i) {
        road.id = i + 1;
        cin >> road.start >> road.end >> road.costGain.cost >> road.costGain.gain;

        --road.start;
        --road.end;

        roads.push(road);
    }

    set<int> result;
    while (!roads.empty()) {
        const Road currentRoad = roads.top();

        if (!uni.connected(currentRoad.start, currentRoad.end)) {
            uni.connect(currentRoad.start, currentRoad.end);
            result.insert(currentRoad.id);
        }

        roads.pop();
    }

    for (const int id : result) {
        cout << id << '\n';
    }

    return 0;
}