#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left  = NULL;
        this->right = NULL;
    }
};

class BST {

    public:
    BST() { root = NULL; }

    void insert(int value) { root = insert(root, value); }

    void printSpecific(int dividedBy) {
        this->printSpecific(this->root, dividedBy);
    }

    private:
    static void printSpecific(Node *src, int divisor) {
        if (src) {
            if ((src->left || src->right) && src->value % divisor == 0) {
                std::cout << src->value << ' ';
            }
            printSpecific(src->left, divisor);
            printSpecific(src->right, divisor);
        }
    }

    Node *root;

    Node *insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            // if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    std::cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        tree.insert(value);
    }
    int dividedBy;
    std::cin >> dividedBy;
    tree.printSpecific(dividedBy);
    return 0;
}
