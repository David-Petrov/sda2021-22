#include <iostream>

void merge(int arr[], int l, int m, int r) {
    int sizeL = m - l + 1;
    int sizeR = r - m;

    int *arrL = new int[sizeL];
    int *arrR = new int[sizeR];

    // fill both subarrays
    for (int i = 0; i < sizeL; ++i) {
        arrL[i] = arr[l + i];
    }
    for (int i = 0; i < sizeR; ++i) {
        arrR[i] = arr[m + i + 1];
    }

    // merge into main arr while both subarrays have elements
    int srcL = 0, srcR = 0, dest = 0;
    while (srcL < sizeL && srcR < sizeR) {
        if (arrL[srcL] <= arrR[srcR]) {
            arr[l + dest] = arrL[srcL];
            ++srcL;
        } else {
            arr[l + dest] = arrR[srcR];
            ++srcR;
        }
        ++dest;
    }

    // fix leftover
    while (srcL < sizeL) {
        arr[l + dest] = arrL[srcL];
        ++srcL;
        ++dest;
    }
    while (srcR < sizeR) {
        arr[l + dest] = arrR[srcR];
        ++srcR;
        ++dest;
    }

    // free memory
    delete[] arrL;
    delete[] arrR;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        long m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    int temp = arr[0];
    std::cout << temp << ' ';
    for (int i = 0; i < n; ++i) {
        if (arr[i] == temp) {
            continue;
        }
        temp = arr[i];
        std::cout << temp << ' ';
    }

    return 0;
}
