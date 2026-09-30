#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort corridors by disturbance score
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(n);

    // MST adjacency list
    vector<vector<pair<int, int>>> tree(n + 1);

    int count = 0;

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);

            tree[u].push_back({v, w});
            tree[v].push_back({u, w});

            count++;

            if (count == n - 1)
                break;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (dsu.find(a) != dsu.find(b)) {
            cout << -1 << endl;
            continue;
        }

        // Find maximum edge on path from a to b
        vector<int> visited(n + 1, 0);
        vector<int> parent(n + 1, -1);
        vector<int> edgeWeight(n + 1, 0);

        vector<int> stack;
        stack.push_back(a);
        visited[a] = 1;

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();

            if (u == b)
                break;

            for (auto p : tree[u]) {
                int v = p.first;
                int w = p.second;

                if (!visited[v]) {
                    visited[v] = 1;
                    parent[v] = u;
                    edgeWeight[v] = w;
                    stack.push_back(v);
                }
            }
        }

        int answer = 0;
        int current = b;

        while (current != a) {
            answer = max(answer, edgeWeight[current]);
            current = parent[current];
        }

        cout << answer << endl;
    }

    return 0;
}
/*
TC and SC
Kruskal: O(m log m)
Each query: O(n) in this simple implementation
Total: O(m log m + q*n) in the worst case
Space: O(n + m)
*/