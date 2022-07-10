#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {

    size_t n;
    cin >> n;

    vector<string> input(n);
    unordered_map<string, int> occurrences;

    for(size_t i = 0; i < n; ++i) {
        cin >> input[i];
        ++occurrences[input[i]];
    }

    for (const string& s : input) {
        cout << occurrences[s] << ' ';
    }


    return 0;
}
