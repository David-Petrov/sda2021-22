#include <algorithm>
#include <cstdio>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    std::map<int, int> degrees;
    std::set<int> visited;
    std::map<int, std::vector<int>> adjacency_list;

    int queires;
    std::cin >> queires;

    std::function<void()> reset_degrees = [&degrees]() {
        degrees.clear();
    };
    std::function<void()> reset_visited = [&visited]() {
        visited.clear();
    };
    std::function<void()> reset_adjacency_list = [&adjacency_list]() {
        adjacency_list.clear();
    };

    std::function<void(int)> dfs = [&](int node) {
        for (auto runner : adjacency_list[node]) {
            if (visited.insert(runner).second) {
                dfs(runner);
            }
        }
    };

    int vertices, edges, odds;
    int start, end;
    for (int _query = 0; _query < queires; ++_query) {
        std::cin >> vertices >> edges;

        odds = 0;
        reset_degrees();
        reset_visited();
        reset_adjacency_list();

        for (int _edge = 0; _edge < edges; ++_edge) {
            std::cin >> start >> end;

            ++degrees[start];
            ++degrees[end];

            adjacency_list[start].push_back(end);
            adjacency_list[end].push_back(start);
        }

        if (vertices != degrees.size()) {
            printf("none\n");
            continue;
        }

        dfs(degrees.begin()->first);

        if (visited.size() != degrees.size()) {
            printf("none\n");
            continue;
        }

        std::for_each(degrees.begin(), degrees.end(),
                      [&odds](std::pair<int, int> degreePair) {
                          if (degreePair.second % 2) {
                              ++odds;
                          }
                      });

        switch (odds) {
            case 0:
                printf("ecycle\n");
                break;
            case 2:
                printf("epath\n");
                break;
            default:
                printf("none\n");
                break;
        }
    }

    return 0;
}
