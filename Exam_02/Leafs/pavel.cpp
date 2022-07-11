#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
    std::unordered_map<long long, std::vector<long long>> adjacency_list;
    std::unordered_map<long long, long long> initial_weights;
    std::unordered_map<long long, long long> total_weights;

    long long edges, queries;
    std::cin >> edges >> queries;

    std::function<long long(long long)> calculate_weights = [&](long long vertex) -> long long {
        if (total_weights[vertex]) {
            return total_weights[vertex];
        }

        long long sum = 0;
        for (auto child : adjacency_list[vertex]) {
            sum += initial_weights[child];
            sum += calculate_weights(child);
        }

        total_weights[vertex] = sum;
        return sum;
    };

    long long from, to;
    for (long long edge = 1; edge <= edges; edge++) {
        std::cin >> from >> to;

        adjacency_list[from].push_back(to);
        initial_weights[from] = from;
        initial_weights[to] = to;
    }

    for (auto [vertex, weight] : initial_weights) {
        calculate_weights(vertex);
    }

    long long query;
    for (long long _query = 0; _query < queries; _query++) {
        std::cin >> query;

        printf("%lld\n", total_weights[query]);
    }

    return 0;
}
