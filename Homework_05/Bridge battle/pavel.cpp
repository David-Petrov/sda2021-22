#include <iostream>
#include <deque>

int main() {
    size_t n;
    std::cin >> n;

    int *input = new int[n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> input[i];
    }
    std::deque<int> positives;

    int temp;
    for (size_t i = 0; i < n; ++i) {
        temp = input[i];

        // Push positive to queue
        if (temp > 0) {
            positives.push_front(temp);
            continue;
        }

        while (true) {
            // Pass the negative if no positives are alive
            if (positives.empty()) {
                std::cout << temp << ' ';
                break;
            }

            // Throw weaker positives
            if (-temp > positives.front()) {
                positives.pop_front();
                continue;
            }

            // Throw both if same power - pop positive and don't print negative
            if (-temp == positives.front()) {
                positives.pop_front();
            }

            // -temp < positives.front() -> break
            break;
        }
    }

    while (!positives.empty()) {
        std::cout << positives.back() << ' ';
        positives.pop_back();
    }

    delete[] input;

    return 0;
}
