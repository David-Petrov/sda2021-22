#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <utility>
#include <vector>

typedef std::map<char, std::set<char>, std::greater<char>> AdjacencyList;

class Trie {
    private:
    struct Node {
        std::map<char, Node *> children;
        std::vector<char> order;

        Node() : children(), order() {}
    };
    Node *root;
    std::unordered_set<char> characters;

    public:
    Trie() : root(new Node()) {}
    ~Trie() {
        std::function<void(Node *)> free_node = [&free_node](Node *node) {
            std::for_each(node->children.begin(), node->children.end(),
                          [&free_node](std::pair<const char, Node *> entry) {
                              free_node(entry.second);
                          });
            delete node;
        };

        free_node(this->root);
    }
    void add(const std::string &string) {
        Node *runner = this->root;

        size_t length = string.size();
        for (size_t i = 0; i < length; ++i) {
            if (runner->children.find(string[i]) == runner->children.end()) {
                runner->children.insert({string[i], new Node()});
                runner->order.push_back(string[i]);
            }

            runner = runner->children[string[i]];
            this->characters.insert(string[i]);
        }
    }
    AdjacencyList make_adjacency_list() const {
        std::function<AdjacencyList()> generateAdjacencyList = [this]() {
            AdjacencyList adjacencyList;

            for (auto runner = this->characters.begin();
                 runner != this->characters.end(); ++runner) {
                adjacencyList.insert({*runner, std::set<char>()});
            }

            return adjacencyList;
        };

        AdjacencyList adjacencyList = generateAdjacencyList();

        std::function<void(Node *)> make_edges = [&make_edges,
                                                  &adjacencyList](Node *node) {
            for (auto runner = node->order.begin(); runner != node->order.end();
                 ++runner) {
                if (std::next(runner) != node->order.end()) {
                    // printf("Adding rule: %c is before %c\n", *runner,
                    //        *std::next(runner));
                    adjacencyList[*runner].insert(*std::next(runner));
                }
                make_edges(node->children[*runner]);
            }
        };

        make_edges(this->root);

        return adjacencyList;
    }
};

std::deque<char> assembleAlphabet(const Trie &trie) {
    AdjacencyList adjacency_list = trie.make_adjacency_list();

    std::deque<char> alphabet;
    std::unordered_set<char> visited;

    std::function<void(char)> dfs =
        [&](char letter) {  // &order, &visited, &DFS, &adjacencyList
            visited.insert(letter);
            for (auto runner : adjacency_list[letter]) {
                if (visited.find(runner) == visited.end()) {
                    dfs(runner);
                }
            }
            alphabet.push_front(letter);
        };

    for (auto runner : adjacency_list) {
        if (visited.find(runner.first) == visited.end()) {
            dfs(runner.first);
        }
    }

    return alphabet;
}

int main() {
    size_t n;
    std::cin >> n;

    Trie trie;
    std::string word;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> word;
        trie.add(word);
    }

    std::deque<char> alphabet = assembleAlphabet(trie);
    std::for_each(alphabet.begin(), alphabet.end(), [](char ch){
        printf("%c ", ch);
    });

    return 0;
}
