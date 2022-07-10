#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int mid(int a, int b)
{
    if (a > b)
    {
        swap(a, b);
    }

    return a + (b - a) / 2;
}

int main() {

    string chars;
    char fixed;

    cin >> chars;
    cin >> fixed;

    vector<int> fixedIndexes;
    for (int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == fixed)
        {
            fixedIndexes.push_back(i);
        }
    }

    size_t currentFixedIndex = 0;
    for (int i = 0; i < chars.length(); i++)
    {
        cout << abs(i - fixedIndexes[currentFixedIndex]) << ' ';

        if(currentFixedIndex < fixedIndexes.size() - 1 && i == mid(fixedIndexes[currentFixedIndex], fixedIndexes[currentFixedIndex + 1]))
        {
            currentFixedIndex++;
        }
    }

    return 0;
}
