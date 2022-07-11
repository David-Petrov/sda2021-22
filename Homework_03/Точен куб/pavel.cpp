#include <iostream>

long long closestPefectCube(long long n) {
    long guess = 1;

    while (guess * guess * guess <= n) {
        ++guess;
    }
    --guess;

    return guess * guess * guess;
}

long countPresents(long long n) {
    long count = 0;

    while (n > 0) {
        n -= closestPefectCube(n);
        ++count;
    }

    return count;
}

int main() {
    long long n;
    std::cin >> n;

    std::cout << countPresents(n) << std::endl;

    return 0;
}
