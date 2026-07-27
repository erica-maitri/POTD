<<<<<<< HEAD
Problem Statement
More than two centuries after humanity established permanent settlements across the Asterion Cluster, communication between research outposts depends on a collection of ancient energy relays floating in space. Every relay contains a powerful crystal capable of transmitting energy to nearby relays, but activating a relay requires a trained engineer to travel there personally.

Commander Aarav has been assigned to restore the entire relay network before an approaching cosmic storm disconnects the colonies. There are N dormant relays, each identified by a unique number from 1 to N. Aarav begins his journey from the Central Dock, represented as location 0.

Travelling directly between any two locations consumes a known amount of energy. This value may differ depending on the pair of locations involved. After activating a relay, it remains permanently operational, so it never needs to be visited again.

The mission regulations require every relay to be activated exactly once. Once the final relay has been activated, Aarav must return safely to the Central Dock before the storm reaches the sector.

Because the storm is rapidly approaching, the engineering council wants the journey requiring the least possible total energy. They already know the energy required to travel directly between every pair of locations but are unable to evaluate every possible activation order because the number of possibilities becomes enormous even for a modest number of relays.

Help the council determine the minimum amount of energy Aarav must spend to complete the restoration mission while following every regulation.

The answer should be a single integer representing the minimum total energy required.

Input Format
The first line contains an integer N, representing the number of dormant relays.
The next N + 1 lines each contain N + 1 space-separated integers.
The value in row i and column j represents the energy required to travel directly from location i to location j.
Location 0 represents the Central Dock.
Locations 1 to N represent the relays.
Output Format
Print a single integer representing the minimum total energy required to activate every relay exactly once and return to the Central Dock.

Constraints
1 ≤ N ≤ 16
0 ≤ Energy ≤ 10^6
Energy(i, i) = 0
Every relay is reachable.
The energy matrix is not necessarily symmetric.
Sample Testcase 0
Testcase Input
3
0 8 6 10
5 0 7 9
4 3 0 8
9 6 5 0
Testcase Output
23
Explanation
Possible activation orders are:


Route

Total Energy

0 → 1 → 2 → 3 → 0

32

0 → 1 → 3 → 2 → 0

26

0 → 2 → 1 → 3 → 0

27

0 → 2 → 3 → 1 → 0

25

0 → 3 → 1 → 2 → 0

27

0 → 3 → 2 → 1 → 0

23


Among all valid journeys, the minimum energy is: 23

Sample Testcase 1
Testcase Input
2
0 4 9
6 0 3
5 8 0
Testcase Output
12
Explanation
There are two possible activation orders.


Route 1: 0 → 1 → 2 → 0


Energy: 4 + 3 + 5 = 12


Route 2: 0 → 2 → 1 → 0


Energy: 9 + 8 + 6 = 23


The smaller value is: 12


Hence the answer is


12

/*Think of it as visiting cities.

Node 0 = Starting city (also where you must return).
Nodes 1..N = Cities that must be visited exactly once.

Goal:
Start from 0
→ Visit every city (1..N) exactly once
→ Return to 0
→ Minimize the total travel cost.

Example (N = 3):

      1
     / \
    2   3

Start: 0

Possible routes:
0 → 1 → 2 → 3 → 0
0 → 1 → 3 → 2 → 0
0 → 2 → 1 → 3 → 0
0 → 2 → 3 → 1 → 0
0 → 3 → 1 → 2 → 0
0 → 3 → 2 → 1 → 0

For each route:
Total Cost =
cost(0→A) +
cost(A→B) +
cost(B→C) +
cost(C→0)

Answer = Minimum of all route costs.

Since N can be up to 16, checking all N! routes is too slow.
So we use DP + Bitmask:
dp[mask][u] = Minimum cost to start from 0,
visit all cities in 'mask',
and currently be at city 'u'.

Transition:
dp[newMask][v] =
min(dp[newMask][v],
    dp[mask][u] + cost[u][v])

Finally:
answer =
min(dp[allVisited][u] + cost[u][0])
for every last city u.
=======
Problem Statement
More than two centuries after humanity established permanent settlements across the Asterion Cluster, communication between research outposts depends on a collection of ancient energy relays floating in space. Every relay contains a powerful crystal capable of transmitting energy to nearby relays, but activating a relay requires a trained engineer to travel there personally.

Commander Aarav has been assigned to restore the entire relay network before an approaching cosmic storm disconnects the colonies. There are N dormant relays, each identified by a unique number from 1 to N. Aarav begins his journey from the Central Dock, represented as location 0.

Travelling directly between any two locations consumes a known amount of energy. This value may differ depending on the pair of locations involved. After activating a relay, it remains permanently operational, so it never needs to be visited again.

The mission regulations require every relay to be activated exactly once. Once the final relay has been activated, Aarav must return safely to the Central Dock before the storm reaches the sector.

Because the storm is rapidly approaching, the engineering council wants the journey requiring the least possible total energy. They already know the energy required to travel directly between every pair of locations but are unable to evaluate every possible activation order because the number of possibilities becomes enormous even for a modest number of relays.

Help the council determine the minimum amount of energy Aarav must spend to complete the restoration mission while following every regulation.

The answer should be a single integer representing the minimum total energy required.

Input Format
The first line contains an integer N, representing the number of dormant relays.
The next N + 1 lines each contain N + 1 space-separated integers.
The value in row i and column j represents the energy required to travel directly from location i to location j.
Location 0 represents the Central Dock.
Locations 1 to N represent the relays.
Output Format
Print a single integer representing the minimum total energy required to activate every relay exactly once and return to the Central Dock.

Constraints
1 ≤ N ≤ 16
0 ≤ Energy ≤ 10^6
Energy(i, i) = 0
Every relay is reachable.
The energy matrix is not necessarily symmetric.
Sample Testcase 0
Testcase Input
3
0 8 6 10
5 0 7 9
4 3 0 8
9 6 5 0
Testcase Output
23
Explanation
Possible activation orders are:


Route

Total Energy

0 → 1 → 2 → 3 → 0

32

0 → 1 → 3 → 2 → 0

26

0 → 2 → 1 → 3 → 0

27

0 → 2 → 3 → 1 → 0

25

0 → 3 → 1 → 2 → 0

27

0 → 3 → 2 → 1 → 0

23


Among all valid journeys, the minimum energy is: 23

Sample Testcase 1
Testcase Input
2
0 4 9
6 0 3
5 8 0
Testcase Output
12
Explanation
There are two possible activation orders.


Route 1: 0 → 1 → 2 → 0


Energy: 4 + 3 + 5 = 12


Route 2: 0 → 2 → 1 → 0


Energy: 9 + 8 + 6 = 23


The smaller value is: 12


Hence the answer is


12

/*Think of it as visiting cities.

Node 0 = Starting city (also where you must return).
Nodes 1..N = Cities that must be visited exactly once.

Goal:
Start from 0
→ Visit every city (1..N) exactly once
→ Return to 0
→ Minimize the total travel cost.

Example (N = 3):

      1
     / \
    2   3

Start: 0

Possible routes:
0 → 1 → 2 → 3 → 0
0 → 1 → 3 → 2 → 0
0 → 2 → 1 → 3 → 0
0 → 2 → 3 → 1 → 0
0 → 3 → 1 → 2 → 0
0 → 3 → 2 → 1 → 0

For each route:
Total Cost =
cost(0→A) +
cost(A→B) +
cost(B→C) +
cost(C→0)

Answer = Minimum of all route costs.

Since N can be up to 16, checking all N! routes is too slow.
So we use DP + Bitmask:
dp[mask][u] = Minimum cost to start from 0,
visit all cities in 'mask',
and currently be at city 'u'.

Transition:
dp[newMask][v] =
min(dp[newMask][v],
    dp[mask][u] + cost[u][v])

Finally:
answer =
min(dp[allVisited][u] + cost[u][0])
for every last city u.
>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
*/