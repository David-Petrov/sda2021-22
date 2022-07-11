#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::cin >> n;

    std::set<int> takovata;
    takovata.insert(0);

    std::pair<std::set<int>::iterator, bool> onakovata;
    int temp, minXOR = INT32_MAX;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        onakovata = takovata.insert(temp);

        if (onakovata.second) {
            if (onakovata.first == takovata.begin()) {
                minXOR = std::min(
                    minXOR, *onakovata.first ^ *std::next(onakovata.first));
            } else if (onakovata.first == std::prev(takovata.end())) {
                minXOR = std::min(
                    minXOR, *onakovata.first ^ *std::prev(onakovata.first));
            } else {
                minXOR = std::min(
                    minXOR,
                    std::min(*onakovata.first ^ *std::prev(onakovata.first),
                             *onakovata.first ^ *std::next(onakovata.first)));
            }
        }

        printf("%d\n", minXOR);
    }

    return 0;
}
