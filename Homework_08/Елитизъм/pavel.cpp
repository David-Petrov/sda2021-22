#include <iostream>
#include <iomanip>
#include <queue>

typedef int T;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);

    int n;
    std::cin >> n;

    std::priority_queue<T, std::deque<T>, std::less<T>> min_queue;
    std::priority_queue<T, std::deque<T>, std::greater<T>> max_queue;

    double median = 0;

    T temp;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;

        if (median >= temp) {
            min_queue.push(temp);

            if (min_queue.size() - max_queue.size() > 1) {
                max_queue.push(min_queue.top());
                min_queue.pop();
            }
        } else {
            max_queue.push(temp);

            if (max_queue.size() - min_queue.size() > 1) {
                min_queue.push(max_queue.top());
                max_queue.pop();
            }
        }

        if (min_queue.size() == max_queue.size()) {
            median = (min_queue.top() + max_queue.top()) / 2.0;
        } else {
            median = (min_queue.size() > max_queue.size() ? min_queue.top()
                                                          : max_queue.top());
        }

        printf("%.1f\n", median);
    }

    return 0;
}
