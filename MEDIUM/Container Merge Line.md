Problem Statement
A cargo yard receives n containers one at a time, in a fixed order. Each container has a positive integer weight. As each container arrives, it is placed on top of a holding stack.

Immediately after a container is placed, the following merge rule is checked: if the two topmost containers on the stack currently have equal weight, they are removed and replaced by a single new container whose weight is their sum. This check is then repeated on the new top of the stack — merging cascades for as long as the top two containers remain equal — before the next container is allowed to arrive.

After all n containers have arrived and all resulting merges are complete, report the final number of containers on the stack and their weights, listed from the bottom of the stack to the top.

Input Format
Line 1: an integer n.

Line 2: n integers w_1, w_2, ..., w_n — the weights of the containers in the order they arrive.

Output Format
Line 1: an integer m — the final number of containers remaining.

Line 2: m integers — the final container weights, from bottom to top, separated by spaces.

Constraints
1 ≤ n ≤ 2 × 10^5
1 ≤ w_i ≤ 10^9
Time Limit: 1 sec
Memory Limit: 256 MB
Use 64-bit integers for weights, since merged weights can exceed the range of a 32-bit integer.
The output is unique.
Sample Testcase 0
Testcase Input
4
1 2 3 4
Testcase Output
4
1 2 3 4
Explanation
No two adjacent containers on the stack are ever equal, so no merges occur at any point.

Sample Testcase 1
Testcase Input
6
3 3 3 3 5 5
Testcase Output
2
12 10
Explanation
Containers 3,3 merge to 6. Then 3 arrives (stack: 6,3). Then 3 arrives (stack: 6,3,3), which merges 3,3→6 (stack: 6,6), which cascades and merges 6,6→12 (stack: 12). Then 5,5 arrive and merge to 10 (stack: 12,10).