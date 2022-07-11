#include <iostream>
#include <map>

int main() {

    size_t n;
    std::cin >> n;

    std::map<long, long> map;

    long temp;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        ++map[temp];
    }

    int sum = 0;
    for (auto runner = map.begin(); runner != map.end(); ++runner) {
        if (runner->second % 2) {
            sum += runner->first * runner->second;
        }
    }

    printf("%d", sum);

    return 0;
}
