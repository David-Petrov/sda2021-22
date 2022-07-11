#include <iostream>
#include <string>
#include <map>

int main() {

    size_t n;
    std::cin >> n;

    std::string *strings = new std::string[n];

    std::map<std::string, int> map;

    for (int i = 0; i < n; ++i) {
        std::cin >> strings[i];
        ++map[strings[i]];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", map[strings[i]]);
    }

    return 0;
}
