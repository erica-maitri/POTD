/*
1. What is the problem asking?

You have a tree of rulers.

Ruler 1 is the root/founding ruler.
Every other ruler has exactly one parent.
Each connection has a number w, which means the years between the parent and child.

For every query (x, y), you need to find:

Total years between ruler x and ruler y.
Number of rulers present on the path from x to y, including both x and y.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> depth(n + 1);
    vector<long long> distance(n + 1);

    // Read the tree
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // v is the child of u
        parent[v] = u;

        // Depth of child
        depth[v] = depth[u] + 1;

        // Total years from root to child
        distance[v] = distance[u] + w;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int a = x;
        int b = y;

        // Move the deeper ruler upward
        while (depth[a] > depth[b])
        {
            a = parent[a];
        }

        while (depth[b] > depth[a])
        {
            b = parent[b];
        }

        // Move both upward until they meet
        while (a != b)
        {
            a = parent[a];
            b = parent[b];
        }

        // a and b are now the common ancestor
        int common = a;

        // Total years between x and y
        long long years =
            distance[x] + distance[y] - 2 * distance[common];

        // Number of rulers on the path
        int rulers =
            depth[x] + depth[y] - 2 * depth[common] + 1;

        cout << years << " " << rulers << endl;
    }

    return 0;
}

