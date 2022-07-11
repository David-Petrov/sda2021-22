/**
* NOTE: 70.00/100 - 3 WA
*/

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>

typedef unsigned long long ull;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull pancakes, chefs;
    std::cin >> pancakes >> chefs;

    std::vector<ull> chef_times(chefs);

    std::function<ull(ull)> calculate_count = [&](ull time) -> ull {
        ull count = 0;

        for (auto chef_time : chef_times) {
            count += time / chef_time;
        }

        return count;
    };

    for (ull i = 0; i < chefs; i++) {
        std::cin >> chef_times[i];
    }

    ull left = 0, right = ULLONG_MAX;
    ull middle, count;

    while (left < right - 1) {
        middle = right - ((right - left) >> 1);
        count  = calculate_count(middle);

        if (count >= pancakes) {
            right = middle;
        } else {
            left = middle;
        }
    }

    printf("%llu", middle + 1);

    return 0;
}
