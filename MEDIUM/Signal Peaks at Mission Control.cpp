#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[200000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> dq;

    for (int i = 0; i < n; i++) {

        // Remove elements that are outside the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }

        // Add current element
        dq.push_back(i);

        // Window is ready after k elements
        if (i >= k - 1) {
            cout << a[dq.front()] << " ";
        }
    }

    return 0;
}

/*
For each new element:

Remove elements that are outside the window.
Remove elements from the back that are smaller than the current element.
Add the current index.
The dq.front() stores the index of the max element 

Input:
n = 5, k = 2
a = [-3, 5, -1, -4, 2]

Initially:
dq = empty

i = 0, a[i] = -3
    Add index 0
    dq = [0]
    Window not complete yet

i = 1, a[i] = 5
    5 is bigger than a[0] = -3
    Remove index 0
    Add index 1
    dq = [1]

    Window = [-3, 5]
    Maximum = a[1] = 5
    Output: 5


i = 2, a[i] = -1
    Remove outside elements:
        index 1 is still inside

    -1 is smaller than 5, so don't remove 5
    Add index 2
    dq = [1, 2]

    Window = [5, -1]
    Maximum = a[1] = 5
    Output: 5


i = 3, a[i] = -4
    Index 1 is outside the window [2, 3]
    Remove index 1

    -4 is smaller than -1
    Add index 3
    dq = [2, 3]

    Window = [-1, -4]
    Maximum = a[2] = -1
    Output: -1


i = 4, a[i] = 2
    Index 2 is still inside

    2 is bigger than -4
    Remove index 3
    2 is also bigger than -1
    Remove index 2

    Add index 4
    dq = [4]

    Window = [-4, 2]
    Maximum = a[4] = 2
    Output: 2


Final Output:
5 5 -1 2

Time Complexity: O(n)
Space Complexity: O(k)
*/