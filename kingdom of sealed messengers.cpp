#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph;

vector<int> disc;      // Discovery time
vector<int> low;       // Lowest reachable discovery time
vector<int> sccId;     // Which SCC each node belongs to

vector<bool> inStack;
stack<int> st;

int timer = 0;
int sccCount = 0;

void tarjanDFS(int node)
{
    disc[node] = low[node] = ++timer;

    st.push(node);
    inStack[node] = true;

    for (int next : graph[node])
    {
        // If not visited
        if (disc[next] == 0)
        {
            tarjanDFS(next);

            low[node] = min(low[node], low[next]);
        }
        // Back edge
        else if (inStack[next])
        {
            low[node] = min(low[node], disc[next]);
        }
    }

    // Root of an SCC
    if (disc[node] == low[node])
    {
        while (true)
        {
            int cur = st.top();
            st.pop();

            inStack[cur] = false;
            sccId[cur] = sccCount;

            if (cur == node)
                break;
        }

        sccCount++;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    disc.assign(N + 1, 0);
    low.assign(N + 1, 0);
    sccId.assign(N + 1, -1);
    inStack.assign(N + 1, false);

    // Find SCCs
    for (int i = 1; i <= N; i++)
    {
        if (disc[i] == 0)
            tarjanDFS(i);
    }

    // Calculate indegree of each SCC
    vector<int> indegree(sccCount, 0);

    for (int u = 1; u <= N; u++)
    {
        for (int v : graph[u])
        {
            if (sccId[u] != sccId[v])
            {
                indegree[sccId[v]]++;
            }
        }
    }

    // Count SCCs with indegree 0
    int answer = 0;

    for (int i = 0; i < sccCount; i++)
    {
        if (indegree[i] == 0)
            answer++;
    }

    cout << answer << endl;

    return 0;
}
/*
disc[node]	When the node was first visited (1,2,3...)
low[node]	Smallest discovery time reachable from this node
stack	Stores nodes of the current DFS path
inStack[node]	Whether the node is currently in the stack
sccId[node]	Which SCC the node belongs to

Dry Run of Tarjan's Algorithm

Input

5 5
1 2
2 3
3 1
4 5
4 5

Graph

1 → 2 → 3
↑       ↓
└───────┘

4 → 5

----------------------------------------------------
Initially

timer = 0
stack = []

disc[] = 0
low[] = 0
sccId[] = -1

----------------------------------------------------
Start DFS from node 1

tarjanDFS(1)

timer = 1

disc[1] = 1
low[1] = 1

stack = [1]

----------------------------------------------------
Visit node 2

timer = 2

disc[2] = 2
low[2] = 2

stack = [1,2]

----------------------------------------------------
Visit node 3

timer = 3

disc[3] = 3
low[3] = 3

stack = [1,2,3]

----------------------------------------------------
3 has an edge to 1

1 is already in the stack.

So

low[3] = min(low[3], disc[1])

low[3] = min(3,1)

low[3] = 1

----------------------------------------------------
Return to node 2

Update

low[2] = min(low[2], low[3])

low[2] = min(2,1)

low[2] = 1

----------------------------------------------------
Return to node 1

Update

low[1] = min(low[1], low[2])

low[1] = min(1,1)

low[1] = 1

----------------------------------------------------
Now check

disc[1] == low[1]

1 == 1

YES

This means node 1 is the ROOT of an SCC.

Pop stack until 1 appears.

Pop 3

stack = [1,2]

sccId[3] = 0

--------------------

Pop 2

stack = [1]

sccId[2] = 0

--------------------

Pop 1

stack = []

sccId[1] = 0

First SCC

{1,2,3}

sccCount = 1

----------------------------------------------------
Continue

Node 2 already visited

Node 3 already visited

----------------------------------------------------
Visit node 4

timer = 4

disc[4] = 4
low[4] = 4

stack = [4]

----------------------------------------------------
Visit node 5

timer = 5

disc[5] = 5
low[5] = 5

stack = [4,5]

Node 5 has no outgoing edge.

Check

disc[5] == low[5]

5 == 5

YES

Pop 5

stack = [4]

sccId[5] = 1

Second SCC

{5}

sccCount = 2

----------------------------------------------------
Return to node 4

Update

low[4] = min(4,5)

low[4] = 4

The second edge 4→5 is ignored because
5 is no longer in the stack.

Now

disc[4] == low[4]

4 == 4

YES

Pop 4

stack = []

sccId[4] = 2

Third SCC

{4}

sccCount = 3

----------------------------------------------------
Final SCCs

SCC 0 = {1,2,3}

SCC 1 = {5}

SCC 2 = {4}

----------------------------------------------------
Calculate SCC indegree

Original edges

1 → 2
Same SCC
Ignore

2 → 3
Same SCC
Ignore

3 → 1
Same SCC
Ignore

4 → 5

SCC2 → SCC1

indegree[SCC1]++

Second edge

4 → 5

Again

indegree[SCC1]++

Final indegree

SCC0 = 0
SCC1 = 2
SCC2 = 0

----------------------------------------------------
Count SCCs having indegree = 0

SCC0 → Yes

SCC1 → No

SCC2 → Yes

Answer = 2

====================================================

Main Idea to Remember

disc[node]
= When the node was first discovered.

low[node]
= The earliest discovered node that can still be reached from this node (using DFS tree edges and back edges).

Stack
= Stores only the nodes of the current DFS path that haven't yet been assigned to an SCC.

Whenever

disc[node] == low[node]

that node is the starting (root) node of an SCC.

Pop nodes from the stack until you pop that node.
Those popped nodes form exactly one SCC.

.................................
```text id="n6k9a"
1. Why do we start from node 1 instead of node 0?
The problem says:
1 ≤ U, V ≤ N
So nodes are numbered:
1, 2, 3, ..., N
There is no node 0.
That is why we create:
graph.resize(N + 1);
This creates:
0 1 2 3 ... N
Index 0 is unused.
If the problem had nodes:
0, 1, 2, ..., N-1
then we would use:
for(int i = 0; i < N; i++)
--------------------------------------------------
2. Why use vector<vector<int>> graph?
Because every node can have multiple neighbours.
Example:
1 → 2
1 → 3
1 → 5
2 → 4
Node 1 has three outgoing edges.
So we store:
graph[1] = {2,3,5}
graph[2] = {4}
graph[3] = {}
graph[4] = {}
graph[5] = {}
vector<int> stores neighbours of one node.
vector<vector<int>> stores neighbours of all nodes.
This is called an adjacency list.
--------------------------------------------------
3. When does this line execute?
low[node] = min(low[node], low[next]);
This executes AFTER the recursive DFS call returns.
Example:
1 → 2 → 3
↑       ↓
└───────┘
DFS(1)
    DFS(2)
        DFS(3)
At node 3:
3 has an edge to 1.
So:
low[3] = min(low[3], disc[1])
low[3] = min(3,1)
low[3] = 1
Now DFS(3) finishes and returns.
Control comes back to DFS(2).
Now:
low[2] = min(low[2], low[3])
low[2] = min(2,1)
low[2] = 1
DFS(2) finishes.
Control comes back to DFS(1).
Now:
low[1] = min(low[1], low[2])
low[1] = min(1,1)
low[1] = 1
--------------------------------------------------
4. Why after recursion and not before?
Because low[next] is not calculated before DFS(next).
Example:
DFS(1)
    DFS(2)
        DFS(3)
First solve node 3.
Then we know:
low[3]
After that node 2 can update:
low[2] = min(low[2], low[3])
After node 2 finishes:
node 1 can update:
low[1] = min(low[1], low[2])
So low values move upward when recursion returns.
--------------------------------------------------
5. Recursion stack view:
DFS(1)
Stack:
1
DFS(2)
Stack:
1
2
DFS(3)
Stack:
1
2
3
Node 3 finishes.
Return to node 2.
Update low[2].
Node 2 finishes.
Return to node 1.
Update low[1].
--------------------------------------------------
6. Meaning of variables:
disc[node]
= Time when the node was first visited.
Example:
First visited node:
disc = 1
Second visited node:
disc = 2
low[node]
= Smallest discovery time node reachable from this node.
It tells whether this node can reach an earlier node.
--------------------------------------------------
7. Final pattern:
for(next : graph[node])
{
    if(disc[next] == 0)
    {
        DFS(next);
        low[node] = min(low[node], low[next]);
    }
    else if(inStack[next])
    {
        low[node] = min(low[node], disc[next]);
    }
}
First:
Visit child.
Second:
Calculate child's low value.
Third:
Use child's low value to update parent.
--------------------------------------------------
Simple intuition:
disc[node] is known when we enter a node.
low[node] is known after exploring all children.
DISC goes downward during DFS.
LOW comes upward during DFS return.
```

```text id="y4p7z"
Time Complexity (TC):

O(N + M)

Why?

Tarjan's algorithm performs one DFS traversal.

Every node is visited exactly once:
N nodes → O(N)

Every edge is checked exactly once:
M edges → O(M)

So total:

O(N) + O(M) = O(N + M)

--------------------------------------------------

Space Complexity (SC):

O(N + M)

Why?

1. Graph storage:

vector<vector<int>> graph

Stores all edges.

M edges are stored.

Space = O(M)

2. Arrays:

disc[]
low[]
sccId[]
inStack[]

Each has size N.

Space = O(N)

3. Recursion stack:

DFS recursion can go as deep as N nodes.

Space = O(N)

4. Stack used for Tarjan:

The stack can contain all N nodes in the worst case.

Space = O(N)

Total:

O(M) + O(N) = O(N + M)

--------------------------------------------------

For the given constraints:

N = 2 × 10^5
M = 3 × 10^5

Tarjan works efficiently because:

Time:
O(2×10^5 + 3×10^5)
= O(5×10^5)

Space:
O(2×10^5 + 3×10^5)
= O(5×10^5)

So it easily fits in typical OA limits.
```

*/