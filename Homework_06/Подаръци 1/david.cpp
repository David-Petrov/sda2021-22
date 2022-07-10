#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

struct Worker { int bossIndex = -1, emloyeeCount = 0; };

int main() {

    int n, bossIndex, index;
    cin >> n;

    vector<Worker> hierarchy(n);

    for(int i = 0; i < n - 1; i++)
    {
        cin >> bossIndex >> index;

        hierarchy[index].bossIndex = bossIndex;

        while (bossIndex != -1)
        {
            ++hierarchy[bossIndex].emloyeeCount;
            bossIndex = hierarchy[bossIndex].bossIndex;
        }
    }

    cout << hierarchy[0].emloyeeCount << ' ';

    for (int i = 1; i < n && hierarchy[i].bossIndex != -1; ++i)
    {
        cout << hierarchy[i].emloyeeCount << ' ';
    }

    return 0;
}