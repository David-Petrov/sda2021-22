#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_set>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> queries(n);
    map<int, int> counts;
    list<int> un, rep;

    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    for (const int q : queries) {
        ++counts[q];
    }

    unordered_set<int> added;
    for (const int q : queries) {
        if (!added.insert(q).second) continue;
        (counts[q] == 1 ? un : rep).push_back(q);
    }

    for (const auto& l : { un, rep }) {
        for (const int u : l) {
            cout << u << ' ';
        }
    }

    return 0;
}
