#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

map<char, set<char>> graph;
vector<bool> visited(128, false);
vector<char> result;

void dfs(char node) {
    if (visited[node]) {
        return;
    }

    const auto& tmp = graph[node];
    visited[node] = true;

    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        dfs(*it);
    }

    result.push_back(node);
}

void topologicalSort() {
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        dfs(it->first);
    }
}

void addWord(const string& word) {
    for (const char c : word) {
        graph[c];
    }
}

int main() {
    size_t n;
    cin >> n;

    vector<string> words(n);
    for(size_t i = 0; i < n; ++i) {
        cin >> words[i];
        addWord(words[i]);
    }

    for (size_t i = 1; i < n; ++i) {
        const string& word = words[i];
        const string& lastWord = words[i - 1];

        size_t len = min(word.size(), lastWord.size());
        for (size_t j = 0; j < len; ++j) {
            if (word[j] == lastWord[j]) {
                continue;
            }

            graph[lastWord[j]].insert(word[j]);
            break;
        }
    }

    topologicalSort();
    reverse(result.begin(), result.end());

    for (const char c : result) {
        cout << c << ' ';
    }
}