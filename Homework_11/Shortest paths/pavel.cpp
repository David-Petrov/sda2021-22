#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

#define MODULO 1000000007

typedef unsigned long long u64;
typedef int i32;

typedef std::pair<i32, i32> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;

std::pair<std::vector<u64>, std::vector<u64>> dijkstra(i32 source,
                                                       const vvpii &graph) {
    std::vector<u64> distances(graph.size(), ULLONG_MAX);
    std::vector<u64> routesFrom(graph.size(), 0);

    std::priority_queue<std::pair<u64, i32>, std::vector<std::pair<u64, i32>>,
                        std::greater<std::pair<u64, i32>>>
        shortest_distances;

    distances[source] = 0;
    routesFrom[source] = 1;
    shortest_distances.push({0, source});

    u64 current_distance;
    i32 current_node;
    while (!shortest_distances.empty()) {
        // Deconstruct the current shortest edge
        std::tie(current_distance, current_node) = shortest_distances.top();
        shortest_distances.pop();

        // Avoid reindexing same paths
        if (current_distance != distances[current_node]) {
            continue;
        }

        i32 vertex, weight;
        u64 adjacent_distance;
        std::for_each(
            graph[current_node].begin(), graph[current_node].end(),
            [&](auto pair) {
                std::tie(vertex, weight) = pair;
                adjacent_distance        = current_distance + weight;

                // If new path is shorter - relax
                if (adjacent_distance < distances[vertex]) {
                    distances[vertex] = adjacent_distance;
                    shortest_distances.push({adjacent_distance, vertex});

                    routesFrom[vertex] = routesFrom[current_node];

                    // If it is the same - increment counter
                } else if (adjacent_distance == distances[vertex]) {
                    (routesFrom[vertex] += routesFrom[current_node]) %= MODULO;
                }
            });
    }

    return {distances, routesFrom};
}

i32 main() {
    i32 vertices, edges;
    std::cin >> vertices >> edges;

    vvpii graph(vertices);

    i32 start, end, weight;
    for (i32 i = 0; i < edges; ++i) {
        std::cin >> start >> end >> weight;

        graph[start - 1].push_back({end - 1, weight});
    }

    std::vector<u64> distances;
    std::vector<u64> routesFrom;
    std::tie(distances, routesFrom) = dijkstra(0, graph);

    if (distances[vertices - 1] != ULLONG_MAX) {
        printf("%llu %llu", distances[vertices - 1], routesFrom[vertices - 1]);
    } else {
        printf("-1 0");
    }
}
