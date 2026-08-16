Problem Statement
A village maintains a single community water tank. Over N days, the net change in water level on day i is given by A[i] (a positive value means water was added that day, a negative value means water was consumed and the level dropped). The tank is assumed to start a query window at level 0 — i.e., for a given range of days you only care about the relative change in level across those days, not the absolute level of the tank on day 1.

You will be asked Q independent queries. Each query gives a day range [L, R] (1-indexed, inclusive). For that query you must report:

The total net change in tank level from day L to day R (i.e., the sum A[L] + A[L+1] + ... + A[R]).
A one-word status describing that change:
SURPLUS if the total is strictly greater than 0
DEFICIT if the total is strictly less than 0
BALANCED if the total is exactly 0
Input Format
N

A[1] A[2] ... A[N]

Q

L1 R1

L2 R2

...

LQ RQ

Output Format
For each query, print the sum and the status word, separated by a single space, on their own line.

Constraints
1 ≤ N ≤ 2 × 10^5
1 ≤ Q ≤ 2 × 10^5
-10^9 ≤ A[i] ≤ 10^9
1 ≤ L ≤ R ≤ N
Time Limit: 1 sec
Memory Limit: 256 MB
The output is unique
Sample Testcase 0
Testcase Input
6
5 -3 2 -8 4 6
3
1 3
2 4
1 6
Testcase Output
4 SURPLUS
-9 DEFICIT
6 SURPLUS
Explanation
For query (1,3): 5 + (-3) + 2 = 4, which is positive, so SURPLUS. For query (2,4): (-3) + 2 + (-8) = -9, negative, so DEFICIT. For query (1,6): 5-3+2-8+4+6 = 6, positive, so SURPLUS.

Sample Testcase 1
Testcase Input
4
5 -5 10 -10
1
1 4
Testcase Output
0 BALANCED
Explanation
5 - 5 + 10 - 10 = 0, so the status is BALANCED.