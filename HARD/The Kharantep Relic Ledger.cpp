#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Relic {
    long long value;
    int chamber;
};

// Higher value first
// If value is same, smaller chamber number first
struct Compare {
    bool operator()(Relic a, Relic b) {
        if (a.value != b.value)
            return a.value < b.value;

        return a.chamber > b.chamber;
    }
};

vector<int> parent, sz;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b,
           vector<priority_queue<Relic, vector<Relic>, Compare>>& pq) {

    a = find(a);
    b = find(b);

    if (a == b)
        return;

    // Keep bigger component as the main component
    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];

    // Move all relics of b into a
    while (!pq[b].empty()) {
        pq[a].push(pq[b].top());
        pq[b].pop();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    vector<priority_queue<Relic, vector<Relic>, Compare>> pq(n + 1);

    // Initially every chamber is its own component
    for (int i = 1; i <= n; i++) {
        parent[i] = i;

        long long value;
        cin >> value;

        if (value > 0) {
            pq[i].push({value, i});
        }
    }

    for (int i = 0; i < m; i++) {
        string type;
        cin >> type;

        if (type == "LINK") {
            int u, v;
            cin >> u >> v;

            unite(u, v, pq);
        }
        else if (type == "CLAIM") {
            int x;
            cin >> x;

            int root = find(x);

            if (pq[root].empty()) {
                cout << "EMPTY\n";
            }
            else {
                Relic best = pq[root].top();
                pq[root].pop();

                cout << best.chamber << " " << best.value << "\n";
            }
        }
    }

    return 0;
}