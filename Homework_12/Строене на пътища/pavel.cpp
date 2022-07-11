/**
* NOTE: 29.70/33 - 1 WA
*/

#include <functional>
#include <iostream>
#include <set>
#include <vector>

typedef long long T;

struct Path {
    static T ID;
    T id;
    T from;
    T to;
    T work;
    T gain;
    bool built;

    Path(T from, T to, T work, T gain)
        : id(this->ID++), from(from), to(to), work(work), gain(gain), built(false) {}

    void build() {
        this->built = true;
        printf("%lld\n", id);
    }

    bool operator<(const Path &path) const {
        return (this->work == path.work ? this->gain > path.gain
                                        : this->work < path.work);
    }
};
T Path::ID = 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    T vertices, edges;
    std::cin >> vertices >> edges;

    std::set<Path> paths;

    T from, to, work, gain;
    for (T i = 0; i < edges; ++i) {
        std::cin >> from >> to >> work >> gain;

        paths.emplace(from, to, work, gain);
    }

    std::vector<T> parents(vertices + 1);
    for (T i = 0; i <= vertices; ++i) {
        parents[i] = i;
    }

    std::function<T(T)> find_root = [&parents, &find_root](T vertex) {
        if (parents[vertex] == vertex) {
            return vertex;
        }

        parents[vertex] = find_root(parents[vertex]);
        return parents[vertex];
    };

    std::function<void(Path *const)> connect = [&parents, &find_root](Path *const path) {
        T node_1_root = find_root(path->from);
        T node_2_root = find_root(path->to);

        if (node_1_root == node_2_root) {
            return;
        }

        path->build();
        parents[node_2_root] = node_1_root;
    };

    for (auto runner = paths.begin(); runner != paths.end(); ++runner) {
        connect(const_cast<Path *const>(&*runner));
    }

    return 0;
}
