#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

// Global variables so that main + dfs() both can access
vector<vector<pair<int, ll>>> tree;

vector<ll> pathScore;
vector<ll> mn;
vector<ll> mx;
vector<ll> spread;


// DFS function outside main
void dfs(int node)
{
    // Initially subtree contains only this node
    mn[node] = pathScore[node];
    mx[node] = pathScore[node];


    // Visit all children
    for(auto child : tree[node])
    {
        int next = child.first;
        ll weight = child.second;


        // Calculate child's path score
        pathScore[next] = pathScore[node] + weight;


        // Solve child's subtree first
        dfs(next);


        // After child returns, update current node
        mn[node] = min(mn[node], mn[next]);

        mx[node] = max(mx[node], mx[next]);
    }


    // Final answer for this node
    spread[node] = mx[node] - mn[node];
}


int main()
{
    int N;
    cin >> N;


    // Resize global vectors
    tree.resize(N + 1);

    pathScore.resize(N + 1);
    mn.resize(N + 1);
    mx.resize(N + 1);
    spread.resize(N + 1);


    // Input edges
    // Format: parent child weight
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        ll w;

        cin >> u >> v >> w;

        tree[u].push_back({v, w});
    }


    // Root node
    pathScore[1] = 0;


    // Start DFS
    dfs(1);


    // Queries
    int Q;
    cin >> Q;


    while(Q--)
    {
        int node;
        cin >> node;

        cout << spread[node] << "\n";
    }


    return 0;
}
/*
Time Complexity (TC):

1. Building the tree:
   - We read N-1 edges.
   - Time = O(N)

2. DFS traversal:
   - Every node is visited once.
   - Every edge is processed once.
   - Time = O(N)

3. Queries:
   - Each query only prints spread[node].
   - Time per query = O(1)
   - Total queries = O(Q)

Overall Time Complexity:

O(N + Q)


--------------------------------------------------


Space Complexity (SC):

1. Tree storage:
   - Stores N-1 edges.
   - Space = O(N)

2. Arrays:
   - pathScore[]
   - mn[]
   - mx[]
   - spread[]

   Each stores N values.
   Space = O(N)

3. DFS recursion stack:
   - Worst case (tree is like a linked list):
   - Stack depth = N
   - Space = O(N)


Overall Space Complexity:

O(N)
*/
/*
You can also declare global arrays:

const int MAX = 200005;

vector<pair<int,ll>> tree[MAX];

ll pathScore[MAX];
ll mn[MAX];
ll mx[MAX];
ll spread[MAX];

Then no resize is needed.
Global declaration:
"I need this variable available everywhere"

Resize:
"Now I know how much memory this variable needs"
*/

/*
STEP 1: Start DFS from root (node 1)
- Set node's own pathScore as its initial minimum and maximum.
- Move to its children.

STEP 2: Go down to child nodes
- Calculate pathScore:
  child pathScore = parent pathScore + edge weight.
- Repeat DFS until reaching a leaf.

STEP 3: Process leaf node
- Leaf has no children.
- Its minimum and maximum are its own pathScore.
- spread = maximum - minimum = 0.
- Return to parent.

STEP 4: Update parent after child returns
- Take the child's minimum and maximum values.
- Update parent's:
  minimum = smaller(parent minimum, child minimum)
  maximum = larger(parent maximum, child maximum)

STEP 5: After all children are processed
- Parent now knows the minimum and maximum pathScores of its whole subtree.
- Calculate:
  spread = maximum - minimum

STEP 6: Continue returning upward
- Each parent gets information from all children.
- Update values until reaching the root.

STEP 7: Answer queries
- The spread of every node is already stored.
- For each query node, directly print spread[node].

dfs(1)
   ↓
dfs(2)
   ↓
dfs(4)
   ↑
update(2)
   ↓
dfs(5)
   ↑
update(2)
   ↑
update(1)
   ↓
dfs(3)
   ↓
dfs(6)
   ↑
update(3)
   ↑
update(1)



*/

/*
DRY RUN (Sample 2)

Input

6
1 2 5
1 3 -2
2 4 3
2 5 -6
3 6 4

Tree

        1
      /   \
     2     3
    / \     \
   4   5     6

--------------------------------------------------------
STEP 1 : Read the tree
--------------------------------------------------------

tree[1] = {(2,+5), (3,-2)}
tree[2] = {(4,+3), (5,-6)}
tree[3] = {(6,+4)}
tree[4] = {}
tree[5] = {}
tree[6] = {}

Initially

pathScore[] = 0
mn[] = 0
mx[] = 0
spread[] = 0

Set

pathScore[1] = 0

Now call

dfs(1)

========================================================
CALL 1 : dfs(1)
========================================================

Current node = 1

Initialize

mn[1] = pathScore[1] = 0
mx[1] = pathScore[1] = 0

Children of 1 are

2
3

Go to first child.

--------------------------------------------------------
CALL 2 : dfs(2)
--------------------------------------------------------

Before calling,

pathScore[2]
= pathScore[1] + 5
= 0 + 5
= 5

Inside dfs(2)

mn[2] = 5
mx[2] = 5

Children are

4
5

Go to first child.

--------------------------------------------------------
CALL 3 : dfs(4)
--------------------------------------------------------

Before calling,

pathScore[4]
= pathScore[2] + 3
= 5 + 3
= 8

Inside dfs(4)

mn[4] = 8
mx[4] = 8

Node 4 has no children.

Loop ends.

spread[4]

= mx[4] - mn[4]
= 8 - 8
= 0

dfs(4) finishes.

Return to dfs(2).

--------------------------------------------------------
Back to node 2
--------------------------------------------------------

Current values

mn[2] = 5
mx[2] = 5

Update using child 4

mn[2]
= min(5,8)
= 5

mx[2]
= max(5,8)
= 8

Now process next child.

--------------------------------------------------------
CALL 4 : dfs(5)
--------------------------------------------------------

Before calling,

pathScore[5]
= pathScore[2] + (-6)
= 5 - 6
= -1

Inside dfs(5)

mn[5] = -1
mx[5] = -1

No children.

spread[5]

= -1 - (-1)

= 0

dfs(5) finishes.

Return to dfs(2).

--------------------------------------------------------
Back to node 2 again
--------------------------------------------------------

Current

mn[2] = 5
mx[2] = 8

Update using child 5

mn[2]
= min(5,-1)
= -1

mx[2]
= max(8,-1)
= 8

All children finished.

Now calculate answer.

spread[2]

= 8 - (-1)

= 9

dfs(2) finishes.

Return to dfs(1).

--------------------------------------------------------
Back to node 1
--------------------------------------------------------

Current

mn[1] = 0
mx[1] = 0

Update using child 2

mn[1]
= min(0,-1)
= -1

mx[1]
= max(0,8)
= 8

Now process second child.

--------------------------------------------------------
CALL 5 : dfs(3)
--------------------------------------------------------

Before calling,

pathScore[3]

= pathScore[1] + (-2)

= -2

Inside dfs(3)

mn[3] = -2
mx[3] = -2

Only child = 6

--------------------------------------------------------
CALL 6 : dfs(6)
--------------------------------------------------------

Before calling,

pathScore[6]

= pathScore[3] + 4

= -2 + 4

= 2

Inside dfs(6)

mn[6] = 2
mx[6] = 2

No children.

spread[6]

= 2 - 2

= 0

dfs(6) finishes.

Return to dfs(3).

--------------------------------------------------------
Back to node 3
--------------------------------------------------------

Current

mn[3] = -2
mx[3] = -2

Update using child 6

mn[3]

= min(-2,2)

= -2

mx[3]

= max(-2,2)

= 2

Children finished.

spread[3]

= 2 - (-2)

= 4

dfs(3) finishes.

Return to dfs(1).

--------------------------------------------------------
Back to node 1 again
--------------------------------------------------------

Current

mn[1] = -1
mx[1] = 8

Update using child 3

mn[1]

= min(-1,-2)

= -2

mx[1]

= max(8,2)

= 8

All children are finished.

Calculate answer.

spread[1]

= 8 - (-2)

= 10

dfs(1) finishes.

========================================================
FINAL ARRAYS
========================================================

pathScore

1 -> 0
2 -> 5
3 -> -2
4 -> 8
5 -> -1
6 -> 2

mn

1 -> -2
2 -> -1
3 -> -2
4 -> 8
5 -> -1
6 -> 2

mx

1 -> 8
2 -> 8
3 -> 2
4 -> 8
5 -> -1
6 -> 2

spread

1 -> 10
2 -> 9
3 -> 4
4 -> 0
5 -> 0
6 -> 0

========================================================
Queries
========================================================

Q = 4

Query = 1  -> print spread[1] = 10
Query = 2  -> print spread[2] = 9
Query = 3  -> print spread[3] = 4
Query = 4  -> print spread[4] = 0

Output

10
9
4
0
*/
