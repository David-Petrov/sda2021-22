#include <cmath>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//template<typename T>
//class BST
//{
//    struct Node
//    {
//        T data;
//        Node* parent = nullptr, * left = nullptr, * right = nullptr;
//    };
//
//    Node* head = nullptr, * largest = nullptr;
//
//public:
//
//    void insert(const T& value)
//    {
//        if (head == nullptr)
//        {
//            head = largest = new Node{ value };
//            return;
//        }
//
//        Node*& slot = head, * parent = nullptr;
//
//        while (slot != nullptr)
//        {
//            if (value > slot->data)
//            {
//                slot = slot->right;
//            }
//        }
//    }
//};

template<typename T>
struct Tree
{
    struct Node
    {
        T data;
        int left = -1, right = -1, index = -1;
    };

    vector<Node> nodes;

    Tree(int nodesCount) : nodes(vector<Node>(nodesCount)) {}

    Node& operator[](const int i)
    {
        return nodes[i];
    }

    int removeKthBiggest(int k)
    {
        stack<int> biggest;
        rightRootLeft(0, k, biggest);

        int biggestIndex = biggest.top();
        biggest.pop();

        if ((nodes[biggestIndex].left == -1 && nodes[biggestIndex].right == -1) ||biggest.empty())
        {
            nodes[biggestIndex].data = -1;
            return biggestIndex;
        }

        
        int secondBiggestIndex = nodes[biggestIndex].right > -1 ? biggest.top() : nodes[biggestIndex].left;

        nodes[biggestIndex].data = nodes[secondBiggestIndex].data;
        nodes[secondBiggestIndex].data = -1;

        return secondBiggestIndex;
    }

    void rightRootLeft(int root, const int& k, stack<int>& biggest)
    {
        if (root == -1)
        {
            return;
        }

        rightRootLeft(nodes[root].right, k, biggest);

        if (biggest.size() >= k)
            return;

        biggest.push(root);
        rightRootLeft(nodes[root].left, k, biggest);
    }
};

int main()
{
    int n, k, temp;
    cin >> n >> k;

    Tree<int> bst(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        bst[i] = {temp, 2 * i + 1 >= n ? -1 : 2 * i + 1, 2 * i + 2 >= n ? -1 : 2 * i + 2, i};
    }


    int kThLargestIndex = bst.removeKthBiggest(k);

    for (int i = 0; i < n; i++)
    {
        if (i == kThLargestIndex)
            continue;

        cout << bst[i].data << ' ';
    }

    //cout << "Kth biggest: " << bst[kThLargestIndex].data << '\n';

    return 0;
}