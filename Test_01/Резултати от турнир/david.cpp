#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Match
{
public:
    size_t id;
    size_t first, second;
    static size_t counter;

    Match(size_t first, size_t second) : id(counter++), first(first), second(second) {}

    long double getPoints() const
    {
        return first * first / (double)second;
    }

    bool operator<(const Match& other) const
    {
        return getPoints() > other.getPoints()
            || (getPoints() == other.getPoints() && first > other.first);
    }
};

size_t Match::counter = 1;

int main()
{
    size_t n;
    cin >> n;

    vector<Match> matches;
    matches.reserve(n);

    size_t first, second;
    for (size_t i = 0; i < n; i++)
    {
        cin >> first >> second;
        matches.push_back(Match(first, second));
    }

    sort(matches.begin(), matches.end());

    for (const Match& match : matches)
    {
        cout << match.id << ' ';
    }

    return 0;
}