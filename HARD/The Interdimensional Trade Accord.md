Problem Statement
In the year 4821, humanity has established diplomatic and commercial relations with dozens of civilizations spread across parallel dimensions. To facilitate trade, the Interdimensional Trade Council (ITC) maintains a network of dimensional gateways connecting various worlds.

Each world is assigned a unique identifier from 1 to N. A gateway between two worlds allows cargo to be transported directly, but every transfer incurs an energy tax due to dimensional stabilization costs.

Over centuries, the network has expanded unpredictably. Some worlds are connected directly, while others require passage through several intermediate worlds.

Recently, the ITC discovered that smugglers have been exploiting inefficient routing policies. To combat this, the council wants to determine the minimum possible Energy Tax required to transport goods between every pair of worlds.

After computing the most efficient routes, the council receives several audit requests. Each request contains two worlds, and the council must report the minimum Energy Tax required to move cargo between them.

If no route exists between two worlds, the transport is considered impossible.

Your task is to assist the ITC by processing the gateway network and answering all audit requests.

Figure

                     [1]
                    /    \
                  5     12
                 /          \
               [2]---3---[3]
                 \           /
                  4       7
                    \     /
                     [4]

Input Format
First line contains three integers:

N M Q

where:

* N = number of worlds
* M = number of gateways
* Q = number of audit requests
* Next M lines contain:

U V W

representing a bidirectional gateway between worlds U and V with Energy Tax W.

* Next Q lines contain:

A B

representing an audit request asking for the minimum Energy Tax between worlds A and B.

Output Format
For each audit request:

* Print the minimum energy tax.
* Print `-1` if transportation is impossible.

Constraints
2  ≤  N  ≤  400
1  ≤  M  ≤  N(N−1)/2
1  ≤  Q  ≤  100000

1  ≤  W  ≤  109

Sample Testcase 0
Testcase Input
4 5 3
1 2 5
1 3 12
2 3 3
2 4 4
3 4 7
1 3
1 4
3 4
Testcase Output
8
9
7
Explanation
For query (1,3):


1 → 2 → 3


5 + 3 = 8


which is cheaper than direct cost 12.


For query (1,4):


1 → 2 → 4


5 + 4 = 9


For query (3,4):


Direct route already costs 7.

Sample Testcase 1
Testcase Input
5 3 3
1 2 6
2 3 5
4 5 2
1 3
1 5
4 5
Testcase Output
11
-1
2
Explanation
1 → 2 → 3 = 11


No route exists between worlds 1 and 5.


For worlds 4 and 5, direct cost is 2.

.........
There is no problem with Dijkstra itself—it is actually the best algorithm for large graphs. The problem is how many times you have to run it.

- Dijkstra finds shortest paths from only ONE source.
- Here, queries can ask for ANY pair (A, B).
- So you would have to run Dijkstra from every node (400 times) or for every query (100000 times).

Comparison:

✔ Floyd–Warshall:
- Runs once.
- Time = O(N³) = 400³ = 64 million operations.
- Every query is answered in O(1).

✔ Dijkstra:
- One run = shortest paths from one node only.
- To answer all possible queries, run it 400 times.
- Time = O(N × (M log N)), which is larger than Floyd here because the graph can be very dense (M ≈ N²).

Rule:
- Small N (≈ 500 or less) → Floyd–Warshall is usually better for all-pairs shortest paths.
- Large N (thousands or more) → Floyd is impossible (N³ is huge), so Dijkstra is used.