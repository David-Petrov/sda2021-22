#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

constexpr size_t getIndex(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';

    if ('a' <= c && c <= 'z')
        return 10 + c - 'a';

    return 36 + c - 'A';
}

constexpr char getChar(size_t i)
{
    if (0 <= i && i < 10)
        return '0' + i;

    if (10 <= i && i < 36)
        return 'a' + i - 10;

    return 'A' + i - 36;
}

size_t counts[62] = {};

int main()
{
    size_t n;
    cin >> n;

    string input;
    cin >> input;

    for (int i = 0; i < n; i++)
    {
        ++counts[getIndex(input[i])];
    }

    for (int i = 0; i < 62; i++)
    {
        cout << string(counts[i], getChar(i));
    }

    return 0;
}