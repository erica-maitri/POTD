Problem Statement
A company has N employees numbered 1 to N, organized into a strict reporting tree rooted at employee 1 (the CEO). This tree is described by N-1 edges; each edge connects an employee to their direct manager and carries an integer "adjustment score" that gets added to a running total as you move from the manager to the report.

For any employee v, define pathScore(v) as the sum of adjustment scores along the unique path from the root (employee 1) down to v (with pathScore(1) = 0, since the root has no incoming edge).

For an employee v, define spread(v) as the difference between the maximum pathScore and the minimum pathScore found among all employees in the subtree rooted at v (this subtree includes v itself and every employee who reports to v, directly or indirectly).

You are given Q queries, each naming an employee v. For each query, output spread(v).

Input Format
N

u1 v1 w1

u2 v2 w2

...

u(N-1) v(N-1) w(N-1)

Q

v1

v2

...

vQ

 

Each of the N-1 edge lines gives two employee IDs u, v connected by an edge and the adjustment score w on that edge. The edges form a valid tree rooted at 1.

Output Format
For each query, print spread(v) on its own line.

Constraints
2 ≤ N ≤ 2 × 10^5
1 ≤ Q ≤ 2 × 10^5
1 ≤ u, v ≤ N
-10^9 ≤ w ≤ 10^9
1 ≤ query employee ≤ N
Time Limit: 1.5 sec
Memory Limit: 256 MB
The output is unique.
Sample Testcase 0
Testcase Input
4
1 2 5
1 3 10
1 4 -5
3
1
2
4
Testcase Output
15
0
0
Explanation
Path scores: 1=0, 2=5, 3=10, 4=-5. Subtree(1) contains all four scores {0,5,10,-5}: max=10, min=-5, spread=15. Employees 2 and 4 are leaves, so their own subtree spread is 0.

Sample Testcase 1
Testcase Input
6
1 2 5
1 3 -2
2 4 3
2 5 -6
3 6 4
4
1
2
3
4
Testcase Output
10
9
4
0
Explanation
Path scores: employee1=0, 2=5, 3=-2, 4=8, 5=-1, 6=2. Subtree(1) = everyone, max=8 (emp 4), min=-2 (emp 3), spread=10. Subtree(2) = {2,4,5} with scores {5,8,-1}, max=8, min=-1, spread=9. Subtree(3) = {3,6} with scores {-2,2}, spread=4. Subtree(4) = {4} alone, spread=0.

Sample 2

Tree:

        1
      /   \
   +5/     \-2
    2       3
   / \       \
 +3  -6      +4
 4     5      6

Path Scores:

1 = 0
2 = 5
3 = -2
4 = 8
5 = -1
6 = 2
Subtree(1) = {1,2,3,4,5,6}
Scores = {0,5,-2,8,-1,2}
Max = 8, Min = -2
Spread = 10
Subtree(2) = {2,4,5}
Scores = {5,8,-1}
Max = 8, Min = -1
Spread = 9
Subtree(3) = {3,6}
Scores = {-2,2}
Max = 2, Min = -2
Spread = 4
Subtree(4) = {4}
Spread = 0
What the problem is asking
Compute the pathScore of every node from the root.(one node at a time then its children, grandchildren, etc.)
For every node, find the minimum and maximum pathScore inside its subtree.
Store spread = max - min.
For each query, simply print the stored spread of that node.

In simple words: Each node asks, "Among me and all my descendants, how far apart are the highest and lowest path scores?" That difference is the answer.