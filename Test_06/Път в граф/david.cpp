#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

typedef long long ll;
std::unordered_map <ll, std::vector <ll>> graph;
std::vector <ll> vertices;
ll N, M;
std::unordered_map <ll, bool> visited;
std::unordered_map <ll, ll> group;
ll step = 0;

bool findWithBFS(ll from) {

    std::list <ll> queue;
    visited[from] = true;
    group[from] = step;
    queue.push_back(from);
    while (!queue.empty()) {
        ll front = queue.front();
        group[front] = step;
        //std :: cout << front << " ";

        queue.pop_front();
        for (auto x : graph[front]) {
            if (!visited[x]) {
                visited[x] = true;
                queue.push_back(x);
            }
        }
    }
    return false;
}

int main() {
    std::cin >> N >> M;
    for (ll i = 0; i < M; ++i) {
        ll v1, v2;
        std::cin >> v1 >> v2;
        if (graph.find(v1) != graph.end())
            vertices.push_back(v1);
        if (graph.find(v2) != graph.end())
            vertices.push_back(v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (auto v : vertices) {
        visited[v] = false;
    }
    ll K;
    for (ll i = 0; i < N; i++) {
        if (!visited[vertices[i]]) {
            //std :: cout << vertices[i] << '\n';
            findWithBFS(vertices[i]);
            step++;
        }
    }
    std::cin >> K;
    std::vector <bool> results;
    for (ll i = 0; i < K; ++i) {
        ll from, to;
        std::cin >> from >> to;
        results.push_back(group[from] == group[to]);
    }
    for (auto res : results) {
        std::cout << res << " ";
    }
    return 0;
}