#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <list>
using namespace std;

typedef unsigned long long ull;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<list<ull>>> graph(n, vector<list<ull>>(n));

    int start, end, weight;
    while (m--) {
        cin >> start >> end >> weight;

        graph[start][end].push_back(weight);
    }

    int k;
    cin >> k;

    unordered_set<int> nums;

    int num;
    while (k--) {
        cin >> num;
        nums.insert(num);
    }

    int t;
    cin >> t;

    vector<bool> result(t);

    for (int i = 0; i < t; ++i) {
        int l;
        cin >> l;

        vector<int> route(l);

        for (int j = 0; j < l; j++)
        {
            cin >> route[j];
        } 

        bool r = true;
        for (int j = 0; j < l - 1; ++j) {

            const list<ull>& edges = graph[route[j]][route[j + 1]];

            bool found = false;
            for (const int e : edges) {
                if (nums.find(e) == nums.end()) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                r = false;
                break;
            }
        }

        result[i] = r;
    }

    for (const bool r : result) {
        cout << r;
    }

    return 0;
}
