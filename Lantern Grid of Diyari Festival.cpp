#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n+1); //1-based indexing
     //a[0] is never used default value is 0
     //waste of memory? yes, but it's negligible.
     //If indices are 0 to n-1  → vector size = n
     //If indices are 1 to n    → vector size = n+1
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;

            for (int i = l; i <= r; i++)
                a[i] = min(a[i], 1LL * v);
        }
        else {
            int l, r;
            cin >> l >> r;

            long long sum = 0;

            for (int i = l; i <= r; i++)
                sum += a[i];

            cout << sum << "\n";
        }
    }
     return 0;
}
   
