/**
* 	This solution had one test timing out due
*	to pure randomness :D
*	Solutions implementing merge sort as a sorting algorithm were
*	treated the full points, whereas the quicksort approach had one
*	disadvantageous test timing out.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void swap(T* p1, T* p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int placePivotAndGetIndex(vector<double>& arr, int first, int last)
{
    double pivot = arr[last];

    int i = first;

    for (int j = first; j < last; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i++], &arr[j]);
        }
    }

    swap(&arr[i], &arr[last]);
    return i;
}

void qSort(vector<double>& arr, int first, int last)
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

    vector<double> numbers;

    double temp;
    for (size_t i = 0; i < n; i++)
    {
        cin >> temp;
        numbers.push_back(temp);
    }

    qSort(numbers, 0, n - 1);

    int tempIndex = 0;
    cout << numbers[0] << ' ';
    for (size_t i = 1; i < n; i++)
    {
        if (numbers[i] == numbers[tempIndex])
        {
            continue;
        }

        cout << numbers[i] << ' ';
        tempIndex = i;
    }

    return 0;
}