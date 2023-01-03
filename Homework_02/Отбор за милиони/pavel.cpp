#include <algorithm>
#include <cstring>
#include <iostream>

#define RANGE 63

unsigned short decodeChar(char symbol) {
    if ('0' <= symbol && symbol <= '9') {
        return symbol - '0' + 1;
    }
    if ('a' <= symbol && symbol <= 'z') {
        return symbol - 'a' + 11;
    }
    if ('A' <= symbol && symbol <= 'Z') {
        return symbol - 'A' + 37;
    }

    return '\0';
}

void countSort(char *arr, size_t size) {
    size_t count[RANGE] = {};

    for (size_t i = 0; i < size; ++i) {
        ++count[decodeChar(arr[i])];
    }

    for (size_t i = 1; i < RANGE; ++i) {
        count[i] += count[i - 1];
    }

    char buffer[size];
    short temp;
    for (size_t i = 0; i < size; ++i) {
        temp = decodeChar(arr[i]);
        buffer[count[temp] - 1] = arr[i];
        --count[temp];
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = buffer[i];
    }
}

int main() {
    size_t n;
    std::cin >> n;

    char *members = new char[n + 1];

    std::cin >> members;

    countSort(members, n);

    std::cout << members;

    delete[] members;

    return 0;
}
