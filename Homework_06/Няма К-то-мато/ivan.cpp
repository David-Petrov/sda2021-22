#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class BST
{
private:
    struct Node
    {
        int val;
        Node *left, *right;

        Node(int val, Node *left = nullptr, Node *right = nullptr)
            : val(val),
              left(left), right(right) {}
    };

    Node *root = nullptr;

    Node *&find(Node *&current, const int target)
    {
        if (!current || current->val == target)
        {
            return current;
        }

        if (current->val < target)
        {
            return find(current->right, target);
        }
        else
        {
            return find(current->left, target);
        }
    }

    void printLevel(const Node *curr) const
    {
        if (curr)
        {
            queue<const Node *> wave;
            wave.push(curr);

            while (!wave.empty())
            {
                const Node *process = wave.front();
                wave.pop();

                cout << process->val << ' ';

                if (process->left)
                {
                    wave.push(process->left);
                }

                if (process->right)
                {
                    wave.push(process->right);
                }
            }
        }
    }

    void cleanUp(Node *ptr)
    {
        if (ptr)
        {
            cleanUp(ptr->left);
            cleanUp(ptr->right);
            delete ptr;
        }
    }

    void inorderBuildVector(vector<int> &v, Node *root)
    {
        if (root)
        {
            inorderBuildVector(v, root->left);
            v.push_back(root->val);
            inorderBuildVector(v, root->right);
        }
    }

    int findKthBiggest(int k)
    {
        vector<int> v;
        inorderBuildVector(v, root);

        return v[v.size() - k];
    }

    Node *&findMin(Node *&curr) const
    {
        if (!curr || !curr->left)
            return curr;

        return findMin(curr->left);
    }

    void remove(int val)
    {
        Node *&toRemove = find(root, val);

        if (!toRemove->left && !toRemove->right)
        {
            delete toRemove;
            toRemove = nullptr;
        }
        else if (!toRemove->left)
        {
            Node *right = toRemove->right;
            delete toRemove;
            toRemove = right;
        }
        else if (!toRemove->right)
        {
            Node *left = toRemove->left;
            delete toRemove;
            toRemove = left;
        }
        else
        {
            Node *&mr = findMin(toRemove->right);

            std::swap(mr->val, toRemove->val);

            delete mr;
            mr = nullptr;
        }
    }

public:
    void add(const int val)
    {
        Node *&insertPos = find(root, val);

        if (!insertPos)
        {
            insertPos = new Node(val);
        }
    }

    void removeKthBiggest(const int k)
    {
        int val = findKthBiggest(k);

        remove(val);
    }

    void print() const
    {
        printLevel(root);
    }

    ~BST()
    {
        cleanUp(root);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BST tree;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int toAdd;
        cin >> toAdd;

        tree.add(toAdd);
    }

    tree.removeKthBiggest(k);
    tree.print();

    cout << '\n';

    return 0;
}