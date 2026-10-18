#include <iostream>
#include <deque>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[200005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> dq;
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        // Remove elements outside the window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Process each complete window
        if (i >= k - 1) {
            int mx = a[dq.front()];
            cout << mx << " ";
            freq[mx]++;
        }
    }

    cout << endl;

    int dominant = 0;
    int maxCount = 0;

    for (auto p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            dominant = p.first;
        }
    }

    cout << dominant << " " << maxCount << endl;

    return 0;
}
/*
Complexity
- Time Complexity: (O(nlog n)), because of the map operations.
- Space Complexity: (O(n)), for the deque and frequency map.
*/