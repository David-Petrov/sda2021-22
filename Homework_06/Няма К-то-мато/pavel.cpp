#include <iostream>
#include <queue>

template <typename T>
class BST {
    public:
    struct Node {
        Node *left;
        T data;
        Node *right;

        Node(T data) : left(nullptr), data(data), right(nullptr) {}
        Node(Node *left, T data, Node *right)
            : left(left), data(data), right(right) {}
    };

    private:
    Node *root;

    public:
    BST() : root(nullptr) {}

    ~BST() {
        this->free_node(this->root);
    }

    void print() {
        if (!this->root) {
            return;
        }

        std::queue<Node *> queue;
        queue.push(this->root);
        while(!queue.empty()) {
            if (queue.front()->left) {
                queue.push(queue.front()->left);
            }
            if (queue.front()->right) {
                queue.push(queue.front()->right);
            }

            std::cout << queue.front()->data << ' ';
            queue.pop();
        }
    }

    void add_node(T data) {
        Node *newNode = new Node(data);

        if (!this->root) {
            this->root = newNode;
            return;
        }

        Node *src = this->root;
        while (true) {
            if (data < src->data) {
                if (src->left) {
                    src = src->left;
                } else {
                    src->left = newNode;
                    break;
                }
            } else {
                if (src->right) {
                    src = src->right;
                } else {
                    src->right = newNode;
                    break;
                }
            }
        }
    }

    void remove_node(T data) {
        Node *prev, *runner = this->root;

        while (runner) {
            if (data == runner->data) {
                break;
            }

            prev = runner;

            if (data < runner->data) {
                runner = runner->left;
                continue;
            }

            if (data > runner->data) {
                runner = runner->right;
                continue;
            }
        }

        if (!runner) {
            return;
        }

        // NOTE: Trivial cases
        if (!runner->left && !runner->right) {
            if (prev) {
                if (prev->left == runner) {
                    prev->left = nullptr;
                } else if (prev->right == runner) {
                    prev->right = nullptr;
                }
            } else {
                this->root = nullptr;
            }
            this->free_node(runner, false);
            return;
        }
        if (runner->left && !runner->right) {
            if (prev) {
                if (prev->left == runner) {
                    prev->left = runner->left;
                } else if (prev->right == runner) {
                    prev->right = runner->left;
                }
            } else {
                this->root = runner->left;
            }
            this->free_node(runner, false);
            return;
        }
        if (!runner->left && runner->right) {
            if (prev) {
                if (prev->left == runner) {
                    prev->left = runner->right;
                } else if (prev->right == runner) {
                    prev->right = runner->right;
                }
            } else {
                this->root = runner->right;
            }
            this->free_node(runner, false);
            return;
        }

        Node* to_remove = runner;

        // NOTE: bigger closest
        // Move right once...
        prev = runner;
        runner = runner->right;

        // Then left while possible
        while(runner->left) {
            prev = runner;
            runner = runner->left;
        }

        to_remove->data = runner->data;

        if (to_remove->right == runner) {
            to_remove->right = nullptr;
        }

        if (prev != to_remove) {
            prev->left = runner->right;
        }

        this->free_node(runner, false);
    }

    Node* kth_largest(int& k) {
        return kth_largest(this->root, k);
    }

    private:
    Node* kth_largest(Node *src, int& k) {
        if (!src) {
            return nullptr;
        }

        Node* left = kth_largest(src->right, k);

        if (left) {
            return left;
        }

        --k;
        if (!k) {
            return src;
        }

        return kth_largest(src->left, k);
    }

    void free_node(Node *node, bool recurse = true) {
        if (recurse) {
            if (node->left) {
                free_node(node->left);
            }
            if (node->right) {
                free_node(node->right);
            }
        }

        delete node;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;

    BST<int> bst;

    int temp;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        bst.add_node(temp);
    }

    bst.remove_node(bst.kth_largest(k)->data);

    bst.print();

    return 0;
}
