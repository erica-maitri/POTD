Problem Statement
A region has n towns connected by m bidirectional roads, where each road connects two towns directly (traveling along any road takes exactly one hop; towns not directly connected must be reached via a sequence of roads). Some towns host emergency broadcast towers. Tower i is located at a specific town and has a power value P_i, meaning its signal can survive at most P_i hops of travel before fading out completely (a signal that has traveled exactly P_i hops still just barely reaches that town; one more hop would fail).

A town is considered covered if it lies within P_i hops (using the shortest hop-distance) of at least one tower i. If a town cannot be reached from any tower at all (due to disconnected roads), it is never covered by that tower regardless of power.

Given the road network and the list of towers, determine how many towns are covered by at least one tower's broadcast.

Input Format
Line 1: three integers n, m, k — number of towns, number of roads, and number of towers.

Next m lines: two integers u v — a road directly connecting towns u and v.

Next k lines: two integers t P — a tower located at town t with power P.

Output Format
Print a single integer — the number of towns covered by at least one tower.

Constraints
1 ≤ n ≤ 2 × 10^5
0 ≤ m ≤ 2 × 10^5
1 ≤ k ≤ n
1 ≤ u, v, t ≤ n
0 ≤ P ≤ 10^9
The road network may be disconnected. No self-loops or duplicate roads are guaranteed, but multiple towers may share the same town.
Time Limit: 1 sec
Memory Limit: 256 MB
The output is unique.
Sample Testcase 0
Testcase Input
4 3 1
1 2
2 3
3 4
1 3
Testcase Output
4
Explanation
The single tower at town 1 has power 3, and the farthest town (town 4) is exactly 3 hops away, so all 4 towns are covered.

Sample Testcase 1
Testcase Input
6 6 2
1 2
2 3
3 4
4 5
5 6
2 6
1 1
5 0
Testcase Output
3
Explanation
Tower at town 1 (power 1) covers towns within 1 hop: town 1 (0 hops) and town 2 (1 hop). Tower at town 5 (power 0) covers only town 5 itself (0 hops). Towns 3, 4, and 6 are not within range of either tower. Total covered towns: {1, 2, 5} = 3.