#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    vector<int> children;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<Node> tree(N);

    for (int i = 0; i < N - 1; i++)
    {
        int parentI, childI;
        cin >> parentI >> childI;

        Node &parent = tree[parentI];

        parent.children.push_back(childI);
    }

    vector<int> result(N);
    for (int i = N - 1; i >= 0; --i)
    {
        Node node = tree[i];

        int totalChildren = node.children.size();

        for (int index : node.children)
        {
            totalChildren += result[index];
        }

        result[i] = totalChildren;
    }

    for (int n : result)
    {
        cout << n << ' ';
    }

    cout << '\n';

    return 0;
}