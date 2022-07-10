#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

vector<int> times;

long long getPancakes(long long time) {
    long long sum = 0;

    for (const int t : times) {
        sum += time / t;
    }

    return sum;
}

struct Cook {
    int id, time;
};

int main() {
    long long n;
    int k;
    cin >> n >> k;

    times.resize(k);
    list<Cook> cooks;
    Cook c;
    for (int i = 0; i < k; ++i) {
        cin >> times[i];
    }

    long long lower = 1, upper = 1e13, mid;

    //cout << getPancakes(11);

    long long val;
    while (upper - lower > 1) {
        mid = (upper + lower) / 2;
        val = getPancakes(mid);

        if (val < n) {
            lower = mid;
        }
        else {
            upper = mid;
        }
    }

    if (val < n) {
        mid = upper;
    }

    cout << mid;

    return 0;
}
