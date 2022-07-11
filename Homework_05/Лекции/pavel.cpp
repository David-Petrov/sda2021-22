#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define RANGE 62

short decodeChar(char symbol) {
    if ('0' <= symbol && symbol <= '9') {
        return symbol - '0';
    }
    if ('a' <= symbol && symbol <= 'z') {
        return symbol - 'a' + 10;
    }
    if ('A' <= symbol && symbol <= 'Z') {
        return symbol - 'A' + 36;
    }

    return -1;
}

int main() {
    std::vector<int> first_encounter(RANGE, -1);

    char ch;
    short temp;
    size_t index = 0, finalCount = 0;
    while (true) {
        ch = std::cin.get();

        if (ch == '\n') {
            break;
        }

        temp = decodeChar(ch);

        // Never encountered
        if (first_encounter[temp] == -1) {
            // First encounter
            ++finalCount;
            first_encounter[temp] = index;
        } else if (first_encounter[temp] != -2) {
            // Duplicate
            --finalCount;
            first_encounter[temp] = -2;
        }

        ++index;
    }

    std::vector<size_t> indices(finalCount);
    for (size_t i = 0, dest = 0; i < RANGE; ++i) {
        if (first_encounter[i] >= 0) {
            indices[dest++] = first_encounter[i];
        }
    }

    std::sort(indices.begin(), indices.end());

    std::for_each(indices.begin(), indices.end(),
                  [](size_t index) { std::cout << index << ' '; });

    return 0;
}
