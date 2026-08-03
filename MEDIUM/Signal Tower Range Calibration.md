Problem Statement
A telecom engineer must place exactly one signal tower somewhere on a number line to serve N houses. House i is located at integer coordinate X[i] and requires a minimum received signal strength of Th[i] to function properly.

The tower can be placed at any integer coordinate C (not necessarily one of the house positions), and can be configured to broadcast at any non-negative integer power P. A house at distance d = |X[i] - C| from the tower receives signal strength exactly P - d (if this value would be negative, the house simply receives no usable signal).

The engineer wants to choose both the tower's position C and its power P so that every house receives signal strength at least equal to its required threshold, while minimizing P (higher power costs more to operate). Determine the minimum power P for which some valid placement C exists that satisfies every house's threshold.

Input Format
N

X[1] X[2] ... X[N]

Th[1] Th[2] ... Th[N]

Output Format
A single integer — the minimum power P required.

Constraints
1 ≤ N ≤ 2 × 10^5
-10^9 ≤ X[i] ≤ 10^9
0 ≤ Th[i] ≤ 10^9
Time Limit: 1 sec
Memory Limit: 256 MB
The output is unique.
Sample Testcase 0
Testcase Input
3
1 5 10
2 3 1
Testcase Output
6
Explanation
With P = 6, house 1 needs distance ≤ 4, house 2 needs distance ≤ 3, house 3 needs distance ≤ 5. Placing the tower at C = 5 gives distances 4, 0, and 5 respectively — all within their allowed limits, so P = 6 works. It can be shown no C makes P = 5 feasible for all three houses simultaneously, so 6 is minimal.

Sample Testcase 1
Testcase Input
2
0 10
5 5
Testcase Output
10
Explanation
Placing the tower at the midpoint C = 5 gives both houses a distance of 5. To satisfy threshold 5 at distance 5, we need P - 5 ≥ 5, i.e. P ≥ 10. No placement does better, so the minimum power is 10.