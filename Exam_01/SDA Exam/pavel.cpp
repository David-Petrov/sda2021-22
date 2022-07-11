#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::vector<int> parents;

    int queries;
    std::cin >> queries;

    for (int i = 0; i < queries; i++) {
        int vertices, edges;
        std::cin >> vertices >> edges;

        std::vector<std::vector<int>> adjacency_list(vertices);

        int from, to;
        for (int edge = 0; edge < edges; edge++) {
            std::cin >> from >> to;
            --from;
            --to;

            adjacency_list[from].push_back(to);
            adjacency_list[to].push_back(from);
        }

        int ivan;
        std::cin >> ivan;
        --ivan;

        std::vector<int> distances(vertices, -1);
        distances[ivan] = 0;
        std::queue<int> wave;
        wave.push(ivan);
        int distance = 6;

        while(!wave.empty()) {
            int size = wave.size();

            for (int i = 0; i < size; ++i) {
                for (auto child : adjacency_list[wave.front()]) {
                    if (distances[child] == -1) {
                        wave.push(child);
                        distances[child] = distance;
                    }
                }
                wave.pop();
            }

            distance += 6;
        }

        for (auto final_distance : distances) {
            if (final_distance) {
                printf("%d ", final_distance);
            }
        }

        printf("\n");
    }

    return 0;
}
