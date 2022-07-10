#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

typedef size_t TInput;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    size_t n;
    cin >> n;

    priority_queue<TInput, vector<TInput>, less<TInput>> maxHeap;
    priority_queue<TInput, vector<TInput>, greater<TInput>> minHeap;

    TInput temp;
    double median = 0;
    while (n-- > 0) {
        cin >> temp;

        switch ((long)maxHeap.size() - (long)minHeap.size()) {
        
        case 0:

            if (temp < median) {
                maxHeap.push(temp);
                median = maxHeap.top();
            }
            else {
                minHeap.push(temp);
                median = minHeap.top();
            }
            break;

        case 1:

            if (temp < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(temp);
            }
            else {
                minHeap.push(temp);
            }
            median = (minHeap.top() + maxHeap.top()) / 2.;
            break;

        default:
            if (temp <= median) {
                maxHeap.push(temp);
            }
            else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(temp);
            }

            median = (minHeap.top() + maxHeap.top()) / 2.;
        }

        cout << median << '\n';
    }

    return 0;
}