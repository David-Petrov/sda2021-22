#include <initializer_list>
#include <iostream>

const unsigned int BASE = 2;

struct Trie {
    struct Node {
        Node *children[BASE] {};

        Node *&at(unsigned int index) {
            return this->children[index];
        }

        ~Node() {
            for (unsigned int i = 0; i < BASE; ++i) {
                delete this->children[i];
            }
        }
    } * root;
    size_t count;

    Trie() : root(new Node), count(1) {}

    ~Trie() {
        delete this->root;
    }

    void insert(unsigned int mask) {
        this->insert(mask, this->root);
    }

    void insert(unsigned int mask, Node *src) {
        if (!mask) {
            return;
        }

        if (mask % BASE) {
            // For each non-zero bit branch off
            for (unsigned int i = 1; i <= mask % BASE; ++i) {
                if (!src->at(BASE - i)) {
                    src->at(BASE - i) = new Node();
                    ++this->count;
                }

                this->insert(mask / BASE, src->at(BASE - i));
            }
        }

        if (!src->at(0)) {
            src->at(0) = new Node();
        }

        this->insert(mask / BASE, src->at(0));
    }
};

int main() {
    unsigned int n;
    std::cin >> n;

    Trie *trie = new Trie();

    unsigned int temp;
    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> temp;
        trie->insert(temp);
    }

    std::cout << trie->count;

    delete trie;

    return 0;
}
