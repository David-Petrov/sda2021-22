#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

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

    void unite(int p, int q) {
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

struct Query { int type, start, end; };

int main()
{
    int n, m;
    cin >> n >> m;

    WeightedQuickUnion uni(n);

    for (int start, end, i = 0; i < m; ++i) {
        cin >> start >> end;
        uni.unite(--start, --end);
    }

    int q;
    cin >> q;

    vector<Query> queries(q);
    for(int i = 0; i < q; ++i) {
        Query& query = queries[i];
        cin >> query.type >> query.start >> query.end;

        --query.start;
        --query.end;
    }

    for (const Query& query : queries) {
        if (query.type == 2) {
            uni.unite(query.start, query.end);
        }
        else {
            cout << uni.connected(query.start, query.end);
        }
    }

    return 0;
}