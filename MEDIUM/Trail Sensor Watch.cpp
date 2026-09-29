#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int v[n], s[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        cin >> s[i];

    map<int, int> freq;
    multiset<int> values;

    // First window
    for (int i = 0; i < k; i++) {
        freq[s[i]]++;
        values.insert(v[i]);
    }

    for (int i = k; i <= n; i++) {

        int distinct = freq.size();

        if (2 * distinct >= k)
            cout << *values.rbegin();
        else
            cout << -1;

        if (i < n)
            cout << " ";

        // Remove the element going out
        freq[s[i - k]]--;
        if (freq[s[i - k]] == 0)
            freq.erase(s[i - k]);

        values.erase(values.find(v[i - k]));

        // Add the new element
        freq[s[i]]++;
        values.insert(v[i]);
    }

    return 0;
}

/*
TC & SC
Time Complexity: O(n log k)
Space Complexity: O(k)
*/