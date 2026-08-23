Problem Statement
An airport gate processes passengers using a boarding queue. Passengers are numbered 1, 2, 3, ... in the order they will eventually arrive at the gate (passenger 1 always arrives before passenger 2, and so on).

You are given a sequence of m operations, each of one of three types:

A — The next passenger (in increasing order of id, starting from 1) arrives and joins the back of the current boarding queue.
P x — If passenger x is currently present anywhere in the queue, they are immediately moved to the front of the queue (a priority reshuffle). If passenger x has not yet arrived, or has already boarded, or is otherwise not in the queue, this operation has no effect.
B — The passenger currently at the front of the queue boards the plane and is removed from the queue; print their id. If the queue is empty at this moment, print 0 instead (no one boards).
Process the operations in the given order and report the result of every B operation.

Input Format
Line 1: two integers n and m — total number of passengers who could ever arrive, and total number of operations.

Next m lines: one operation each, in the format A, P x, or B.

Output Format
For every B operation (in order), print one line containing the id of the passenger who boarded, or 0 if the queue was empty.

Constraints
1 ≤ n ≤ 2000
1 ≤ m ≤ 4000
The total number of A operations is at most n.
For every P x operation, 1 ≤ x ≤ n.
Time Limit: 1 sec
Memory Limit: 256 MB
The output is unique.
Sample Testcase 0
Testcase Input
2 4
B
A
P 1
B
Testcase Output
0
1
Explanation
The first B finds an empty queue, so it prints 0. Passenger 1 then arrives, P 1 moves them to front (no visible change since already at front), and the final B boards passenger 1.

Sample Testcase 1
Testcase Input
5 10
A
A
P 2
B
A
P 4
B
B
A
B
Testcase Output
2
1
3
4
Explanation
Passengers 1 then 2 arrive (queue: 1,2). P 2 moves passenger 2 to front (queue: 2,1). B boards 2 (queue: 1). Passenger 3 arrives (queue: 1,3). P 4 has no effect since passenger 4 has not arrived yet. B boards 1, then B boards 3 (queue empty). Passenger 4 arrives (queue: 4). B boards 4.