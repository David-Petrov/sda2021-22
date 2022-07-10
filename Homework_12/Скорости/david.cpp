#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class WeightedQuickUnion {
    int count;
    const int size;
    vector<int> parents;
    vector<int> sizes;

public:
    WeightedQuickUnion(int n) : count(n), size(n), parents(n), sizes(n, 1) {
        reset();
    }

    int getCount() const {
        return count;
    }

    void reset();
    int find(int p);

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    bool connect(int p, int q);
};

int WeightedQuickUnion::find(int p) {
    while (p != parents[p]) {
        p = parents[p];
    }
    return p;
}

void WeightedQuickUnion::reset() {
    count = size;
    for (int i = 0; i < size; i++) {
        sizes[i] = 1;
        parents[i] = i;
    }
}

bool WeightedQuickUnion::connect(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);

    if (rootP == rootQ) {
        return false;
    }

    if (sizes[rootP] < sizes[rootQ]) {
        parents[rootP] = rootQ;
        sizes[rootQ] += sizes[rootP];
    }
    else {
        parents[rootQ] = rootP;
        sizes[rootP] += sizes[rootQ];
    }

    --count;
    return true;
}

struct Road { 
    int start, end, optimalSpeed;

    Road() : start(), end(), optimalSpeed() {}
    Road(const Road& other, int newOptimalSpeed) : start(other.start), end(other.end), optimalSpeed(newOptimalSpeed) {}
};

struct RoadOptimalSpeedLess {
    bool operator()(const Road& first, const Road& second) const {
        return first.optimalSpeed < second.optimalSpeed;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    WeightedQuickUnion uni(n);
    multiset<Road, RoadOptimalSpeedLess> roads;

    Road temp;
    while(m--) {
        cin >> temp.start >> temp.end >> temp.optimalSpeed;
        --temp.start;
        --temp.end;
        roads.insert(temp);
    }

    pair<int, int> minSpeedAndDifference = {0, INT_MAX};
    int minSpeed, maxSpeedDifference;

    while(!roads.empty()) {

        uni.reset();
        minSpeed = roads.begin()->optimalSpeed;
        maxSpeedDifference = INT_MIN;

        for (const Road& currentRoad : roads) {
            if (uni.connect(currentRoad.start, currentRoad.end)) {
                maxSpeedDifference = max(maxSpeedDifference, currentRoad.optimalSpeed - minSpeed);

                //how the hell did I forget you for so long, god damn it... 
                //crucial mid-cycle break check... :D
                if (maxSpeedDifference >= minSpeedAndDifference.second) {
                    break;
                }
            }
        }

        roads.erase(roads.begin());

        if (uni.getCount() > 1) {
            continue;
        }

        if (maxSpeedDifference < minSpeedAndDifference.second) {
            minSpeedAndDifference = { minSpeed, maxSpeedDifference };
        } 
    }

    cout << minSpeedAndDifference.first << ' ' << (minSpeedAndDifference.first + minSpeedAndDifference.second);
    return 0;
}