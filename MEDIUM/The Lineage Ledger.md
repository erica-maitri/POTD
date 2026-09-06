Problem Statement
Kabir is a royal archivist tasked with digitizing the succession records of an ancient kingdom. The kingdom's history is captured as a single family tree of n rulers, rooted at the founding monarch (ruler 1), where every other ruler is recorded as the direct successor of exactly one earlier ruler. Each successor relationship also carries a number: the count of years that passed between a ruler's coronation and the moment their named successor took the throne.

The royal historians are compiling a commemorative exhibit and keep sending Kabir pairs of rulers, asking two things about each pair: first, how many years separate the two rulers' reigns when traced back through their shared lineage meaning the years accumulated along the unique path connecting them through their nearest common ancestor in the family tree; and second, how many rulers in total appear along that connecting chain, including both endpoints and the common ancestor.

This matters for the exhibit because certain plaques compare "distant" rulers separated by centuries and long lineage chains against rulers who were close relatives separated by only a handful of years, and the historians want both numbers precise down to the ruler and the year. Kabir has the full family tree in front of him thousands of rulers deep in places, with long unbroken chains of succession in one branch and short, bushy branches in another and a growing stack of exhibit pair requests that keeps arriving faster than he can trace paths by hand.

Tracing a single pair by walking up both family branches until they meet is manageable once, but with hundreds of pairs requested and some rulers separated by dozens of generations, doing this by hand for every request before the exhibit opens is simply not feasible. Kabir digitizes the entire family tree every ruler's direct predecessor and the years-gap on that link and hands it to you along with the full list of requested pairs, hoping for both the year-gap and the ruler-count for each one before the exhibit's final proofing deadline.

Input Format
First line: integer n.
Next n−1 lines: three integers u, v, w — ruler v is the direct successor of ruler u, and w years passed between them (1 ≤ u, v ≤ n).
Next line: integer q.
Next q lines: two integers x, y — a requested pair of rulers.
Output Format
q lines, each with two integers: the total years separating x and y along the connecting chain, and the number of rulers on that chain (including both endpoints).

Constraints
2 ≤ n ≤ 2×10^5

1 ≤ q ≤ 2×10^5

1 ≤ w ≤ 10^4

1 ≤ x, y ≤ n

Sample Testcase 0
Testcase Input
6
1 2 10
1 3 5
2 4 7
2 5 3
3 6 8
2
4 5
4 6
Testcase Output
10 3
30 5
Explanation

For (4,5): their nearest common ancestor is ruler 2. Years from 4 up to 2 is 7, from 5 up to 2 is 3, total 10. Rulers on the chain: 4, 2, 5 — 3 rulers.

For (4,6): their nearest common ancestor is the founder, ruler 1. Years from 4 to 1 is 7+10=17, from 6 to 1 is 8+5=13, total 30. Rulers on the chain: 4, 2, 1, 3, 6 — 5 rulers.

Sample Testcase 1
Testcase Input
4
1 2 4
2 3 6
2 4 2
1
3 4
Testcase Output
8 3
Explanation

Ruler 3 and ruler 4 both trace back to ruler 2 as their nearest common ancestor.

Years from 3 to 2 is 6, from 4 to 2 is 2, total 8.

Rulers on the chain are 3, 2, 4 — 3 rulers.

DRY RUN
INPUT
-----

6

1 2 10
1 3 5
2 4 7
2 5 3
3 6 8

2

4 5
4 6


--------------------------------------------------
STEP 1: Read the tree
--------------------------------------------------

Initially:

parent[]    = 0
depth[]     = 0
distance[]  = 0


Read: 1 2 10

v = 2, parent of 2 is 1

parent[2]   = 1
depth[2]    = depth[1] + 1 = 1
distance[2] = distance[1] + 10 = 10


Read: 1 3 5

parent[3]   = 1
depth[3]    = depth[1] + 1 = 1
distance[3] = distance[1] + 5 = 5


Read: 2 4 7

parent[4]   = 2
depth[4]    = depth[2] + 1 = 2
distance[4] = distance[2] + 7 = 17


Read: 2 5 3

parent[5]   = 2
depth[5]    = depth[2] + 1 = 2
distance[5] = distance[2] + 3 = 13


Read: 3 6 8

parent[6]   = 3
depth[6]    = depth[3] + 1 = 2
distance[6] = distance[3] + 8 = 13


So finally:

Ruler       1   2   3   4   5   6
------------------------------------
parent      0   1   1   2   2   3
depth       0   1   1   2   2   2
distance    0  10   5  17  13  13


Tree:

             1
           /   \
        10/     \5
         2       3
       /  \       \
     7/    \3      \8
     4      5       6


--------------------------------------------------
QUERY 1: 4 5
--------------------------------------------------

Start:

a = 4
b = 5

depth[4] = 2
depth[5] = 2

Both have the SAME depth.

So we don't move them here.


Now:

a != b

So move both to their parents:

a = parent[4] = 2
b = parent[5] = 2


Now:

a = 2
b = 2

They are equal.

Therefore:

common = 2


Calculate years:

distance[4] = 17
distance[5] = 13
distance[2] = 10

years = distance[4] + distance[5] - 2 * distance[2]

years = 17 + 13 - 2 * 10
years = 30 - 20
years = 10


Calculate number of rulers:

depth[4] = 2
depth[5] = 2
depth[2] = 1

rulers = depth[4] + depth[5] - 2 * depth[2] + 1

rulers = 2 + 2 - 2 * 1 + 1
rulers = 5 - 2
rulers = 3


OUTPUT:

10 3


Path:

4 → 2 → 5

Years:

7 + 3 = 10

Rulers:

4, 2, 5 = 3


--------------------------------------------------
QUERY 2: 4 6
--------------------------------------------------

Start:

a = 4
b = 6

depth[4] = 2
depth[6] = 2

Both have the SAME depth.

So we don't move them here.


Now:

a != b

Move both to their parents:

a = parent[4] = 2
b = parent[6] = 3


Still:

a != b

Move both again:

a = parent[2] = 1
b = parent[3] = 1


Now:

a = b = 1

Therefore:

common = 1


Calculate years:

distance[4] = 17
distance[6] = 13
distance[1] = 0

years = distance[4] + distance[6] - 2 * distance[1]

years = 17 + 13 - 2 * 0
years = 30


Calculate number of rulers:

depth[4] = 2
depth[6] = 2
depth[1] = 0

rulers = depth[4] + depth[6] - 2 * depth[1] + 1

rulers = 2 + 2 - 2 * 0 + 1
rulers = 5


OUTPUT:

30 5


Path:

4 → 2 → 1 → 3 → 6

Years:

7 + 10 + 5 + 8 = 30

Rulers:

4, 2, 1, 3, 6 = 5


--------------------------------------------------
FINAL OUTPUT
--------------------------------------------------

10 3
30 5

1. Store parent, depth and distance
          ↓
2. Find common ancestor
          ↓
3. Use formulas for years and rulers

Time Complexity  : O(n × q)  [worst case]
Space Complexity : O(n)