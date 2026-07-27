#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1);

    // Read dimensions
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    // dp[i][j] = minimum cost to multiply matrices i to j
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // length = number of matrices in current chain
    for (int length = 2; length <= n; length++) {

        // starting matrix
        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            dp[i][j] = 1e18; //LLONG_MAX

            // Try every possible place to split
            for (int k = i; k < j; k++) {

                long long cost =
                    dp[i][k] +                    // Left part
                    dp[k + 1][j] +                // Right part
                    1LL * p[i] * p[k + 1] * p[j + 1];   // Cost to multiply them

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;

}

/*Time Complexity:O(N³)
Because we create a 2D DP table:
N rows × N columns
= N² cells
vector<long long> p(n+1);
takes:
O(N)
extra space, but it is smaller than O(N²).
Therefore:
Total Space = O(N²)
*/

/*Matrix Chain Multiplication (Simple Explanation)

What is given?
--------------
You have N matrices.

Instead of giving each matrix directly, the input gives N+1 numbers.

For example:

10 20 30 40 30

This represents the matrices:

A = 10 × 20
B = 20 × 30
C = 30 × 40
D = 40 × 30

Since the number of columns of one matrix equals the number of rows of the next,
all matrices can be multiplied together.

------------------------------------------------------------

Cost of multiplying two matrices
--------------------------------
If

A = x × y
B = y × z

then the multiplication cost is

x × y × z

The resulting matrix will have dimensions

x × z

Note:
The cost is NOT the size of the resulting matrix.
It is the number of scalar multiplications required.

------------------------------------------------------------

Important Idea
--------------
No matter how you parenthesize the matrices, the final result is the same.
This is a property of matrix multiplication called the associative property.
It means:
(A × B) × C = A × (B × C)
The final matrix (its values) will be the same.
However, the number of calculations (cost) can be different.
However, the total multiplication cost changes depending on the order.
(AB)C  → Result = 20×40
A(BC)  → Result = 20×40

Our goal is to find the order that gives the minimum total cost.

------------------------------------------------------------

Example 1

Matrices:

A = 20 × 30
B = 30 × 10
C = 10 × 40

There are only two possible orders.

Option 1: (AB)C

Step 1:
Multiply A and B

20×30 × 30×10

Cost = 20 × 30 × 10 = 6000

Resulting matrix = 20 × 10

Step 2:
Multiply the result with C

20×10 × 10×40

Cost = 20 × 10 × 40 = 8000

Total Cost = 6000 + 8000 = 14000

------------------------------------------------------------

Option 2: A(BC)

Step 1:
Multiply B and C

30×10 × 10×40

Cost = 30 × 10 × 40 = 12000

Resulting matrix = 30 × 40

Step 2:
Multiply A with the result

20×30 × 30×40

Cost = 20 × 30 × 40 = 24000

Total Cost = 12000 + 24000 = 36000

------------------------------------------------------------

Minimum Cost = 14000

------------------------------------------------------------

Example 2

Input:

4
10 20 30 40 30

Matrices:

A = 10 × 20
B = 20 × 30
C = 30 × 40
D = 40 × 30

Possible multiplication orders include:

((AB)C)D
(A(BC))D
AB(CD)
A((BC)D)
(AB)(CD)

Each order has a different total multiplication cost.

The minimum cost among all possible orders is

30000

------------------------------------------------------------

What is the problem asking?

You DO NOT have to actually multiply the matrices.

You only need to calculate the minimum number of scalar multiplications
required by choosing the best order of multiplication.

------------------------------------------------------------

One-line Summary

Given a chain of matrices, find the best parenthesization (order of
multiplication) so that the total multiplication cost is minimum.

So in this problem, you are only allowed to change the parentheses (grouping), not the order of the matrices.

For example, if the chain is:

A × B × C × D

Valid groupings include:

((AB)C)D
(AB)(CD)
A((BC)D)
A(B(CD))

But these are not allowed:

BACD
CABD
DBCA

The order A → B → C → D must always remain the same. Only the grouping can change.*/

/*DRY RUN
DRY RUN OF MATRIX CHAIN MULTIPLICATION CODE

Input:
------
4
10 20 30 40 30


Meaning:

n = 4

Dimensions array:

p[0] = 10
p[1] = 20
p[2] = 30
p[3] = 40
p[4] = 30


Matrices:

A = p[0] x p[1] = 10 x 20
B = p[1] x p[2] = 20 x 30
C = p[2] x p[3] = 30 x 40
D = p[3] x p[4] = 40 x 30


------------------------------------------------------------
STEP 1: Create DP Table
------------------------------------------------------------

Code:

vector<vector<int>> dp(n, vector<int>(n, 0));


n = 4

Create a 4 x 4 matrix:

        0    1    2    3
    -----------------------
0 |     0    0    0    0
1 |     0    0    0    0
2 |     0    0    0    0
3 |     0    0    0    0


Meaning:

dp[i][j] = minimum cost of multiplying matrices from i to j


Initially:

dp[i][i] = 0

because multiplying one matrix requires no multiplication.


------------------------------------------------------------
STEP 2: length = 2
------------------------------------------------------------

Code:

for(length = 2; length <= n; length++)


Here:

length = 2

Means:
Calculate cost for chains containing 2 matrices.


Example:

AB
BC
CD


------------------------------------------------------------
CASE 1: i = 0
------------------------------------------------------------

Code:

for(i = 0; i <= n-length; i++)


n = 4
length = 2

Condition:

i <= 4-2

i <= 2


First:

i = 0


Calculate:

j = i + length - 1

j = 0 + 2 - 1

j = 1


We need:

dp[0][1]


Set:

dp[0][1] = INT_MAX


Now try all possible splits:

for(k = i; k < j; k++)


k starts at 0


k = 0


Cost:

dp[i][k]
+
dp[k+1][j]
+
p[i]*p[k+1]*p[j+1]


Putting values:

dp[0][0]
+
dp[1][1]
+
p[0]*p[1]*p[2]


= 0
+ 0
+ 10*20*30


= 6000


So:

dp[0][1] = min(INT_MAX,6000)

dp[0][1] = 6000


DP table:

        0      1      2      3
    ----------------------------
0 |     0    6000    0      0
1 |     0      0     0      0
2 |     0      0     0      0
3 |     0      0     0      0


Meaning:

Cost of A x B = 6000


------------------------------------------------------------
CASE 2: i = 1
------------------------------------------------------------


i = 1

j = 1 + 2 - 1

j = 2


Find:

dp[1][2]


Set:

dp[1][2] = INT_MAX


Only split:

k = 1


Cost:

dp[1][1]
+
dp[2][2]
+
p[1]*p[2]*p[3]


= 0 + 0 + 20*30*40


= 24000


Therefore:

dp[1][2] = 24000


Table:

        0      1       2      3
    -----------------------------
0 |     0    6000     0      0
1 |     0      0    24000    0
2 |     0      0      0      0
3 |     0      0      0      0


Meaning:

B x C = 24000


------------------------------------------------------------
CASE 3: i = 2
------------------------------------------------------------


j = 2 + 2 - 1

j = 3


Find:

dp[2][3]


Split:

k = 2


Cost:

dp[2][2]
+
dp[3][3]
+
p[2]*p[3]*p[4]


= 0 + 0 + 30*40*30


= 36000


dp[2][3] = 36000


Table:

        0      1       2       3
    --------------------------------
0 |     0    6000      0       0
1 |     0      0    24000      0
2 |     0      0      0     36000
3 |     0      0      0       0



------------------------------------------------------------
STEP 3: length = 3
------------------------------------------------------------

Now calculate chains of 3 matrices:

ABC
BCD


length = 3


------------------------------------------------------------
CASE 1: i = 0
------------------------------------------------------------


j = 0 + 3 - 1

j = 2


Need:

dp[0][2]


Set:

dp[0][2] = INT_MAX


Now try splits.


========================
Split 1:

k = 0

Meaning:

A | BC


Cost:

dp[0][0]
+
dp[1][2]
+
p[0]*p[1]*p[3]


= 0
+ 24000
+ 10*20*40


= 24000 + 8000


= 32000



dp[0][2] = 32000


========================
Split 2:

k = 1

Meaning:

AB | C


Cost:

dp[0][1]
+
dp[2][2]
+
p[0]*p[2]*p[3]


= 6000
+ 0
+ 10*30*40


= 6000 + 12000


= 18000



Minimum:

dp[0][2] = 18000



Table:

        0      1       2       3
    --------------------------------
0 |     0    6000   18000      0
1 |     0      0    24000      0
2 |     0      0      0     36000
3 |     0      0      0       0



------------------------------------------------------------
CASE 2: i = 1
------------------------------------------------------------


j = 1+3-1

j = 3


Need:

dp[1][3]


Splits:


========================
k = 1

B | CD


Cost:

dp[1][1]
+
dp[2][3]
+
p[1]*p[2]*p[4]


= 0
+ 36000
+ 20*30*30


= 36000 + 18000


= 54000



========================
k = 2

BC | D


Cost:

dp[1][2]
+
dp[3][3]
+
p[1]*p[3]*p[4]


= 24000
+ 0
+ 20*40*30


= 24000 + 24000


= 48000



Minimum:

dp[1][3] = 48000



Table:

        0      1       2       3
    --------------------------------
0 |     0    6000   18000      0
1 |     0      0    24000   48000
2 |     0      0      0     36000
3 |     0      0      0       0



------------------------------------------------------------
STEP 4: length = 4
------------------------------------------------------------

Now calculate the complete chain:

ABCD


i = 0

j = 3


Need:

dp[0][3]


Set:

dp[0][3] = INT_MAX


Try all splits:


============================================================
Split 1:

k = 0

A | BCD


Cost:

dp[0][0]
+
dp[1][3]
+
p[0]*p[1]*p[4]


= 0
+ 48000
+ 10*20*30


= 48000 + 6000


= 54000



============================================================
Split 2:

k = 1

AB | CD


Cost:

dp[0][1]
+
dp[2][3]
+
p[0]*p[2]*p[4]


= 6000
+ 36000
+ 10*30*30


= 6000 + 36000 + 9000


= 51000



============================================================
Split 3:

k = 2

ABC | D


Cost:

dp[0][2]
+
dp[3][3]
+
p[0]*p[3]*p[4]


= 18000
+ 0
+ 10*40*30


= 18000 + 12000


= 30000



Minimum:

dp[0][3] = 30000



Final DP Table:

        0       1        2        3
    ------------------------------------
0 |     0     6000   18000    30000
1 |     0       0    24000    48000
2 |     0       0      0      36000
3 |     0       0      0        0



------------------------------------------------------------
STEP 5: Print Answer
------------------------------------------------------------

Code:

cout << dp[0][n-1];


n = 4

dp[0][3] = 30000


Output:

30000


------------------------------------------------------------
FINAL UNDERSTANDING
------------------------------------------------------------

The DP table stores answers for smaller matrix chains first.

Length 2:
    Find cost of multiplying 2 matrices.

Length 3:
    Use length 2 answers.

Length 4:
    Use length 2 and length 3 answers.

Finally:

dp[0][n-1]

contains the minimum cost for multiplying all matrices.


For input:

4
10 20 30 40 30


Answer:

30000
..........
vector<vector<long long>>
This means:
"A vector that stores vectors of long long."
I want a vector whose elements are themselves vectors.
or
vector of rows
Example:
[
  [0,0,0,0],
  [0,0,0,0],
  [0,0,0,0],
  [0,0,0,0]

  LLONG_MAX
acts like infinity.

vector<long long>(4, 0)
creates:
[0, 0, 0, 0]
This is one row with 4 columns.
vector<vector<long long>> dp(n, vector<long long>(n,0));
means:
Create n copies of this row:
Row 1 → [0,0,0,0]
Row 2 → [0,0,0,0]
Row 3 → [0,0,0,0]
Row 4 → [0,0,0,0]
]*/