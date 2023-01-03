#include <functional>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int vertices, edges;
    std::cin >> vertices >> edges;

    std::vector<int> parents(vertices + 1);
    for (int i = 0; i < vertices; ++i) {
        parents[i] = i;
    }

    std::vector<std::pair<int, int>> pairs(edges);
    int start, end;
    for (int i = 0; i < edges; ++i) {
        std::cin >> start >> end;
        pairs[i] = {start, end};
    }

    std::function<int(int)> find_root = [&parents, &find_root](int vertex) {
        if (parents[vertex] == vertex) {
            return vertex;
        }

        return find_root(parents[vertex]);
    };

    std::function<void(std::pair<int, int>)> connect =
        [&parents, &find_root](std::pair<int, int> nodes) {
            int node_1_root = find_root(nodes.first),
                node_2_root = find_root(nodes.second);

            if (node_1_root == node_2_root) {
                return;
            }

            parents[node_2_root] = node_1_root;
        };

    for (int i = 0; i < edges; ++i) {
        connect(pairs[i]);
    }

    int queries;
    std::cin >> queries;

    int isNew;
    for (int i = 0; i < queries; ++i) {
        std::cin >> isNew >> start >> end;

        if (isNew - 1) {
            connect({start, end});
        } else {
            printf("%d", find_root(start) == find_root(end));
        }
    }
}
