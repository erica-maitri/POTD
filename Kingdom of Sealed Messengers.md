Problem Statement
For centuries, the Kingdom of Valoria has relied on enchanted messengers to carry royal orders between cities.

Each city may possess one-way messenger portals leading to other cities. If a messenger enters a portal, they immediately appear in the destination city. Over time, a complicated network of portals has formed throughout the kingdom.

Princess Meera is planning a grand royal announcement. She wishes for the announcement to eventually reach every city in the kingdom.

The kingdom's scholars have discovered an unusual property of the portal system. In some groups of cities, a messenger can travel from any city in the group to every other city in the same group using a sequence of portals. These groups are called communication circles.

Instead of placing royal announcers in every city, Meera wants to place them only in carefully chosen cities.

Whenever a city initially receives the announcement, messengers begin using the portals automatically. Every city reachable through the portal network from that starting city eventually learns the announcement.

The royal treasury wants to spend as little gold as possible. Therefore, Meera wants to determine the minimum number of cities in which announcers must be stationed initially so that eventually every city in the kingdom hears the announcement.

Input Format
The first line contains two integers N and M.
●​ N = number of cities
●​ M = number of portals
The next M lines contain two integers U and V indicating a portal from U to V.

Output Format
Print a single integer representing the minimum number of initial announcers required.

Constraints
1 ≤ N ≤ 2 × 105
0 ≤ M ≤ 3 × 105
1 ≤ U, V ≤ N

Sample Testcase 0
Testcase Input
4 4
1 2
2 3
3 4
4 1
Testcase Output
1
Explanation
All cities belong to the same communication circle.
One announcer is enough.

Sample Testcase 1
Testcase Input
5 5
1 2
2 3
3 1
4 5
4 5
Testcase Output
2
Explanation
Communication circles:
{1,2,3}
{4}
{5}
Only two circles have no incoming information from another circle:
{1,2,3}
{4}
Thus two starting announcers are sufficient.


..........................................

PROBLEM IN SIMPLE WORDS

You are given:
- N cities (nodes)
- M one-way portals (directed edges)

A portal U → V means:
If city U receives the announcement, it can send it to city V.

If you place an announcer in a city, the announcement automatically spreads through all cities that can be reached from it.

Your task is to find the minimum number of starting cities (where announcers are placed) so that eventually every city receives the announcement.

--------------------------------------------------

Example 1

1 → 2 → 3 → 4
↑           ↓
└───────────┘

Every city can reach every other city.

Starting from any one city spreads the announcement to all cities.

Answer = 1

--------------------------------------------------

Example 2

1 → 2 → 3
↑       ↓
└───────┘

4 → 5

Cities {1,2,3} form one cycle.
City 4 can reach 5.
City 5 cannot reach 4.

If we start from city 1:
Announcement reaches only {1,2,3}.

If we start from city 4:
Announcement reaches {4,5}.

So we need two starting cities.

Answer = 2

--------------------------------------------------

Strongly Connected Component (SCC)

An SCC is a group of cities where every city can reach every other city.

Example:

1 → 2
↑   ↓
└── 3

From any city (1,2,3), you can reach the other two.

So they behave like one single unit.

--------------------------------------------------

Compress the Graph

Treat every SCC as one node.

Example:

{1,2,3} 
{4} → {5}

This compressed graph has no cycles.
It is called a DAG (Directed Acyclic Graph).
Indegree of each SCC
{1,2,3} → indegree = 0
{4} → indegree = 0
{5} → indegree = 1 (from {4})

There are 2 SCCs with indegree 0, so the answer is 2.

--------------------------------------------------

Which SCCs need an announcer?

Only the SCCs that have NO incoming edges from another SCC.

Reason:
If no other SCC can send information into them,
the announcement must start inside them.

--------------------------------------------------

Example

A → B → C

D → C

Incoming edges:

A : none
B : from A
C : from B and D
D : none

SCCs with indegree 0:
A and D

Answer = 2

--------------------------------------------------

Another Example

A → B
|
v
C

Incoming edges:

A : none
B : from A
C : from A

Starting from A reaches everyone.

Answer = 1

--------------------------------------------------

Final Idea / Algorithm

1. Find all Strongly Connected Components (SCCs).
2. Compress each SCC into a single node.
3. Compute the indegree of every SCC in the compressed graph.
4. Count how many SCCs have indegree = 0.
5. That count is the minimum number of starting announcers required.

--------------------------------------------------

Key Observation

Minimum announcers required
=
Number of SCCs with zero incoming edges.
```
