#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int size;
    cin >> size;

    vector<int> numbers;

    int temp;
    for (int i = 0; i < size; i++)
    {
        cin >> temp;

        if (temp > 0)
        {
            numbers.push_back(temp);
        }
    }

    sort(numbers.begin(), numbers.end());

    //couldn't hold myself back from a tiny bit of validation
    if (numbers.size() == 0 || numbers[0] > 1)
    {
        cout << 1;
        return 0;
    }


    int result = numbers[numbers.size() - 1] + 1;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i + 1] - numbers[i] > 1)
        {
            result = numbers[i] + 1;
            break;
        }
    }

    cout << result;

    return 0;
}