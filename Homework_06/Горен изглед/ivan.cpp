#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coord
{
    int x, y;

    Coord(int x = 0, int y = 0)
        : x(x), y(y) {}

    bool operator>(Coord &rhs)
    {
        return x > rhs.x && y > rhs.y;
    }

    bool operator==(Coord &rhs)
    {
        return x == rhs.x && y == rhs.y;
    }

    bool operator<(Coord &rhs)
    {
        return !(*this > rhs || *this == rhs);
    }
};

struct Node
{
    int id;
    Coord coord;
    vector<int> children;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<Node> tree(N);

    for (int i = 0; i < N; i++)
    {
        int lChild, rChild;
        cin >> lChild >> rChild;

        tree[i].id = i;

        int x = tree[i].coord.x;
        int y = tree[i].coord.y;

        if (lChild != -1)
        {
            tree[lChild].coord = {x - 1, y - 1};
            tree[i].children.push_back(lChild);
        }

        if (rChild != -1)
        {
            tree[rChild].coord = {x + 1, y + 1};
            tree[i].children.push_back(rChild);
        }
    }

    // Interval
    Coord min = {0, 0};
    Coord max = {0, 0};

    vector<Node> topViewNodes;
    // The root is always a top-view node
    topViewNodes.push_back(tree[0]);

    for (int i = 0; i < N; i++)
    {
        bool topView = false;

        if (tree[i].coord > max)
        {
            // It's a top-view node
            max = tree[i].coord;

            topView = true;
        }

        if (tree[i].coord < min)
        {
            // It's a top-view node
            min = tree[i].coord;

            topView = true;
        }

        if (topView)
        {
            topViewNodes.push_back(tree[i]);
        }
    }

    sort(topViewNodes.begin(), topViewNodes.end(), [](Node &lhs, Node &rhs)
         { return lhs.coord < rhs.coord; });

    for (const Node &node : topViewNodes)
    {
        cout << node.id << ' ';
    }

    cout << '\n';

    return 0;
}