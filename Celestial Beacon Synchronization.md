Problem Statement
Far beyond Earth's atmosphere, Commander Aarav oversees a massive orbital defense network known as the Celestial Ring. The ring consists of N energy beacons arranged in a fixed sequence around the station. Each beacon emits a signal represented by an integer frequency code.

Throughout every orbital cycle, the control room receives thousands of diagnostic requests from engineers. Each request focuses on a consecutive section of the beacon ring to inspect its Synchronization Energy.

Unlike ordinary inspections, the engineers do not evaluate individual beacons. Instead, every distinct frequency code contributes according to the square of the number of times it appears inside the inspected section. Higher repetition indicates stronger resonance among identical beacons, increasing the total synchronization energy.

For a selected section:

Suppose a frequency code appears f times.
Its contribution becomes
f^2

The Synchronization Energy of the section is the sum of these contributions over every distinct frequency present in that section.

Since the beacon arrangement never changes during an orbital cycle, the engineers may issue hundreds of thousands of diagnostic requests. Recalculating the entire frequency distribution for every request would consume valuable processing time, delaying critical monitoring operations.

Commander Aarav needs a program capable of answering every diagnostic request efficiently while preserving the exact Synchronization Energy for each inspected section.

Every inspection is independent of the others, even if multiple requests overlap.

Input Format
The first line contains two integers N and Q.
The second line contains N integers representing beacon frequency codes.
Each of the next Q lines contains two integers L and R, describing one inspection.
Output Format
Print the Synchronization Energy for every inspection on a separate line.

Constraints
1 ≤ N,Q ≤ 2 × 10^5
1 ≤ Frequency Code ≤ 10^6
1 ≤ L ≤ R ≤ N
Answer fits in signed 64-bit integer.
Sample Testcase 0
Testcase Input
10 2
5 5 3 8 3 8 5 8 8 2
1 10
4 9
Testcase Output
30
18
Explanation

Query 1

Entire Beacon Ring: 5 5 3 8 3 8 5 8 8 2

Frequency

5 → 3

3 → 2

8 → 4

2 → 1

Contribution

3² = 9

2² = 4

4² = 16

1² = 1

Total: 9 + 4 + 16 + 1 = 30

Query 2

Range: 8 3 8 5 8 8

Frequency

8 → 4

3 → 1

5 → 1

Contribution

4² = 16

1² = 1

1² = 1

Total: 16 + 1 + 1 = 18

Sample Testcase 1
Testcase Input
8 3
4 7 4 2 7 7 9 4
2 8
1 5
3 7
Testcase Output
15
9
7
Explanation

Query 1

Range: 7 4 2 7 7 9 4

Frequency

2 → 1

4 → 2

7 → 3

9 → 1

Contribution

1² = 1

2² = 4

3² = 9

1² = 1

Total: 1 + 4 + 9 + 1 = 15

Query 2

Range: 4 7 4 2 7

Frequency

4 → 2

7 → 2

2 → 1

Contribution

2² = 4

2² = 4

1² = 1

Total: 4 + 4 + 1 = 9

Query 3

Range: 4 2 7 7 9

Frequency

4 → 1

2 → 1

7 → 2

9 → 1

Contribution

1² = 1

1² = 1

2² = 4

1² = 1

Total: 1 + 1 + 4 + 1 = 7
/*You have an array.

Example:
5 5 3 8 3 8 5 8 8 2

There are many queries.

Each query asks:
"Look only at elements from index L to R."

For that range:
1. Count how many times every number appears.
2. Square each frequency.
3. Add all the squares.

----------------------------------------
Example 1
----------------------------------------

Array:
5 5 3 8 3 8 5 8 8 2

Query:
1 10

Frequency Table:

Number    Count    Contribution
5         3        3² = 9
3         2        2² = 4
8         4        4² = 16
2         1        1² = 1

Answer:
9 + 4 + 16 + 1 = 30

----------------------------------------
Example 2
----------------------------------------

Query:
4 9

Elements:
8 3 8 5 8 8

Frequency:

8 -> 4
3 -> 1
5 -> 1

Contribution:

4² + 1² + 1²
= 16 + 1 + 1
= 18

----------------------------------------
Why can't we solve each query normally?
----------------------------------------

For every query:

1. Count frequencies.
2. Calculate the answer.

This takes O(N) time.

Given:
N = 2 × 10^5
Q = 2 × 10^5

Total Time:
O(N × Q)
= 4 × 10^10 operations

This is too slow.

----------------------------------------
Idea of Mo's Algorithm
----------------------------------------

Instead of solving every query from scratch,
we move the current range little by little.

Suppose the current range is:

[2, 6]

The next query is:

[3, 7]

Instead of recounting everything,

we simply:
- Remove index 2
- Add index 7

Only 2 operations are needed.

This makes the algorithm much faster.

Time Complexity:
O((N + Q) × √N)

----------------------------------------
Important Formula
----------------------------------------

Suppose a number appears f times.

Current contribution:
f²

When adding one more occurrence:

New frequency = f + 1

Change in contribution:

(f + 1)² - f²
= 2f + 1

When removing one occurrence:

f² - (f - 1)²
= 2f - 1

Therefore, each add/remove operation updates the answer in O(1) time.*/
