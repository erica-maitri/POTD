/*
Correct Approach
Store each lighthouse as a pair (deadline, repairTime).
Sort all lighthouses by deadline.
Traverse them in sorted order.
Keep adding the repair time to the total time and push it into a max heap.
If the total time exceeds the current deadline, remove the largest repair time from the heap (because removing the longest job gives the best chance of fitting more jobs).
At the end, the heap size is the maximum number of repairs completed on time.
Time Complexity
Sorting: O(N log N)
Heap operations: O(N log N)
Works for N = 2 × 10⁵.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vecator<pair<int, int>> jobs; // {deadline, repairTime}

    for (int i = 0; i < N; i++) {
        int T, D;
        cin >> T >> D;
        jobs.push_back({D, T});
    }

    // Sort by deadline
    sort(jobs.begin(), jobs.end());

    priority_queue<int> pq; // Max Heap
    long long totalTime = 0;

    for (auto job : jobs) {
        int deadline = job.first;
        int repairTime = job.second;

        totalTime += repairTime;
        pq.push(repairTime);

        if (totalTime > deadline) {
            totalTime -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << endl;

    return 0;
}

/*
push()   -> O(log N)
top()    -> O(1)
pop()    -> O(log N)
*/