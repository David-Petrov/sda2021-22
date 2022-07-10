#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void swap(T* p1, T* p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int placePivotAndGetIndex(int* arr, int first, int last)
{
    int pivot = arr[last];

    int i = first;

    for (int j = first; j < last; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(arr + i++, arr + j);
        }
    }

    swap(arr + i, arr + last);
    return i;
}

void qSort(int* arr, int first, int last)
{
    if (first >= last)
        return;

    int pivotIndex = placePivotAndGetIndex(arr, first, last);
    qSort(arr, first, pivotIndex - 1);
    qSort(arr, pivotIndex + 1, last);
}

int main()
{
    size_t n;
    cin >> n;

    int* numbers = new int[n];
    for (size_t i = 0; i < n; i++)
        cin >> numbers[i];

    size_t k;
    cin >> k;

    qSort(numbers, 0, n - 1);

    long sum = 0;

    for (size_t i = 0; i < k; i++)
        sum += numbers[i];

    cout << sum;

    delete[] numbers;

    return 0;
}