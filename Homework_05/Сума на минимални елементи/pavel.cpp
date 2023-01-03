#include <climits>
#include <iostream>

// Find min element in [left, right] (inclusive)
template<typename T>
long findMin(T *arr, size_t left, size_t right) {
    long tempMin = arr[left];
    for (size_t i = left + 1; i <= right; i++) {
        if (arr[i] < tempMin) {
            tempMin = arr[i];
        }
    }

    return tempMin;
}

int main() {
    size_t n, d;
    std::cin >> n >> d;

    long *arr    = new long[n];
    long tempMin = LLONG_MAX;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (i < d) {
            if (arr[i] < tempMin) {
                tempMin = arr[i];
            }
        }
    }

    long long sum = 0;
    for (size_t i = 0; i < n - d; ++i) {
        sum += tempMin;

        if (arr[i + d] < tempMin) {
            // new right-most is less than current min -> It is the new min
            tempMin = arr[i + d];
        } else if (arr[i] == tempMin) {
            // old left-most was the min -> Find new one
            tempMin = findMin(arr, i + 1, i + d);
        }
    }
    sum += tempMin;

    std::cout << sum;

    delete[] arr;

    return 0;
}
