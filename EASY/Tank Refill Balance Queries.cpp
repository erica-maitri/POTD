#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Prefix sum array
    long long prefix[200005];

    prefix[0] = 0;

    // Read the array and create prefix sums
    for (int i = 1; i <= N; i++) {
        long long x;
        cin >> x;

        prefix[i] = prefix[i - 1] + x;
    }

    int Q;
    cin >> Q;

    // Process each query
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;

        // Sum from L to R
        long long sum = prefix[R] - prefix[L - 1];

        cout << sum << " ";

        // Check the status
        if (sum > 0) {
            cout << "SURPLUS";
        }
        else if (sum < 0) {
            cout << "DEFICIT";
        }
        else {
            cout << "BALANCED";
        }

        cout << endl;
    }

    return 0;
}