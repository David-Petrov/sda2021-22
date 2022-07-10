#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    size_t n;
    cin >> n;

    vector<size_t> keys(n), doors(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> keys[i];
    }
    for (size_t i = 0; i < n; ++i) {
        cin >> doors[i];
    }

    size_t counter = 0;

    unordered_multiset<size_t> collectedKeys;

    for (size_t i = 0; i < n; ++i) {
        collectedKeys.insert(keys[i]);

        auto it = collectedKeys.find(doors[i]);

        if (it == collectedKeys.end()) {
            ++counter;
            continue;
        }

        collectedKeys.erase(it);
    }

    cout << counter;

    return 0;
}