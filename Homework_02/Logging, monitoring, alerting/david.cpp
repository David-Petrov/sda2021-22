#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Timestamp
{
public:
    size_t id;
    unsigned long long unified = 0;
    static size_t counter;

    static const unsigned long long multipliers[6];

    Timestamp(istream& input) : id(counter++)
    {
        size_t temp;
        char waste;
        for (int i = 0; i < 6; i++)
        {
            input >> temp;

            //don't discard between spaces though, it eats up the next digit
            if (i != 2 && i != 5)
                input >> waste;

            unified += temp * multipliers[i];
        }
    }

    bool operator<(const Timestamp& other) const
    {
        return unified < other.unified;
    }
};

size_t Timestamp::counter = 1;
//think of those as offsets for our number, so that we get the timestamp in as string-like number
const unsigned long long Timestamp::multipliers[6] = {10000ULL, 100ULL, 1ULL, 1000000ULL, 100000000ULL, 10000000000ULL};

int main()
{
    size_t n;
    cin >> n;

    vector<Timestamp> timestamps;
    timestamps.reserve(n);

    for (size_t i = 0; i < n; i++)
    {
        timestamps.push_back(Timestamp(cin));
    }

    stable_sort(timestamps.begin(), timestamps.end());

    for (const auto& ts : timestamps)
        cout << ts.id << endl;

    return 0;
}