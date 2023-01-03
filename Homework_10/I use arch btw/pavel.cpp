#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {
    private:
    std::unordered_set<size_t> nodes;
    std::unordered_map<size_t, std::list<size_t>> adjacent;

    public:
    Graph() : nodes(), adjacent() {}
    void add_edge(size_t left_vertex, size_t right_vertex) {
        this->nodes.insert(left_vertex);
        this->nodes.insert(right_vertex);
        this->adjacent[left_vertex].push_back(right_vertex);
    }

    bool isCyclic() {
        std::set<size_t> current;

        std::function<bool(const size_t &node)> util =
            [&](const size_t &node) -> bool {
            if (current.find(node) != current.end()) {
                return true;
            }

            current.insert(node);

            for (auto runner = this->adjacent[node].begin();
                 runner != this->adjacent[node].end(); ++runner) {

                if (util(*runner)) {
                    return true;
                }
            }

            current.erase(node);
            return false;
        };

        for (auto runner = this->nodes.begin(); runner != this->nodes.end();
             ++runner) {
            current.clear();
            if (util(*runner)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    size_t queries_count;
    std::cin >> queries_count;

    Graph graph;

    size_t edges, start, end;
    for (size_t i = 0; i < queries_count; ++i) {
        graph = Graph();

        std::cin >> edges;
        for (size_t j = 0; j < edges; ++j) {
            std::cin >> start >> end;
            graph.add_edge(start, end);
        }

        printf("%d ", graph.isCyclic());
    }

    return 0;
}
