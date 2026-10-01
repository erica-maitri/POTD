#include <iostream>
#include <map>
#include <string>
using namespace std;

int parent[210005];
long long rating[210005];
long long maximum[210005];

// Find the leader of a zone
int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

// Join two zones
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    parent[b] = a;

    if (maximum[b] > maximum[a])
        maximum[a] = maximum[b];
}

int main() {
    int n;
    cin >> n;

    map<string, int> id;

    for (int i = 1; i <= n; i++) {
        string name;
        long long value;

        cin >> name >> value;

        id[name] = i;
        parent[i] = i;
        rating[i] = value;
        maximum[i] = value;
    }

    int q;
    cin >> q;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "LINK") {
            string x, y;
            cin >> x >> y;

            unite(id[x], id[y]);
        }
        else if (operation == "BOOST") {
            string x;
            long long v;

            cin >> x >> v;

            int node = id[x];
            int root = find(node);

            rating[node] += v;

            if (rating[node] > maximum[root])
                maximum[root] = rating[node];
        }
        else if (operation == "QUERY") {
            string x;
            cin >> x;

            int root = find(id[x]);

            cout << maximum[root] << endl;
        }
    }

    return 0;
}
/*
TC
LINK: O(α(n))
BOOST: O(α(n))
QUERY: O(α(n))
Name lookup using map: O(log n)
Overall: O((n + q) log n)
SC

O(n)
*/