Problem Statement
In the ancient Kingdom of Arvandor, every city was connected through a carefully planned network of roads. The kingdom was designed in such a way that there was exactly one possible route between any two cities, ensuring that travelers never had to choose between multiple paths. City 1 served as the capital and acted as the center of administration, trade, and communication for the entire kingdom.

As new settlements were established, the kingdom grew larger and more complex. The king wanted to understand how far his influence extended across the land. Instead of measuring the actual physical length of roads, he defined the distance of a city as the number of roads that must be crossed to travel from the capital to that city.

Cities directly connected to the capital have a distance of 1, cities reached through two roads have a distance of 2, and so on.

To prepare for future expansion and improve communication across the kingdom, the king instructed his royal advisors to identify the settlement that is farthest from the capital.

Your task is to analyze the network of cities and determine the maximum distance from City 1 to any other city in the kingdom.

Input Format
The first line contains an integer N, representing the number of cities.

The next N - 1 lines contain two integers U and V, indicating a road connecting City U and City V.

Output Format
Print a single integer representing the maximum number of roads that must be traveled to reach the farthest city from City 1.

Constraints
1 ≤ N ≤ 200000
1 ≤ U, V ≤ N

Sample Testcase 0
Testcase Input
7
1 2
1 3
2 4
2 5
3 6
6 7
Testcase Output
3
Explanation
Kingdom Structure:


        1
       /  \
      2   3
     /  \    \
    4   5   6
                \
                 7


Distances from City 1:


City 1 -> 0
City 2 -> 1
City 3 -> 1
City 4 -> 2
City 5 -> 2
City 6 -> 2
City 7 -> 3


The farthest city is City 7 at distance 3.


Therefore, the answer is:


3

Sample Testcase 1
Testcase Input
8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
Testcase Output
7
Explanation
Kingdom Structure:


1 - 2 - 3 - 4 - 5 - 6 - 7 - 8


Distances from City 1:


City 1 -> 0
City 2 -> 1
City 3 -> 2
City 4 -> 3
City 5 -> 4
City 6 -> 5
City 7 -> 6
City 8 -> 7


The farthest city is City 8, requiring 7 roads to be traveled from the capital.


Therefore, the answer is:


7

dry run 

Input:
7
1 2
1 3
2 4
2 5
3 6
6 7

Adjacency List:
1 -> 2, 3
2 -> 1, 4, 5
3 -> 1, 6
4 -> 2
5 -> 2
6 -> 3, 7
7 -> 6

-------------------------------------------------
Initialization

dist = [-1, 0, -1, -1, -1, -1, -1, -1]
        0  1   2   3   4   5   6   7
(queue index 0 is unused)

Queue = [1]

-------------------------------------------------
Iteration 1

Pop 1

Neighbors of 1:
2 -> not visited
dist[2] = dist[1] + 1 = 1
Push 2

3 -> not visited
dist[3] = dist[1] + 1 = 1
Push 3

Queue = [2, 3]

dist =
1 : 0
2 : 1
3 : 1
4 : -1
5 : -1
6 : -1
7 : -1

-------------------------------------------------
Iteration 2

Pop 2

Neighbors:
1 -> already visited

4 -> not visited
dist[4] = 2
Push 4

5 -> not visited
dist[5] = 2
Push 5

Queue = [3, 4, 5]

dist =
1 : 0
2 : 1
3 : 1
4 : 2
5 : 2
6 : -1
7 : -1

-------------------------------------------------
Iteration 3

Pop 3

Neighbors:
1 -> visited

6 -> not visited
dist[6] = 2
Push 6

Queue = [4, 5, 6]

dist =
1 : 0
2 : 1
3 : 1
4 : 2
5 : 2
6 : 2
7 : -1

-------------------------------------------------
Iteration 4

Pop 4

Neighbor:
2 -> already visited

Queue = [5, 6]

-------------------------------------------------
Iteration 5

Pop 5

Neighbor:
2 -> already visited

Queue = [6]

-------------------------------------------------
Iteration 6

Pop 6

Neighbors:
3 -> already visited

7 -> not visited
dist[7] = dist[6] + 1 = 3
Push 7

Queue = [7]

dist =
1 : 0
2 : 1
3 : 1
4 : 2
5 : 2
6 : 2
7 : 3

-------------------------------------------------
Iteration 7

Pop 7

Neighbor:
6 -> already visited

Queue = []

BFS Ends.

-------------------------------------------------
Find Maximum Distance

ans = 0

dist[1] = 0  -> ans = 0
dist[2] = 1  -> ans = 1
dist[3] = 1  -> ans = 1
dist[4] = 2  -> ans = 2
dist[5] = 2  -> ans = 2
dist[6] = 2  -> ans = 2
dist[7] = 3  -> ans = 3

Output:
3

Time Complexity
O(N) (each node and edge is visited once)
Space Complexity
O(N) (adjacency list, distance array, and queue)

This solution works efficiently for the given constraint N ≤ 200000