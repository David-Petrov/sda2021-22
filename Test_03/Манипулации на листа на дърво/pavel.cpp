#include <bits/stdc++.h>
#include <iostream>

class Node {
    public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data      = d;
        leftNode  = nullptr;
        rightNode = nullptr;
    }
};

class Solution {
    public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if (data <= root->data) {
                cur            = insert(root->leftNode, data);
                root->leftNode = cur;
            } else {
                cur             = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }

    void leaves(Node* src, long &sum) {
        if (src->leftNode) {
            leaves(src->leftNode, sum);
        }
        if (!src->leftNode && !src->rightNode && src->data % 2 == 1) {
            sum += src->data;
        }
        if (src->rightNode) {
            leaves(src->rightNode, sum);
        }
    }

};

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    long sum = 0;
    myTree.leaves(root, sum);

    std::cout << sum;
    return 0;
}
