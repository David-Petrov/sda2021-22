#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

typedef int i32;
typedef unsigned long long u64;

typedef std::pair<i32, i32> pii;
typedef std::pair<u64, i32> pui;
typedef std::vector<i32> vi32;
typedef std::vector<vi32> vvi32;
typedef std::vector<pii> vpii;
typedef std::vector<pui> vpui;
typedef std::vector<vpii> vvpii;
typedef std::vector<vpui> vvpui;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i32 vertices, edges;
    std::cin >> vertices >> edges;

    vvi32 graph(vertices);

    std::function<bool(i32)> path = [&](i32 indexx) {
        std::vector<bool> visited(vertices, false);

        std::function<void(i32)> dfs = [&](i32 index) {
            visited[index] = true;
            for (auto runner : graph[index]) {
                if (!visited[runner]) {
                    dfs(runner);
                }
            }
        };

        for (i32 i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        return visited[indexx];
    };

    i32 start, end;
    for (i32 i = 0; i < edges; ++i) {
        std::cin >> start >> end;

        graph[start - 1].emplace_back(end - 1);
        graph[end - 1].emplace_back(start - 1);
    }

    i32 sources;
    std::cin >> sources;

    i32 source;
    std::vector<int> distances;
    for (i32 i = 0; i < sources; ++i) {
        std::cin >> source;

        printf("%d ", path(source));
    }

    return 0;
}
