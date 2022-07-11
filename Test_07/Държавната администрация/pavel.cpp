#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> freq;
    std::map<int, int> occur;

    std::vector<int> takiva;

    int temp;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;

        takiva.push_back(temp);

        ++freq[temp];
        if (occur.find(temp) == occur.end()) {
            occur[temp] = i;
        }
    }

    std::vector<int> unique;
    std::vector<int> dup;

    for (int i = 0; i < n; ++i) {
        int elem = takiva[i];

        if (freq[elem] > 1) {
            if (occur[elem] == i) {
                dup.push_back(elem);
            }
        } else {
            unique.push_back(elem);
        }
        // (entry.second > 1 ? dup : unique).push_back(entry.first);
    }

    std::for_each(unique.begin(), unique.end(),
                  [](int elem) { printf("%d ", elem); });

    std::for_each(dup.begin(), dup.end(),
                  [](int elem) { printf("%d ", elem); });

    return 0;
}
