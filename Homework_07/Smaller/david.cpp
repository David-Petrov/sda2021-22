#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <iterator>
using namespace std;

typedef int TInput;
typedef map<TInput, queue<TInput>> Map;

int main() {
    TInput n, k;
    cin >> n >> k;

    vector<TInput> values(n), results(n, -1);

    for (TInput i = 0; i < n; i++) {
        cin >> values[i];
    }

    Map entries;
    pair<Map::iterator, bool> insertResult;

    for (TInput i = n - 1; i >= 0; --i) {
        insertResult = entries.emplace(values[i], initializer_list<TInput>({i}));

        auto it = insertResult.first;
        if (!insertResult.second) {
            it->second.push(i);
        }

        auto upperBound = entries.upper_bound(it->first + k);
        ++it;

        while(it != upperBound) {
            while (!it->second.empty()) {
                results[it->second.front()] = i;
                it->second.pop();
            }

            entries.erase(it++);
        }
    }

    for (const auto& num : results) {
        printf("%d ", num);
    }

    return 0;
}