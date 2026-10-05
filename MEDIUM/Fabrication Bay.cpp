#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Order {
    long long profit;
    long long deadline;
};

bool compare(Order a, Order b) {
    return a.profit > b.profit;
}

int findSlot(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;

    return parent[x] = findSlot(parent[x], parent);
}

int main() {
    int n;
    cin >> n;

    vector<Order> orders(n);

    for (int i = 0; i < n; i++) {
        cin >> orders[i].profit >> orders[i].deadline;

        // We never need more than n slots
        if (orders[i].deadline > n)
            orders[i].deadline = n;
    }

    // Highest profit first
    sort(orders.begin(), orders.end(), compare);

    // parent[i] tells the latest available slot
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    long long totalProfit = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {

        int slot = findSlot(orders[i].deadline, parent);

        // Slot 0 means no slot is available
        if (slot > 0) {
            totalProfit += orders[i].profit;
            count++;

            // Mark this slot as occupied
            parent[slot] = findSlot(slot - 1, parent);
        }
    }

    cout << totalProfit << " " << count << endl;

    return 0;
}

/*
Steps — What we did
Took each order as profit + deadline.
Sorted all orders by profit in decreasing order.
Limited every deadline to at most n, because only n orders exist.
Used DSU to find the latest available slot before the deadline.
If a free slot exists, accepted the order and added its profit.
Marked that slot as occupied using DSU.
Printed maximum profit and number of accepted orders.
Time Complexity

O(n log n)

Sorting: O(n log n)
DSU operations: almost O(n)
Overall: O(n log n)
Space Complexity

O(n)

Orders array: O(n)
DSU parent array: O(n)
*/