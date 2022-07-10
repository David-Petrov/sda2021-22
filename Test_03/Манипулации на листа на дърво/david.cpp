#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }

    long long sum = 0;
    void sumOddLeaves(Node* root) {
        if (root == nullptr) {
            return;
        }

        if (root->leftNode == nullptr && root->rightNode == nullptr && root->data % 2 == 1) {
            sum += root->data;
        }

        sumOddLeaves(root->leftNode);
        sumOddLeaves(root->rightNode);
    }

    void leaves(Node* root) {
        sum = 0;
        sumOddLeaves(root);
        cout << sum << endl;
    }
}; //End of Solution

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

    myTree.leaves(root);
    return 0;
}