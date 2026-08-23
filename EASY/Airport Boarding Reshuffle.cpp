#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> q;
    int next = 1;

    for (int i = 0; i < m; i++) {

        char ch;
        cin >> ch;

        // Passenger arrives
        if (ch == 'A') {
            q.push_back(next);
            next++;
        }

        // Passenger gets priority
        else if (ch == 'P') {
            int x;
            cin >> x;

            // Find x in the queue
            for (int j = 0; j < q.size(); j++) {

                if (q[j] == x) {

                    // Remove x
                    q.erase(q.begin() + j);

                    // Put x at front
                    q.insert(q.begin(), x);

                    break;
                }
            }
        }

        // Passenger boards
        else if (ch == 'B') {

            if (q.empty()) {
                cout << 0 << endl;
            }
            else {
                cout << q[0] << endl;

                // Remove first passenger
                q.erase(q.begin());
            }
        }
    }

    return 0;
}