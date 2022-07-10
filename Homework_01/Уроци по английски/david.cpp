#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
    string word;
    cin >> word;

    int charsCount;
    cin >> charsCount;

    char fixed;
    cin >> fixed;


    size_t wordLen = word.length();
    size_t remainderLen = charsCount % wordLen;

    int occurencesInWord = 0;
    int occurencesInRemainder = 0;

    for (size_t i = 0; i < wordLen; i++)
    {
        if (word[i] != fixed)
            continue;

        if (i < remainderLen)
        {
            occurencesInRemainder++;
        }
            
        occurencesInWord++;
    }

    cout << occurencesInWord * (charsCount / wordLen) + occurencesInRemainder;

    return 0;
}