#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

typedef int i32;
typedef unsigned long long u64;

typedef std::pair<i32, i32> pii;
typedef std::pair<u64, i32> pui;
typedef std::vector<pii> vpii;
typedef std::vector<pui> vpui;
typedef std::vector<vpii> vvpii;
typedef std::vector<vpui> vvpui;

std::vector<i32> dijkstra(i32, const vvpii &);

i32 main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i32 vertices, edges;
    std::cin >> vertices >> edges;

    vvpii graph(vertices + 1);  // +1 for special node
    i32 start, end, weight;
    for (i32 i = 0; i < edges; ++i) {
        std::cin >> start >> end >> weight;

        graph[start].emplace_back(end, weight);
        graph[end].emplace_back(start, weight);
    }

    i32 waters;
    std::cin >> waters;

    i32 water;
    for (i32 i = 0; i < waters; ++i) {
        std::cin >> water;

        graph[vertices].emplace_back(water, 0);
        graph[water].emplace_back(vertices, 0);
    }

    std::vector<int> distances = dijkstra(vertices, graph);

    i32 queries;
    std::cin >> queries;

    i32 query;
    for (i32 i = 0; i < queries; ++i) {
        std::cin >> query;

        printf("%d\n", distances[query]);
    }
}

std::vector<i32> dijkstra(i32 source, const vvpii &graph) {
    std::priority_queue<pui, vpui> shortest_paths;

    std::vector<i32> distances(graph.size(), INT_MAX);

    distances[source] = 0;
    shortest_paths.push({source, 0});

    while (!shortest_paths.empty()) {
        auto [current_vertex, current_weight] = shortest_paths.top();
        shortest_paths.pop();

        auto update = [&, current_vertex =
                              std::ref(current_vertex)](const pui &path) {
            auto [end, weight] = path;

            i32 &current_distance = distances[end];
            i32 adjacent_distance = distances[current_vertex.get()] + weight;

            if (adjacent_distance < current_distance) {
                current_distance = adjacent_distance;
                shortest_paths.push({end, current_distance});
            }
        };

        std::for_each(graph[current_vertex].begin(),
                      graph[current_vertex].end(), update);
    }

    return distances;
}
