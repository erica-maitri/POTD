<<<<<<< HEAD
/*Input:
5
10 2 8 3 7

-----------------------------------------
Read n
n = 5

Read energy array
a = [10, 2, 8, 3, 7]

Create dp array
dp = [INF, INF, INF, INF, INF]

dp[0] = 0

dp = [0, INF, INF, INF, INF]

=========================================
Outer Loop: i = 1 (Tower 2)

j = 0

cost = dp[0] + |a[1]-a[0]|*(1-0)
     = 0 + |2-10|*1
     = 8

8 < INF  → Yes

dp[1] = 8

dp = [0, 8, INF, INF, INF]

=========================================
Outer Loop: i = 2 (Tower 3)

j = 0

cost = dp[0] + |8-10|*(2-0)
     = 0 + 2*2
     = 4

4 < INF → Yes

dp[2] = 4

dp = [0, 8, 4, INF, INF]

-------------------------

j = 1

cost = dp[1] + |8-2|*(2-1)
     = 8 + 6*1
     = 14

14 < 4 ? No

dp remains

dp = [0, 8, 4, INF, INF]

=========================================
Outer Loop: i = 3 (Tower 4)

j = 0

cost = dp[0] + |3-10|*(3-0)
     = 0 + 7*3
     = 21

dp[3] = 21

dp = [0, 8, 4, 21, INF]

-------------------------

j = 1

cost = dp[1] + |3-2|*(3-1)
     = 8 + 1*2
     = 10

10 < 21 → Yes

dp[3] = 10

dp = [0, 8, 4, 10, INF]

-------------------------

j = 2

cost = dp[2] + |3-8|*(3-2)
     = 4 + 5*1
     = 9

9 < 10 → Yes

dp[3] = 9

dp = [0, 8, 4, 9, INF]

=========================================
Outer Loop: i = 4 (Tower 5)

j = 0

cost = dp[0] + |7-10|*(4-0)
     = 0 + 3*4
     = 12

dp[4] = 12

dp = [0, 8, 4, 9, 12]

-------------------------

j = 1

cost = dp[1] + |7-2|*(4-1)
     = 8 + 5*3
     = 23

23 < 12 ? No

dp = [0, 8, 4, 9, 12]

-------------------------

j = 2

cost = dp[2] + |7-8|*(4-2)
     = 4 + 1*2
     = 6

6 < 12 → Yes

dp[4] = 6

dp = [0, 8, 4, 9, 6]

-------------------------

j = 3

cost = dp[3] + |7-3|*(4-3)
     = 9 + 4*1
     = 13

13 < 6 ? No

dp = [0, 8, 4, 9, 6]

=========================================

Final Answer

dp[n-1] = dp[4] = 6

Output:
6*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int n;
   cin >> n;

   vector < int > e;
   for(int i = 0; i< n;i++){
   // cin >> e.push_back[i]; wrong as this is function not array.
   int x ;
   cin >> x;
   e.push_back(x);
   }

   //dp[i] stores the minimum cost to reach tower i
   vector<long long >dp(n,1e18);
   dp[0]=0;

   for(int i =1 ; i< n;i++){
    for(int j = 0; j< i;j++){
       long long cost = dp[j] + 1LL * abs(e[i] - e[j]) * (i-j); //as i>j

       if (cost < dp[i]){
        dp[i] = cost;
       }
    }
   }
    cout << dp[n-1];
   
    return 0;
}
/*i loop runs about n times.
Inner loop:
for(int j = 0; j < i; j++)

runs
1 time
2 times
3 times
...
n−1 times

Total iterations:
1+2+3+⋯+(n−1)=
2
n(n−1)
So,

Time Complexity: O(N²)
Space Complexity (SC)
Energy vector → O(N)
DP vector → O(N)
Total:
Space Complexity: O(N)

Short summary
energy → int is enough because values are only up to 100000.
dp → must be long long because it stores total costs.
1e18 → used as infinity, so dp must be able to store it.
1LL → makes multiplication happen in long long to prevent overflow.

Now expression becomes:

1LL * 2 * (2 - 0)
Step 2: What is 1LL doing?
1LL * 2
is:(long long)1 * (int)2

C++ converts 2 into long long.
So:
1LL * 2 = 2LL
Now the expression is:
2LL * 2
Step 3: Multiply distance
2LL * 2
= 4LL
So jump cost is:4
.................
Why not BFS?
BFS works when every edge has equal weight.
BFS chooses the direct path 1 → 3 because it has fewer edges, but its cost is 10, whereas 1 → 2 → 3 costs only 2.
Since our jump costs are different, BFS is not applicable.

Why not DFS?
DFS explores one path completely before trying others.
DFS may visit
1 → 2 → 4
first, but a cheaper path might be
1 → 3 → 4
To guarantee the minimum, DFS would need to explore all possible paths.
The number of possible paths is exponential (roughly 2
N−2), so it is far too slow.

Can we use Dijkstra?
Yes.
Think of each tower as a graph node.
Edge weight:
|a[i] - a[j]| × (j - i)
Number of edges:

1 -> N-1 edges
2 -> N-2 edges
3 -> N-3 edges
...

Total edges:
E=N(N−1)/2
	=O(N^2)


Dijkstra complexity:

O(ElogV)=O(N^2logN)

For N=1000:

DP: O(N^2)
Dijkstra: O(N^2logN)

So DP is actually faster and much simpler.

Best algorithm for this problem
✅ Algorithm: Dynamic Programming
✅ Data Structure: Array (vector<long long>)

Recurrence:

dp[i] = minimum cost to reach tower i

dp[i] = min(dp[j] + abs(a[i]-a[j])*(i-j))
        for all j < i
Interview perspective

If asked, "Can this be solved using Dijkstra?"

=======
/*Input:
5
10 2 8 3 7

-----------------------------------------
Read n
n = 5

Read energy array
a = [10, 2, 8, 3, 7]

Create dp array
dp = [INF, INF, INF, INF, INF]

dp[0] = 0

dp = [0, INF, INF, INF, INF]

=========================================
Outer Loop: i = 1 (Tower 2)

j = 0

cost = dp[0] + |a[1]-a[0]|*(1-0)
     = 0 + |2-10|*1
     = 8

8 < INF  → Yes

dp[1] = 8

dp = [0, 8, INF, INF, INF]

=========================================
Outer Loop: i = 2 (Tower 3)

j = 0

cost = dp[0] + |8-10|*(2-0)
     = 0 + 2*2
     = 4

4 < INF → Yes

dp[2] = 4

dp = [0, 8, 4, INF, INF]

-------------------------

j = 1

cost = dp[1] + |8-2|*(2-1)
     = 8 + 6*1
     = 14

14 < 4 ? No

dp remains

dp = [0, 8, 4, INF, INF]

=========================================
Outer Loop: i = 3 (Tower 4)

j = 0

cost = dp[0] + |3-10|*(3-0)
     = 0 + 7*3
     = 21

dp[3] = 21

dp = [0, 8, 4, 21, INF]

-------------------------

j = 1

cost = dp[1] + |3-2|*(3-1)
     = 8 + 1*2
     = 10

10 < 21 → Yes

dp[3] = 10

dp = [0, 8, 4, 10, INF]

-------------------------

j = 2

cost = dp[2] + |3-8|*(3-2)
     = 4 + 5*1
     = 9

9 < 10 → Yes

dp[3] = 9

dp = [0, 8, 4, 9, INF]

=========================================
Outer Loop: i = 4 (Tower 5)

j = 0

cost = dp[0] + |7-10|*(4-0)
     = 0 + 3*4
     = 12

dp[4] = 12

dp = [0, 8, 4, 9, 12]

-------------------------

j = 1

cost = dp[1] + |7-2|*(4-1)
     = 8 + 5*3
     = 23

23 < 12 ? No

dp = [0, 8, 4, 9, 12]

-------------------------

j = 2

cost = dp[2] + |7-8|*(4-2)
     = 4 + 1*2
     = 6

6 < 12 → Yes

dp[4] = 6

dp = [0, 8, 4, 9, 6]

-------------------------

j = 3

cost = dp[3] + |7-3|*(4-3)
     = 9 + 4*1
     = 13

13 < 6 ? No

dp = [0, 8, 4, 9, 6]

=========================================

Final Answer

dp[n-1] = dp[4] = 6

Output:
6*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int n;
   cin >> n;

   vector < int > e;
   for(int i = 0; i< n;i++){
   // cin >> e.push_back[i]; wrong as this is function not array.
   int x ;
   cin >> x;
   e.push_back(x);
   }

   //dp[i] stores the minimum cost to reach tower i
   vector<long long >dp(n,1e18);
   dp[0]=0;

   for(int i =1 ; i< n;i++){
    for(int j = 0; j< i;j++){
       long long cost = dp[j] + 1LL * abs(e[i] - e[j]) * (i-j); //as i>j

       if (cost < dp[i]){
        dp[i] = cost;
       }
    }
   }
    cout << dp[n-1];
   
    return 0;
}
/*i loop runs about n times.
Inner loop:
for(int j = 0; j < i; j++)

runs
1 time
2 times
3 times
...
n−1 times

Total iterations:
1+2+3+⋯+(n−1)=
2
n(n−1)
So,

Time Complexity: O(N²)
Space Complexity (SC)
Energy vector → O(N)
DP vector → O(N)
Total:
Space Complexity: O(N)

Short summary
energy → int is enough because values are only up to 100000.
dp → must be long long because it stores total costs.
1e18 → used as infinity, so dp must be able to store it.
1LL → makes multiplication happen in long long to prevent overflow.

Now expression becomes:

1LL * 2 * (2 - 0)
Step 2: What is 1LL doing?
1LL * 2
is:(long long)1 * (int)2

C++ converts 2 into long long.
So:
1LL * 2 = 2LL
Now the expression is:
2LL * 2
Step 3: Multiply distance
2LL * 2
= 4LL
So jump cost is:4
.................
Why not BFS?
BFS works when every edge has equal weight.
BFS chooses the direct path 1 → 3 because it has fewer edges, but its cost is 10, whereas 1 → 2 → 3 costs only 2.
Since our jump costs are different, BFS is not applicable.

Why not DFS?
DFS explores one path completely before trying others.
DFS may visit
1 → 2 → 4
first, but a cheaper path might be
1 → 3 → 4
To guarantee the minimum, DFS would need to explore all possible paths.
The number of possible paths is exponential (roughly 2
N−2), so it is far too slow.

Can we use Dijkstra?
Yes.
Think of each tower as a graph node.
Edge weight:
|a[i] - a[j]| × (j - i)
Number of edges:

1 -> N-1 edges
2 -> N-2 edges
3 -> N-3 edges
...

Total edges:
E=N(N−1)/2
	=O(N^2)


Dijkstra complexity:

O(ElogV)=O(N^2logN)

For N=1000:

DP: O(N^2)
Dijkstra: O(N^2logN)

So DP is actually faster and much simpler.

Best algorithm for this problem
✅ Algorithm: Dynamic Programming
✅ Data Structure: Array (vector<long long>)

Recurrence:

dp[i] = minimum cost to reach tower i

dp[i] = min(dp[j] + abs(a[i]-a[j])*(i-j))
        for all j < i
Interview perspective

If asked, "Can this be solved using Dijkstra?"

>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
Yes. We can model each tower as a node and every valid jump as a weighted edge. However, the graph has O(N^2) edges, so Dijkstra runs in O(N^2logN). Since the graph is a DAG and the transition naturally depends on previous states, a Dynamic Programming solution with O(N^2) time and O(N) space is simpler and more efficient.*/