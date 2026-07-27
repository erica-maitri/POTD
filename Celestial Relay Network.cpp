<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main() {
    int N;
    cin >> N;

    int total = N + 1; // Nodes: 0 to N

    vector<vector<long long>> cost(total, vector<long long>(total));

    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            cin >> cost[i][j];
        }
    }

    int FULL = 1 << N;

    // dp[mask][u] = minimum cost to visit cities in mask and end at u
    vector<vector<long long>> dp(FULL, vector<long long>(N + 1, INF));

    // Start from node 0 and visit one city first
    for (int i = 1; i <= N; i++) {
        dp[1 << (i - 1)][i] = cost[0][i];
    }

    for (int mask = 0; mask < FULL; mask++) {
        for (int u = 1; u <= N; u++) {

            if (!(mask & (1 << (u - 1))))
                continue;

            if (dp[mask][u] == INF)
                continue;

            // Go to an unvisited city
            for (int v = 1; v <= N; v++) {
                if (mask & (1 << (v - 1)))
                    continue;

                int newMask = mask | (1 << (v - 1));

                dp[newMask][v] = min(dp[newMask][v],
                                     dp[mask][u] + cost[u][v]);
            }
        }
    }

    long long ans = INF;
    int allVisited = FULL - 1;

    // Return to node 0
    for (int u = 1; u <= N; u++) {
        ans = min(ans, dp[allVisited][u] + cost[u][0]);
    }

    cout << ans << endl;

    return 0;
}
/*
standard DP + Bitmask (Held-Karp) solution in C++, which works within the given constraints (N ≤ 16).

Time Complexity
O(N² × 2ᴺ)
Space Complexity
O(N × 2ᴺ)

This is the optimal solution for the classic Travelling Salesman Problem (TSP) with N ≤ 16.
=======
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main() {
    int N;
    cin >> N;

    int total = N + 1; // Nodes: 0 to N

    vector<vector<long long>> cost(total, vector<long long>(total));

    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            cin >> cost[i][j];
        }
    }

    int FULL = 1 << N;

    // dp[mask][u] = minimum cost to visit cities in mask and end at u
    vector<vector<long long>> dp(FULL, vector<long long>(N + 1, INF));

    // Start from node 0 and visit one city first
    for (int i = 1; i <= N; i++) {
        dp[1 << (i - 1)][i] = cost[0][i];
    }

    for (int mask = 0; mask < FULL; mask++) {
        for (int u = 1; u <= N; u++) {

            if (!(mask & (1 << (u - 1))))
                continue;

            if (dp[mask][u] == INF)
                continue;

            // Go to an unvisited city
            for (int v = 1; v <= N; v++) {
                if (mask & (1 << (v - 1)))
                    continue;

                int newMask = mask | (1 << (v - 1));

                dp[newMask][v] = min(dp[newMask][v],
                                     dp[mask][u] + cost[u][v]);
            }
        }
    }

    long long ans = INF;
    int allVisited = FULL - 1;

    // Return to node 0
    for (int u = 1; u <= N; u++) {
        ans = min(ans, dp[allVisited][u] + cost[u][0]);
    }

    cout << ans << endl;

    return 0;
}
/*
standard DP + Bitmask (Held-Karp) solution in C++, which works within the given constraints (N ≤ 16).

Time Complexity
O(N² × 2ᴺ)
Space Complexity
O(N × 2ᴺ)

This is the optimal solution for the classic Travelling Salesman Problem (TSP) with N ≤ 16.
>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
*/