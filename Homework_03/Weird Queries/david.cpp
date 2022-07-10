#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t upperBound(vector<size_t>& numbers, size_t key)
{
    size_t end = numbers.size(), start = 0, mid;

    while (end - start > 1)
    {
        mid = (start + end) / 2;
        (numbers[mid] <= key ? start : end) = mid;
    }

    return end;
}

size_t getQueryCount(vector<size_t>& numbers, size_t s, size_t p)
{
    size_t maxIndex = upperBound(numbers, p) - 1, sum = 0, i;

    for (i = maxIndex + 1; i > 0; --i)
        if ((sum += numbers[i - 1]) > s)
            break;

    return maxIndex - i + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, q, i;
    cin >> n >> q;

    vector<size_t> numbers(n);

    for (i = n; i > 0; --i)
    {
        cin >> numbers[n - i];
    }

    sort(numbers.begin(), numbers.end());

    for (i = q; i > 0; --i)
    {
        cin >> n >> q;
        printf("%u\n", getQueryCount(numbers, n, q));
    }

    return 0;
}