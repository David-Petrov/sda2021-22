#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;

    vector<int> widths(n, 0);
    deque<int> topView({ 0 });

    for (int i = 0; i < n; i++)
    {
        //handle left
        cin >> temp;
        if (temp > -1)
        {
            if ((widths[temp] = widths[i] - 1) < widths[topView.front()])
            {
                topView.push_front(temp);
            }  
        }
         
        //handle right
        cin >> temp;
        if (temp > -1)
        {
            if ((widths[temp] = widths[i] + 1) > widths[topView.back()])
            {
                topView.push_back(temp);
            }
        }
    }

    //print the top view
    while (!topView.empty())
    {
        cout << topView.front() << ' ';
        topView.pop_front();
    }
    
    return 0;
}