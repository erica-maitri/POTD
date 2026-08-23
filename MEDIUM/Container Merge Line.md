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



APPROACH USING STACK:

Imagine the stack like this:

        TOP
         ↓
       [ 3 ]     ← top container
       [ 3 ]     ← second from top
       [ 6 ]
       [ 12 ]
        ↑
      BOTTOM


When a new container arrives, it is always placed at the TOP.

For example, if the stack is:

       TOP
        ↓
       [3]
       [6]
       [12]
      BOTTOM

and another 3 arrives:

       TOP
        ↓
       [3]   ← new container
       [3]
       [6]
       [12]
      BOTTOM

Now compare the TOP TWO:

3 == 3

So remove both:

       [6]
       [12]

and put their sum:

3 + 3 = 6

Now:

       TOP
        ↓
       [6]
       [6]
       [12]
      BOTTOM

Again compare TOP TWO:

6 == 6

Merge them:

6 + 6 = 12

Now:

       TOP
        ↓
       [12]
       [12]
      BOTTOM

Again:

12 == 12

They would merge again if they are equal, and so on.

--------------------------------------------------


FOR THE SAMPLE:

Input:
6
3 3 3 3 5 5


Step 1:
Push 3

TOP
 ↓
[3]
BOTTOM


Step 2:
Push 3

TOP
 ↓
[3]
[3]
BOTTOM

Top two are equal:
3 + 3 = 6

TOP
 ↓
[6]
BOTTOM


Step 3:
Push 3

TOP
 ↓
[3]
[6]
BOTTOM


Step 4:
Push 3

TOP
 ↓
[3]
[3]
[6]
BOTTOM

3 == 3

Merge → 6

TOP
 ↓
[6]
[6]
BOTTOM

Again:

6 == 6

Merge → 12

TOP
 ↓
[12]
BOTTOM


Step 5:
Push 5

TOP
 ↓
[5]
[12]
BOTTOM


Step 6:
Push 5

TOP
 ↓
[5]
[5]
[12]
BOTTOM

5 == 5

Merge → 10

TOP
 ↓
[10]
[12]
BOTTOM


FINAL STACK:

TOP
 ↓
[10]
[12]
BOTTOM

But the question wants:

BOTTOM → TOP

So:

12 10


Therefore:

2
12 10


KEY POINT:

We are NOT comparing the "first two" elements.

We are ALWAYS comparing:

        TOP
         ↓
       [ x ]  ← st.top()
       [ y ]  ← element just below top
       [   ]
       [   ]
      BOTTOM

If x == y:
    remove x and y
    push x + y

Then check again.

So using an actual stack is completely possible, and in fact it matches the problem description very naturally.