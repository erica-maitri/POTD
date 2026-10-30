/*
Store each waiting parcel as a pair:

(deadline, id)

The set automatically maintains ascending order, so:

The parcel with the earliest deadline is at begin().

If deadlines are equal, the smaller ID comes first.

Insertion, deletion, and deadline updates take 

O(logQ).

Dispatch takes 
O(logQ).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    // Stores {deadline, id}
    set<pair<long long, int>> parcels;

    // Stores the current deadline of each waiting parcel
    unordered_map<int, long long> mp;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "ARRIVE") {
            int id;
            long long deadline;
            cin >> id >> deadline;

            parcels.insert({deadline, id});
            mp[id] = deadline;
        }

        else if (op == "DELAY") {
            int id;
            long long newDeadline;
            cin >> id >> newDeadline;

            // Remove the old entry
            parcels.erase({mp[id], id});

            // Insert the updated entry
            parcels.insert({newDeadline, id});
            mp[id] = newDeadline;
        }

        else if (op == "CANCEL") {
            int id;
            cin >> id;

            parcels.erase({mp[id], id});
            mp.erase(id);
        }

        else if (op == "DISPATCH") {
            if (parcels.empty()) {
                cout << "IDLE\n";
            }
            else {
                auto it = parcels.begin();

                int id = it->second;
                cout << id << '\n';

                parcels.erase(it);
                mp.erase(id);
            }
        }
    }

    return 0;
}
