/**
* NOTE: 38.89/50 - 2 WA
*/

#include <iostream>
#include <set>
#include <utility>
#include <vector>

struct Path {
    int to;
    int weight;
};

int main() {
    int vertices, edges;
    std::cin >> vertices >> edges;

    std::vector<std::vector<Path>> adjacency_list(vertices);

    int from, to, weight;
    for (int edge = 0; edge < edges; edge++) {
        std::cin >> from >> to >> weight;

        adjacency_list[from].push_back({to, weight});
    }

    int superstitions_count;
    std::cin >> superstitions_count;

    std::set<int> superstitions;

    int superstition;
    for (int i = 0; i < superstitions_count; ++i) {
        std::cin >> superstition;

        superstitions.insert(superstition);
    }

    int queries;
    std::cin >> queries;

    bool foundBrokenPath;
    bool foundPath;
    bool foundNonBrokenPath;
    int towns;
    int query1, query2;
    for (int i = 0; i < queries; i++) {
        std::cin >> towns;

        foundBrokenPath    = false;
        foundPath          = false;
        foundNonBrokenPath = false;
        std::cin >> query1;
        for (int j = 0; j < towns - 1; j++) {
            std::cin >> query2;

            for (Path path : adjacency_list[query1]) {
                if (path.to == query2) {
                    if (superstitions.find(path.weight) !=
                        superstitions.end()) {
                        foundBrokenPath = true;
                    } else {
                        foundNonBrokenPath = true;
                    }
                    foundPath = true;
                }
            }

            if ((foundBrokenPath && !foundNonBrokenPath) || !foundPath) {
                break;
            }

            query1 = query2;
        }

        if ((!foundPath) || (foundBrokenPath && !foundNonBrokenPath)) {
            printf("0");
        } else {
            printf("1");
        }
    }

    return 0;
}
