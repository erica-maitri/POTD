<<<<<<< HEAD
Problem Statement
Nisha coordinates the lantern display for the Diyari night festival. The lanterns are hung in a single long row, numbered 1 to n, and each lantern i currently glows with a brightness value a[i]. The festival's lighting controller can send two kinds of commands to the row throughout the evening, and Nisha needs a system that reacts to each command the instant it arrives.

The first kind of command targets a contiguous stretch of lanterns from position l to position r and specifies a ceiling value v. Every lantern in that stretch whose brightness currently exceeds v is dimmed down so that its new brightness becomes exactly v; lanterns in the stretch that are already at or below v are left completely untouched. This mimics how the festival's dimmer boxes actually work — they can only pull bright lanterns down to a ceiling, never push dim ones up.

The second kind of command also targets a contiguous stretch l to r, but instead of changing anything, it asks for the total combined brightness of every lantern in that stretch at that exact moment, which the festival's power-planning team uses to make sure the local generators are not overloaded.

Over the course of the evening, Nisha receives a long sequence of these two kinds of commands, alternating unpredictably, and after every brightness-total command she must announce the answer before the next command can be processed, since the generator team is waiting live. Because thousands of lanterns and tens of thousands of commands are expected during the festival's peak hours, and because a ceiling command might only change a handful of the brightest lanterns in a huge stretch while leaving the rest untouched, Nisha cannot afford to walk through every lantern in a stretch each time — she needs a way to apply ceiling commands and answer brightness totals that stays fast even in the worst case, where commands keep targeting the same huge stretch of lanterns over and over.

Input Format
Line 1: two integers n q.

Line 2: n integers — the initial brightness values a[1..n].

Next q lines, each one of:

1 l r v — cap every lantern in [l, r] whose brightness exceeds v down to v.
2 l r — report the sum of brightness over [l, r].
Output Format
For every command of type 2, print the requested sum on its own line, in order.

Constraints
1 ≤ n, q ≤ 200000
1 ≤ a[i], v ≤ 109
1 ≤ l ≤ r ≤ n
Applying each ceiling command by scanning every lantern in the range, or using a plain range-assignment segment tree that cannot distinguish which lanterns actually exceed the ceiling, will exceed the time limit on the hidden tests.
Sample Testcase 0
Testcase Input
6 3
10 10 10 10 10 10
2 1 6
1 1 6 5
2 1 6
Testcase Output
60
30
Explanation
All six lanterns start at 10, so the first sum query over [1,6] is 60. 


The ceiling command caps everything above 5 down to 5, so every lantern becomes 5 (since all were equal, there is no "second-highest" value to stop the operation early — the whole range collapses at once). 


The final sum over [1,6] is 6×5=30.

Sample Testcase 1
Testcase Input
5 4
7 2 5 9 3
1 1 5 6
2 1 5
1 2 4 4
2 1 5
Testcase Output
22
19
Explanation
Initial row: 7 2 5 9 3. 


The first command caps [1,5] to 6: lantern 1 (7>6) becomes 6, lantern 4 (9>6) becomes 6, the rest (2, 5, 3) are already ≤6 and stay. 


Row becomes 6 2 5 6 3, whose sum over [1,5] is 6+2+5+6+3=22. 


The next command caps [2,4] to 4: within positions 2–4 the values are 2,5,6; 2 stays, 5>4 becomes 4, 6>4 becomes 4. 


Row becomes 6 2 4 4 3, whose sum over [1,5] is 6+2+4+4+3=19.

....................

```
PROBLEM SIMPLIFIED
You are given an array of n numbers.
Example:
A = [7, 2, 5, 9, 3]
There are only TWO types of queries.
---------------------------------------------------
TYPE 1
---------------------------------------------------
Input format:
1 l r v
Meaning:
Look at every element from index l to index r.
If an element is greater than v, replace it with v.
Otherwise, leave it unchanged.
Mathematically:
A[i] = min(A[i], v)
for every i in [l, r].
Notice:
- Values can only decrease.
- No value is ever increased.
---------------------------------------------------
Example 1
---------------------------------------------------
Array:
7 2 5 9 3
Query:
1 1 5 6
Check every element.
7 > 6 → becomes 6
2 ≤ 6 → stays 2
5 ≤ 6 → stays 5
9 > 6 → becomes 6
3 ≤ 6 → stays 3
New array:
6 2 5 6 3
---------------------------------------------------
Example 2
---------------------------------------------------
Current array:
6 2 5 6 3
Query:
1 2 4 4
Only positions 2 to 4 are affected.
Values are:
2 5 6
Compare each with 4.
2 → stays 2
5 → becomes 4
6 → becomes 4
New array:
6 2 4 4 3
---------------------------------------------------
TYPE 2
---------------------------------------------------
Input format:
2 l r
Meaning:
Find the sum of all elements from index l to r.
Nothing in the array changes.
---------------------------------------------------
Example
---------------------------------------------------
Array:
6 2 5 6 3
Query:
2 1 5
Sum =
6 + 2 + 5 + 6 + 3 = 22
Output:
22
===================================================
SAMPLE TESTCASE 1
===================================================
Initial array:
7 2 5 9 3
-----------------------------------
Query 1
-----------------------------------
1 1 5 6
Cap every value at 6.
7 → 6
2 → 2
5 → 5
9 → 6
3 → 3
Array becomes:
6 2 5 6 3
-----------------------------------
Query 2
-----------------------------------
2 1 5
Sum:
6 + 2 + 5 + 6 + 3 = 22
Output:
22
-----------------------------------
Query 3
-----------------------------------
1 2 4 4
Only indices 2 to 4.
Current values:
2 5 6
Apply cap 4.
2 → 2
5 → 4
6 → 4
Array becomes:
6 2 4 4 3
-----------------------------------
Query 4
-----------------------------------
2 1 5
Sum:
6 + 2 + 4 + 4 + 3 = 19
Output:
19
===================================================
SAMPLE TESTCASE 0
===================================================
Initial array:
10 10 10 10 10 10
-----------------------------------
Query 1
-----------------------------------
2 1 6
Sum:
10 + 10 + 10 + 10 + 10 + 10 = 60
Output:
60
-----------------------------------
Query 2
-----------------------------------
1 1 6 5
Cap every value at 5.
10 → 5
10 → 5
10 → 5
10 → 5
10 → 5
10 → 5
Array becomes:
5 5 5 5 5 5
-----------------------------------
Query 3
-----------------------------------
2 1 6
Sum:
5 + 5 + 5 + 5 + 5 + 5 = 30
Output:
30
===================================================
IMPORTANT OBSERVATION
===================================================
Operation 1 does NOT replace every value with v.
It ONLY changes values that are greater than v.
Example:
Array:
3 8 2 10 5
Query:
1 1 5 6
Result:
3 6 2 6 5
NOT
6 6 6 6 6
because values already smaller than 6 remain unchanged.
===================================================
WHY THIS PROBLEM IS HARD
===================================================
The operations themselves are very easy.
The difficulty comes from the constraints:
1 ≤ n, q ≤ 200000
If every Type 1 query scans every element in its range, it can take O(n).
In the worst case:
200000 queries × 200000 elements = 40,000,000,000 operations
which is far too slow.
Therefore, a normal array solution or ordinary lazy segment tree is not enough.
The intended solution uses a special data structure called "Segment Tree Beats", which can efficiently handle:
1. Range min-update (A[i] = min(A[i], v))
2. Range sum queries
```
...................
```text
CODE IDEA
Store the array and process each query directly.

--------------------------------------------------
TYPE 1 : 1 l r v
--------------------------------------------------
For every element from index l to r:
a[i] = min(a[i], v)

If a[i] > v, it becomes v.
Otherwise, it remains unchanged.

Time Complexity:
O(r - l + 1)

Worst Case:
O(n)

--------------------------------------------------
TYPE 2 : 2 l r
--------------------------------------------------
Traverse from l to r.
Add every element to the sum.
Print the sum.

Time Complexity:
O(r - l + 1)

Worst Case:
O(n)

--------------------------------------------------
OVERALL TIME COMPLEXITY
--------------------------------------------------
If there are q queries:

Worst Case:
O(n × q)

Given:
n = 200000
q = 200000

Worst Case Operations:
200000 × 200000
= 40,000,000,000 (40 Billion)

Normally, this would give TLE if worst-case tests are used.

--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------
Only one array is stored.

Space Complexity:
O(n)

--------------------------------------------------
WHEN TO USE THIS APPROACH
--------------------------------------------------
Use this approach when:

✔ n is small (around 10^3 or 10^4)
✔ q is small (around 10^3 or 10^4)
✔ Total operations (n × q) are manageable (around 10^7 to 10^8)
✔ No advanced data structure is required.

--------------------------------------------------
WHEN NOT TO USE
--------------------------------------------------
Do NOT use it when:

✘ n and q are both very large (like 2×10^5)
✘ Worst-case range updates/queries are frequent
✘ The problem expects Segment Tree, Lazy Propagation,
  Fenwick Tree, or Segment Tree Beats.

--------------------------------------------------
RULE OF THUMB
--------------------------------------------------
n ≤ 10^3                    → Brute Force
n ≤ 10^5 (few queries)      → Brute Force may work
n,q ≤ 2×10^5                → Segment Tree / BIT / Advanced DS
n,q ≤ 10^6                  → Optimized Data Structure required

--------------------------------------------------
NOTE
--------------------------------------------------
Although the problem statement suggests Segment Tree Beats,
your brute-force solution was accepted.

This means the hidden test cases are likely not strict enough
to force the worst-case O(n × q) behavior, so the simple
solution passes successfully.
```
=======
Problem Statement
Nisha coordinates the lantern display for the Diyari night festival. The lanterns are hung in a single long row, numbered 1 to n, and each lantern i currently glows with a brightness value a[i]. The festival's lighting controller can send two kinds of commands to the row throughout the evening, and Nisha needs a system that reacts to each command the instant it arrives.

The first kind of command targets a contiguous stretch of lanterns from position l to position r and specifies a ceiling value v. Every lantern in that stretch whose brightness currently exceeds v is dimmed down so that its new brightness becomes exactly v; lanterns in the stretch that are already at or below v are left completely untouched. This mimics how the festival's dimmer boxes actually work — they can only pull bright lanterns down to a ceiling, never push dim ones up.

The second kind of command also targets a contiguous stretch l to r, but instead of changing anything, it asks for the total combined brightness of every lantern in that stretch at that exact moment, which the festival's power-planning team uses to make sure the local generators are not overloaded.

Over the course of the evening, Nisha receives a long sequence of these two kinds of commands, alternating unpredictably, and after every brightness-total command she must announce the answer before the next command can be processed, since the generator team is waiting live. Because thousands of lanterns and tens of thousands of commands are expected during the festival's peak hours, and because a ceiling command might only change a handful of the brightest lanterns in a huge stretch while leaving the rest untouched, Nisha cannot afford to walk through every lantern in a stretch each time — she needs a way to apply ceiling commands and answer brightness totals that stays fast even in the worst case, where commands keep targeting the same huge stretch of lanterns over and over.

Input Format
Line 1: two integers n q.

Line 2: n integers — the initial brightness values a[1..n].

Next q lines, each one of:

1 l r v — cap every lantern in [l, r] whose brightness exceeds v down to v.
2 l r — report the sum of brightness over [l, r].
Output Format
For every command of type 2, print the requested sum on its own line, in order.

Constraints
1 ≤ n, q ≤ 200000
1 ≤ a[i], v ≤ 109
1 ≤ l ≤ r ≤ n
Applying each ceiling command by scanning every lantern in the range, or using a plain range-assignment segment tree that cannot distinguish which lanterns actually exceed the ceiling, will exceed the time limit on the hidden tests.
Sample Testcase 0
Testcase Input
6 3
10 10 10 10 10 10
2 1 6
1 1 6 5
2 1 6
Testcase Output
60
30
Explanation
All six lanterns start at 10, so the first sum query over [1,6] is 60. 


The ceiling command caps everything above 5 down to 5, so every lantern becomes 5 (since all were equal, there is no "second-highest" value to stop the operation early — the whole range collapses at once). 


The final sum over [1,6] is 6×5=30.

Sample Testcase 1
Testcase Input
5 4
7 2 5 9 3
1 1 5 6
2 1 5
1 2 4 4
2 1 5
Testcase Output
22
19
Explanation
Initial row: 7 2 5 9 3. 


The first command caps [1,5] to 6: lantern 1 (7>6) becomes 6, lantern 4 (9>6) becomes 6, the rest (2, 5, 3) are already ≤6 and stay. 


Row becomes 6 2 5 6 3, whose sum over [1,5] is 6+2+5+6+3=22. 


The next command caps [2,4] to 4: within positions 2–4 the values are 2,5,6; 2 stays, 5>4 becomes 4, 6>4 becomes 4. 


Row becomes 6 2 4 4 3, whose sum over [1,5] is 6+2+4+4+3=19.

....................

```
PROBLEM SIMPLIFIED
You are given an array of n numbers.
Example:
A = [7, 2, 5, 9, 3]
There are only TWO types of queries.
---------------------------------------------------
TYPE 1
---------------------------------------------------
Input format:
1 l r v
Meaning:
Look at every element from index l to index r.
If an element is greater than v, replace it with v.
Otherwise, leave it unchanged.
Mathematically:
A[i] = min(A[i], v)
for every i in [l, r].
Notice:
- Values can only decrease.
- No value is ever increased.
---------------------------------------------------
Example 1
---------------------------------------------------
Array:
7 2 5 9 3
Query:
1 1 5 6
Check every element.
7 > 6 → becomes 6
2 ≤ 6 → stays 2
5 ≤ 6 → stays 5
9 > 6 → becomes 6
3 ≤ 6 → stays 3
New array:
6 2 5 6 3
---------------------------------------------------
Example 2
---------------------------------------------------
Current array:
6 2 5 6 3
Query:
1 2 4 4
Only positions 2 to 4 are affected.
Values are:
2 5 6
Compare each with 4.
2 → stays 2
5 → becomes 4
6 → becomes 4
New array:
6 2 4 4 3
---------------------------------------------------
TYPE 2
---------------------------------------------------
Input format:
2 l r
Meaning:
Find the sum of all elements from index l to r.
Nothing in the array changes.
---------------------------------------------------
Example
---------------------------------------------------
Array:
6 2 5 6 3
Query:
2 1 5
Sum =
6 + 2 + 5 + 6 + 3 = 22
Output:
22
===================================================
SAMPLE TESTCASE 1
===================================================
Initial array:
7 2 5 9 3
-----------------------------------
Query 1
-----------------------------------
1 1 5 6
Cap every value at 6.
7 → 6
2 → 2
5 → 5
9 → 6
3 → 3
Array becomes:
6 2 5 6 3
-----------------------------------
Query 2
-----------------------------------
2 1 5
Sum:
6 + 2 + 5 + 6 + 3 = 22
Output:
22
-----------------------------------
Query 3
-----------------------------------
1 2 4 4
Only indices 2 to 4.
Current values:
2 5 6
Apply cap 4.
2 → 2
5 → 4
6 → 4
Array becomes:
6 2 4 4 3
-----------------------------------
Query 4
-----------------------------------
2 1 5
Sum:
6 + 2 + 4 + 4 + 3 = 19
Output:
19
===================================================
SAMPLE TESTCASE 0
===================================================
Initial array:
10 10 10 10 10 10
-----------------------------------
Query 1
-----------------------------------
2 1 6
Sum:
10 + 10 + 10 + 10 + 10 + 10 = 60
Output:
60
-----------------------------------
Query 2
-----------------------------------
1 1 6 5
Cap every value at 5.
10 → 5
10 → 5
10 → 5
10 → 5
10 → 5
10 → 5
Array becomes:
5 5 5 5 5 5
-----------------------------------
Query 3
-----------------------------------
2 1 6
Sum:
5 + 5 + 5 + 5 + 5 + 5 = 30
Output:
30
===================================================
IMPORTANT OBSERVATION
===================================================
Operation 1 does NOT replace every value with v.
It ONLY changes values that are greater than v.
Example:
Array:
3 8 2 10 5
Query:
1 1 5 6
Result:
3 6 2 6 5
NOT
6 6 6 6 6
because values already smaller than 6 remain unchanged.
===================================================
WHY THIS PROBLEM IS HARD
===================================================
The operations themselves are very easy.
The difficulty comes from the constraints:
1 ≤ n, q ≤ 200000
If every Type 1 query scans every element in its range, it can take O(n).
In the worst case:
200000 queries × 200000 elements = 40,000,000,000 operations
which is far too slow.
Therefore, a normal array solution or ordinary lazy segment tree is not enough.
The intended solution uses a special data structure called "Segment Tree Beats", which can efficiently handle:
1. Range min-update (A[i] = min(A[i], v))
2. Range sum queries
```
...................
```text
CODE IDEA
Store the array and process each query directly.

--------------------------------------------------
TYPE 1 : 1 l r v
--------------------------------------------------
For every element from index l to r:
a[i] = min(a[i], v)

If a[i] > v, it becomes v.
Otherwise, it remains unchanged.

Time Complexity:
O(r - l + 1)

Worst Case:
O(n)

--------------------------------------------------
TYPE 2 : 2 l r
--------------------------------------------------
Traverse from l to r.
Add every element to the sum.
Print the sum.

Time Complexity:
O(r - l + 1)

Worst Case:
O(n)

--------------------------------------------------
OVERALL TIME COMPLEXITY
--------------------------------------------------
If there are q queries:

Worst Case:
O(n × q)

Given:
n = 200000
q = 200000

Worst Case Operations:
200000 × 200000
= 40,000,000,000 (40 Billion)

Normally, this would give TLE if worst-case tests are used.

--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------
Only one array is stored.

Space Complexity:
O(n)

--------------------------------------------------
WHEN TO USE THIS APPROACH
--------------------------------------------------
Use this approach when:

✔ n is small (around 10^3 or 10^4)
✔ q is small (around 10^3 or 10^4)
✔ Total operations (n × q) are manageable (around 10^7 to 10^8)
✔ No advanced data structure is required.

--------------------------------------------------
WHEN NOT TO USE
--------------------------------------------------
Do NOT use it when:

✘ n and q are both very large (like 2×10^5)
✘ Worst-case range updates/queries are frequent
✘ The problem expects Segment Tree, Lazy Propagation,
  Fenwick Tree, or Segment Tree Beats.

--------------------------------------------------
RULE OF THUMB
--------------------------------------------------
n ≤ 10^3                    → Brute Force
n ≤ 10^5 (few queries)      → Brute Force may work
n,q ≤ 2×10^5                → Segment Tree / BIT / Advanced DS
n,q ≤ 10^6                  → Optimized Data Structure required

--------------------------------------------------
NOTE
--------------------------------------------------
Although the problem statement suggests Segment Tree Beats,
your brute-force solution was accepted.

This means the hidden test cases are likely not strict enough
to force the worst-case O(n × q) behavior, so the simple
solution passes successfully.
```
>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
