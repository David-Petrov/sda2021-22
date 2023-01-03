#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

typedef int i32;
typedef unsigned long long u64;

struct Tunnel {
    i32 end;
    i32 kilos;
    i32 weight;

    Tunnel(i32 end, i32 kilos, i32 weight)
        : end(end), kilos(kilos), weight(weight) {}

    friend bool operator<(const Tunnel &, const Tunnel &);
};

bool operator<(const Tunnel &tunnel1, const Tunnel &tunnel2) {
    // Reverse, because we want the shortest tunnel on top
    return tunnel1.weight > tunnel2.weight;
}

typedef std::vector<std::vector<Tunnel>> vvt;

i32 binary_search(const vvt &, i32, i32, i32);
i32 dijkstra(i32, const vvt &, i32);

i32 main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i32 vertices, edges, debel;
    std::cin >> vertices >> edges >> debel;

    vvt graph(vertices);
    i32 start, end, kilos, weight;
    for (i32 i = 0; i < edges; ++i) {
        std::cin >> start >> end >> kilos >> weight;

        graph[start - 1].emplace_back(end - 1, kilos, weight);
    }

    std::cout << binary_search(graph, 0, 1e9, debel) << std::endl;
}

i32 binary_search(const vvt &graph, i32 min, i32 max, i32 limit) {
    i32 res = INT_MAX;

    i32 mid;
    i32 current_distance;
    while (min <= max) {
        mid              = max - ((max - min) >> 1);
        current_distance = dijkstra(0, graph, mid);

        if (current_distance > limit) {
            min = mid + 1;
        } else {
            res = mid;
            max = mid - 1;
        }
    }

    return res == INT_MAX ? -1 : res;
}

i32 dijkstra(i32 source, const vvt &graph, i32 debel) {
    std::priority_queue<Tunnel, std::vector<Tunnel>> shortest_tunnels;

    std::vector<i32> distances(graph.size(), INT_MAX);
    std::vector<bool> available(graph.size(), true);

    distances[source] = 0;
    shortest_tunnels.push({source, 0, 0});

    while (!shortest_tunnels.empty()) {
        auto [current_vertex, current_kilos, current_weight] =
            shortest_tunnels.top();
        shortest_tunnels.pop();

        if (!available[current_vertex]) {
            continue;
        }

        auto update = [&, current_vertex =
                              std::ref(current_vertex)](const Tunnel &tunnel) {
            auto [end, kilos, weight] = tunnel;

            i32 &current_distance = distances[end];
            u64 adjacent_distance = distances[current_vertex.get()] + (u64) weight;

            if (kilos <= debel && adjacent_distance < current_distance) {
                current_distance = adjacent_distance;
                shortest_tunnels.push({end, 0, current_distance});
            }
        };

        std::for_each(graph[current_vertex].begin(),
                      graph[current_vertex].end(), update);

        available[current_vertex] = false;
    }

    return distances.back();
}
