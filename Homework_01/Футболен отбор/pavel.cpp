#include <algorithm>
#include <cstdint>
#include <iostream>

void solve(int *arr, size_t n) {
    std::sort(arr, arr + n, [](int n1, int n2) { return n1 < n2; });

    int min = 1;
    for (size_t i = 0; i < n; ++i) {
        if (arr[i] < min) {
            continue;
        }
        if (arr[i] == min) {
            ++min;
        } else {
            break;
        }
    }

    std::cout << min << std::endl;
}

int main() {
    size_t n;
    std::cin >> n;

    int *arr = new int[n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    solve(arr, n);

    delete[] arr;

    return 0;
}
