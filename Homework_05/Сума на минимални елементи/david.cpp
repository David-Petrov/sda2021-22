#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
using namespace std;

int main() 
{
    int n, d, temp;
    long long sum = 0;
    deque<pair<int, int>> minimums;

    cin >> n >> d;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;

        while (!minimums.empty() && minimums.back().first >= temp) 
            minimums.pop_back();

        minimums.emplace_back(temp, i);

        if (i >= d - 1) 
            sum += minimums.front().first;

        while (!minimums.empty() && minimums.front().second <= i - d + 1) 
            minimums.pop_front();
    }
    cout << sum << endl;
    return 0;
}