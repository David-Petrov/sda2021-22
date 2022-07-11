#include <iostream>

template<typename T>
void swap(T &val1, T &val2) {
    T temp = val1;
    val1   = val2;
    val2   = temp;
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i     = (left - 1);

    for (int j = left; j <= right - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);

        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

long solve(size_t giftCount, int *gifts, size_t employeeCount) {
    quickSort(gifts, 0, giftCount - 1);

    long neededMoney = 0;
    for (size_t i = 0; i < employeeCount; ++i) {
        neededMoney += gifts[i];
    }

    return neededMoney;
}

int main() {
    size_t giftCount;
    std::cin >> giftCount;

    int *gifts = new int[giftCount];

    for (size_t i = 0; i < giftCount; i++) {
        std::cin >> gifts[i];
    }

    size_t employeeCount;
    std::cin >> employeeCount;

    std::cout << solve(giftCount, gifts, employeeCount) << std::endl;

    delete[] gifts;

    return 0;
}
