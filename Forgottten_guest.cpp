#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (auto it : mp) {
        if (it.second == 1) {
            cout << it.first;
            break;
        }
    }

    return 0;
}
/*Time: O(N)
Space: O(N)*/
//or

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        ans = ans ^ x;
    }

    cout << ans;

    return 0;
}

/*Time Complexity: O(N)
Space Complexity: O(1)*/


