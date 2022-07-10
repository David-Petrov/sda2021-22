#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t findBestTopic(vector<size_t>& topics, size_t team)
{
    if (team <= topics[0])
        return topics[0];

    if (team >= topics[topics.size() - 1])
        return topics[topics.size() - 1];

    size_t start = 0, end = topics.size() - 1, mid, topic, nextTopic;

    do {
        mid = (start + end) / 2;
        topic = topics[mid];
        nextTopic = topics[mid + 1];

        if (topic <= team)
        {
            if (nextTopic >= team)
            {
                return team - topic > nextTopic - team ? nextTopic : topic;
            }

            start = mid;
        }
        else
        {
            end = mid;
        }

    } while (true);
}

int main()
{
    size_t n, m;
    cin >> n >> m;

    vector<size_t> topics(n);
    vector<size_t> teams(m);

    for (size_t i = 0; i < n; i++)
        cin >> topics[i];

    for (size_t i = 0; i < m; i++)
        cin >> teams[i];

    sort(topics.begin(), topics.end());

    for (const size_t team : teams)
        cout << findBestTopic(topics, team) << endl;

    return 0;
}