#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<size_t, int> Tuple;

constexpr int charIndex(const char c)
{
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'z') return 10 + c - 'a';
    if ('A' <= c && c <= 'Z') return 36 + c - 'A';

    return c;
}

int main() {
    char lecture;
    vector<Tuple> charIndices(62, {-1, -1});

    int i = 0;
    while (cin.get(lecture) && !isspace(lecture))
    {
        Tuple& temp = charIndices[charIndex(lecture)];
        ++temp.first;
        temp.second = i++;
    }

    sort(charIndices.begin(), charIndices.end());

    i = 0;
    while (i < 62 && charIndices[i].first == 0)
        cout << charIndices[i++].second << ' ';

    return 0;
}