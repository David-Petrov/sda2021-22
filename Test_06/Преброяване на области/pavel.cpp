#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
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

i32 main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i32 takiva;
    std::cin >> takiva;

    for (int takova = 0; takova < takiva; ++takova) {
        i32 vertices, edges;
        std::cin >> vertices >> edges;

        vvi32 graph(vertices);

        int start, end;
        for (i32 i = 0; i < edges; i++) {
            std::cin >> start >> end;

            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        std::vector<bool> visited(vertices, false);

        std::function<void(i32)> dfs = [&](i32 index) {
            visited[index] = true;
            for (i32 runner : graph[index]) {
                if (!visited[runner]) {
                    dfs(runner);
                }
            }
        };

        i32 counter = 0;
        for (i32 i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i);
                ++counter;
            }
        }

        printf("%d ", counter);
    }

    return 0;
}
