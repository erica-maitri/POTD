/*
Since N ≤ 400, the best and simplest solution is Floyd–Warshall.

Time Complexity: O(N³) = 400
3
=64,000,000 operations (fast enough).
Space Complexity: O(N²).

This is simpler than running Dijkstra from every node, and after preprocessing, each query is answered in O(1).*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    // A very large value to represent infinity
    const long long INF = 1e18;

    // dist[i][j] = minimum cost from i to j
    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));

    // Distance from a node to itself is 0
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    // Read all roads
    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // If multiple edges exist, keep the smallest one
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    // Floyd-Warshall Algorithm
    // Try every node as an intermediate node
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {

                // Update shortest distance if going through k is better
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Answer queries
    while (Q--) {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }

    return 0;
}

/*
1. Why index starts from 1?
   - Because the problem numbers the nodes from 1 to N.
   - You can absolutely use 0-based indexing if you convert every input:
       u--, v--, a--, b--;
   - Starting from 1 just avoids conversion and makes the code match the input.

2. Why both lines?
   dist[u][v] = min(dist[u][v], w);
   dist[v][u] = min(dist[v][u], w);

   - The graph is UNDIRECTED (bidirectional).
   - If there is a road between 2 and 5, then:
       2 → 5 costs w
       5 → 2 also costs w
   - If the graph were directed, you would write only:
       dist[u][v] = min(dist[u][v], w);

3. Why use min()?
   - There may be multiple edges between the same two nodes.
   - Example:
       1 2 10
       1 2 5
   - We keep the smaller cost (5).

4. What are i, j, and k?

   k = Intermediate node (the node through which we try to travel)
   i = Starting node
   j = Destination node

   We check:
       "Is going from i → k → j cheaper than the current i → j?"

   If yes:
       dist[i][j] = dist[i][k] + dist[k][j];

   Example:
       i = 1
       k = 2
       j = 3

       Current:
       1 → 3 = 12

       Through 2:
       1 → 2 = 5
       2 → 3 = 3
       Total = 8

       Since 8 < 12, update:
       dist[1][3] = 8.
*/

/*
Dry Run (Sample Input)

Graph:
1 --5-- 2
|       |
12      4
|       |
3 --7-- 4
 \--3--/

Initial Distance Matrix (INF = no path)

      1    2    3    4
1     0    5   12   INF
2     5    0    3     4
3    12    3    0     7
4   INF    4    7     0

-----------------------------------
k = 1 (Use node 1 as intermediate)
-----------------------------------
No shorter paths are found.

Matrix remains same.

-----------------------------------
k = 2 (Use node 2 as intermediate)
-----------------------------------

Check 1 → 3:
Current = 12
Through 2 = 5 + 3 = 8
Update: dist[1][3] = 8

Check 1 → 4:
Current = INF
Through 2 = 5 + 4 = 9
Update: dist[1][4] = 9

Similarly,
dist[3][1] = 8
dist[4][1] = 9

New Matrix

      1   2   3   4
1     0   5   8   9
2     5   0   3   4
3     8   3   0   7
4     9   4   7   0

-----------------------------------
k = 3 (Use node 3 as intermediate)
-----------------------------------

Try every pair through node 3.

Example:
1 → 4 through 3 = 8 + 7 = 15
Current = 9
No update.

No other path becomes smaller.

-----------------------------------
k = 4 (Use node 4 as intermediate)
-----------------------------------

Again check every pair.

Example:
2 → 3 through 4 = 4 + 7 = 11
Current = 3
No update.

No changes.

Final Shortest Distance Matrix

      1   2   3   4
1     0   5   8   9
2     5   0   3   4
3     8   3   0   7
4     9   4   7   0

Queries:
(1,3) → 8
(1,4) → 9
(3,4) → 7

Idea:
For every node k, assume "What if every path is allowed to pass through k?"
If going through k makes a path cheaper, update it.
After trying all nodes as intermediates, every shortest path is found.
*/