#include <iostream>
#include <vector>
#include <map>

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    std::vector<int> row(cols);
    std::map<std::vector<int>, int> uniq;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> row[j];
        }

        ++uniq[row];
    }

    int count = 0;

    for (auto [key, value] : uniq) {
        if (value == 1) {
            ++count;
        }
    }

    printf("%d", count);

    return 0;
}
