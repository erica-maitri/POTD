#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // Sort by start time
    sort(intervals.begin(), intervals.end());

    // Min-heap stores ending times
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto interval : intervals) {
        int start = interval.first;
        int end = interval.second;

        // Reuse a room if it is free
        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        // Occupy a room until 'end'
        pq.push(end);
    }

    cout << pq.size();

    return 0;
}
/*
Simple meaning of the problem:

You are given N time intervals (start time, end time).

Each interval represents one team's working time.

Rule:
- If two intervals overlap, they cannot be placed in the same room/zone.
- If one interval ends exactly when another starts (end <= start),
  they CAN use the same room.

Your task:
Find the minimum number of rooms/zones needed so that all intervals
can be scheduled without any overlaps in the same room.

Example:

Intervals:
(1,4)
(2,5)
(3,6)
(6,8)
(7,9)

From time 3 to 4, the first three intervals are all active together.
So at that moment, 3 rooms are needed.

Answer = 3.

In short:
The problem is asking for the **maximum number of intervals that are
running at the same time**, because that is exactly the minimum number
of rooms/zones required.

he simplest approach is:

Sort all intervals by their start time.
Use a min-heap to store the ending times of currently occupied rooms.
If the earliest ending room is free (end <= current start), reuse it.
Otherwise, allocate a new room.
The maximum size of the heap is the answer.

Time Complexity (TC):
- Sorting intervals: O(N log N)
- For each interval:
    - At most one pop: O(log N)
    - One push: O(log N)

Total TC = O(N log N)

Space Complexity (SC):
- Vector of intervals: O(N)
- Min-heap (in the worst case all intervals overlap): O(N)

Total SC = O(N)
*/