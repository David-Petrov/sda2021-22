#include <iostream>
#include <vector>

template<typename T>
struct Node {
    T data;
    std::vector<Node *> children;

    Node(T data) : data(data) {}
};

template<typename T>
T deepChildrenCount(Node<T> *node) {
    if (!node) {
        return 0;
    }

    int count = 0;
    size_t childrenCount = node->children.size();
    for (size_t i = 0; i < childrenCount; ++i) {
        count += deepChildrenCount(node->children[i]) + 1;
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;

    int parent, child;
    std::vector<Node<int> *> nodes(n);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> parent >> child;

        if (!i) {
            nodes[parent] = new Node<int>(parent);
        }

        nodes[child] = new Node<int>(child);
        nodes[parent]->children.push_back(nodes[child]);
    }

    for (int i = 0; i < n; i++) {
        std::cout << deepChildrenCount(nodes[i]) << " ";
    }
}
