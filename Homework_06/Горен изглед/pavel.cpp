#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

struct Node {
    size_t id;
    int x, y;
    Node *left, *right;

    Node(size_t id, int x, int y) : id(id), x(x), y(y) {}

    static void pre_order_for_each(Node *root,
                                   std::function<void(Node *)> for_each) {
        if (root) {
            for_each(root);
            pre_order_for_each(root->left, for_each);
            pre_order_for_each(root->right, for_each);
        }
    }
};

int main() {
    size_t n;
    std::cin >> n;

    std::vector<Node *> nodes(n, nullptr);
    nodes[0] = new Node(0, 0, 0);

    int temp;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> temp;
        if (temp == -1) {
            nodes[i]->left = nullptr;
        } else {
            nodes[temp]    = new Node(temp, nodes[i]->x - 1, nodes[i]->y - 1);
            nodes[i]->left = nodes[temp];
        }

        std::cin >> temp;
        if (temp == -1) {
            nodes[i]->right = nullptr;
        } else {
            nodes[temp]     = new Node(temp, nodes[i]->x + 1, nodes[i]->y - 1);
            nodes[i]->right = nodes[temp];
        }
    }
    std::vector<Node *> highest(2 * n - 1, nullptr);

    Node::pre_order_for_each(
        nodes[0], [n, &highest](Node *node) -> void {
            if (!highest[n + node->x] || node->y > highest[n + node->x]->y) {
                highest[n + node->x] = node;
            }
        });

    std::for_each(highest.begin(), highest.end(), [](Node *node) {
        if (node) {
            std::cout << node->id << ' ';
        }
    });

    return 0;
}
