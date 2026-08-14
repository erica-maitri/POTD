/*
You have a graph of n towns connected by roads.

Each tower is placed at a town and has a power P.
A tower covers every town whose shortest-path distance from the tower is ≤ P.

Your goal: count how many different towns are covered by at least one tower.

Example:
Tower at town 1 with P = 3
1 → 2 → 3 → 4
Distances are 0, 1, 2, 3, so all 4 towns are covered.

Important:
- Roads are bidirectional.
- Distance means number of roads (hops).
- P = 0 means the tower covers only its own town.
- Disconnected towns cannot be reached by that tower.
- Multiple towers can cover the same town; count that town only once.

With n,m ≤ 2×10⁵, the solution needs an efficient graph algorithm, typically a multi-source BFS with the tower having the greatest remaining power taking priority.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n + 1);

    // Roads
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // best[i] = maximum remaining power reaching town i
    vector<long long> best(n + 1, -1);

    // {remaining power, town}
    priority_queue<pair<long long, int>> pq;

    // Towers
    for (int i = 0; i < k; i++) {
        int town;
        long long power;

        cin >> town >> power;

        if (power > best[town]) {
            best[town] = power;
            pq.push({power, town});
        }
    }

    // Process towns with highest remaining power first
    while (!pq.empty()) {
        long long power = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated entry
        if (power != best[u])
            continue;

        // No power left to move further
        if (power == 0)
            continue;

        for (int v : graph[u]) {
            long long newPower = power - 1;

            if (newPower > best[v]) {
                best[v] = newPower;
                pq.push({newPower, v});
            }
        }
    }

    // Count covered towns
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (best[i] >= 0)
            answer++;
    }

    cout << answer << '\n';

    return 0;
}