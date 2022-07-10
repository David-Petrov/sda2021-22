#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {

    size_t n, r;
    cin >> n >> r;

    vector<ull> weights(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    unordered_map<ull, ull> singleNumberOccurences;
    unordered_map<ull, unordered_map<ull, ull>> pairOccurences;

    ull counter = 0, x;
    while (n-- > 0)
    {
        x = weights[n];

        counter += pairOccurences[r * x][r * r * x];
        pairOccurences[x][r * x] += singleNumberOccurences[r * x];
        ++singleNumberOccurences[x];
    }

    cout << counter;

    return 0;
}
