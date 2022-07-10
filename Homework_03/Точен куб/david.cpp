#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef unsigned long long ull;

ull pow3(ull n)
{
    return n > 2097151 ? ULLONG_MAX : n * n * n; //check for overflow against 2^21 -1
}

ull closestCubeNumberLessThanOrEqualTo(const ull num)
{
    ull start = 1, end = num, mid, p, p1;

    do {
        mid = (start + end) / 2;
        p = pow3(mid);
        p1 = pow3(mid + 1);

        if (p <= num)
        {
            if (p1 > num)
            {
                return p;
            }
            
            start = mid;
        } 
        else
        {
            end = mid;
        }
    } while (true);
}

int main()
{
    ull pts;
    cin >> pts;

    ull num, count = 0;

    do {
        num = closestCubeNumberLessThanOrEqualTo(pts);
        count += pts / num;
    } while (pts %= num);

    cout << count;

    return 0;
}