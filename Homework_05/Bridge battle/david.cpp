#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    size_t n, size = 0;

    cin >> n;

    int temp, * elements = new int[n], * input = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for(size_t i = 0; i < n; i++)
    {
        temp = input[i];

        if (temp > 0)
        {
            elements[size++] = temp;
            continue;
        }

        while (size > 0 && elements[size - 1] < -temp)
        {
            --size;
        }

        if (size == 0)
        {
            printf("%d ", temp);
            continue;
        }

        if (elements[size - 1] == -temp)
        {
            --size;
        }
    }

    for (size_t i = 0; i < size; ++i)
        printf("%d ", elements[i]);

    delete[] elements;
    delete[] input;

    return 0;
}