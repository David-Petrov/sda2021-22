#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

typedef long long T;
static const T T_MAX = LLONG_MAX;

struct Path {
    T from;
    T to;
    T speed;

    Path(T from, T to, T average_speed)
        : from(from), to(to), speed(average_speed) {}

    bool operator<(const Path &path) const { return this->speed < path.speed; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    T vertices, edges;
    std::cin >> vertices >> edges;

    std::multiset<Path> paths;

    T from, to, average_speed;
    for (T i = 0; i < edges; ++i) {
        std::cin >> from >> to >> average_speed;

        paths.emplace(from, to, average_speed);
    }

    struct MinMax {
        T min;
        T delta;

        MinMax(T min, T delta) : min(min), delta(delta) {}
    } min_max(-1, T_MAX);

    bool short_circuit;
    T temp_min_speed, temp_max_delta, temp_path_counter;

    std::vector<T> parents(vertices + 1);
    std::function<void()> reset_parents = [&parents, vertices]() {
        for (T i = 0; i <= vertices; ++i) {
            parents[i] = i;
        }
    };

    std::function<T(T)> find_root = [&parents, &find_root](T vertex) {
        if (parents[vertex] == vertex) {
            return vertex;
        }

        parents[vertex] = find_root(parents[vertex]);
        return parents[vertex];
    };

    std::function<bool(const Path &)> connect = [&](const Path &path) -> bool {
        T node_1_root = find_root(path.from);
        T node_2_root = find_root(path.to);

        if (node_1_root == node_2_root) {
            return false;
        }

        temp_max_delta = std::max(temp_max_delta, path.speed - temp_min_speed);
        ++temp_path_counter;
        parents[node_2_root] = node_1_root;

        return true;
    };

    for (auto start = paths.begin(); start != paths.end(); ++start) {
        short_circuit     = false;
        temp_max_delta    = 0;
        temp_min_speed    = start->speed;
        temp_path_counter = 0;
        reset_parents();

        for (auto runner = start; runner != paths.end(); ++runner) {
            if (connect(*runner) && temp_max_delta > min_max.delta) {
                short_circuit = true;
                break;
            }
        }

        if (!short_circuit && temp_path_counter == vertices - 1 &&
            temp_max_delta < min_max.delta) {
            min_max = {temp_min_speed, temp_max_delta};
        }
    }

    printf("%lld %lld", min_max.min, min_max.min + min_max.delta);

    return 0;
}
