#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

class BinaryTrie
{
    struct Node {
        Node* left = nullptr, * right = nullptr;
    }* root = new Node;

public:
    ~BinaryTrie() {
        free(root);
    }

private:
    void free(Node* node) {
        if (node == nullptr) return;

        free(node->left);
        free(node->right);
        delete node;
    }

    size_t uniqueWordsCounted = 1;

    void insert(size_t mask, Node* node) {

        //if we only have 0 to count, we've alreade done that by default
        if (mask == 0) {
            return;
        }

        //if last bit is 1, branch and account for the branch
        if (mask % 2 == 1) {
            if (!node->right) {
                node->right = new Node;
                uniqueWordsCounted++;
            }

            insert(mask >> 1, node->right);
        }

        //and keep checking the 0 option anyways
        if (!node->left) {
            node->left = new Node;
        }

        insert(mask >> 1, node->left);
    }

public:
    void insert(size_t mask) {
        insert(mask, root);
    }

    size_t getCount() const {
        return uniqueWordsCounted;
    }
};

int main() {

    BinaryTrie bt;

    size_t n;
    cin >> n;

    size_t temp;
    while (n-- > 0)
    {
        cin >> temp;
        bt.insert(temp);
    }

    cout << bt.getCount();
    return 0;
}
