#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int main() 
{
    size_t n, temp, maxDays = 0, tempMaxDays;
    cin >> n;

    vector<size_t> numbers(n);
    for (size_t i = 0; i < n; i++)
        cin >> numbers[i];
   
    stack<pair<size_t, size_t>> st;
    for (size_t i = 0; i < n; i++)
    {
        tempMaxDays = 0;
        temp = numbers[i];

        while (!st.empty() && st.top().first >= temp)
        {
            tempMaxDays = max(tempMaxDays, st.top().second);
            st.pop();
        }

        if (!st.empty())
        {
            st.top().second = max(tempMaxDays, st.top().second) + 1;
            maxDays = max(maxDays, st.top().second);
        }

        st.push({ temp, 0 });
    }

    cout << maxDays;
    return 0;
}