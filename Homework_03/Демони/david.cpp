#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Demon
{
    size_t a, d;
    bool operator>(const Demon& other) const { return a > other.a && d > other.d; }
    bool operator<(const Demon& other) const { return a < other.a && d < other.d; }
};

size_t lowerBound(std::vector<Demon>& demons, long start, long end, const Demon& key)
{
    long mid;
    while (end - start > 1) {
        mid = (start + end) / 2;
        (demons[mid] > key ? start : end) = mid;
    }
    return end;
}

size_t maximumDefeats(vector<Demon>& demons)
{
    vector<Demon> maxDefeatsSubseq(demons.size());
    size_t len = 1;

    maxDefeatsSubseq[0] = demons[0];
    for (size_t i = 1; i < demons.size(); i++)
    {
        maxDefeatsSubseq[
            demons[i] > maxDefeatsSubseq[0]         ? 0     :
            maxDefeatsSubseq[len - 1] > demons[i]   ? len++ : lowerBound(maxDefeatsSubseq, -1, len - 1, demons[i])
        ] = demons[i];
    }

    return len;
}

int main()
{
    size_t n;
    cin >> n;

    vector<Demon> demons(n);
    for (size_t i = 0; i < n; i++)
        cin >> demons[i].a >> demons[i].d;

    sort(demons.begin(), demons.end(), [](const Demon& first, const Demon& second) -> bool {
        return first.a > second.a || (first.a == second.a && first.d > second.d);
    });

    printf("%u", maximumDefeats(demons));
    return 0;
}