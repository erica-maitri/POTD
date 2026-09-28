#include <bits/stdc++.h>
using namespace std;

struct Node {
    int p, t, id;

    bool operator<(Node x) const {
        if (p != x.p) return p < x.p;
        return t > x.t;
    }
};

int main() {
    int q;
    cin >> q;

    priority_queue<Node> pq;
    map<int, pair<int,int>> mp; // id -> {priority, time}

    int t = 0;

    while (q--) {
        string s;
        cin >> s;

        if (s == "ADD") {
            int id, p;
            cin >> id >> p;
            mp[id] = {p, ++t};
            pq.push({p, t, id});
        }

        else if (s == "UPDATE") {
            int id, p;
            cin >> id >> p;

            if (mp.count(id)) {
                mp[id].first = p;
                pq.push({p, mp[id].second, id});
            }
        }

        else if (s == "CANCEL") {
            int id;
            cin >> id;
            mp.erase(id);
        }

        else {
            while (!pq.empty()) {
                Node x = pq.top();

                if (!mp.count(x.id) ||
                    mp[x.id].first != x.p ||
                    mp[x.id].second != x.t)
                    pq.pop();
                else
                    break;
            }

            if (pq.empty())
                cout << -1 << endl;
            else {
                int id = pq.top().id;
                cout << id << endl;
                mp.erase(id);
                pq.pop();
            }
        }
    }
}

/*
TC: O(q log q)
SC: O(q)
*/