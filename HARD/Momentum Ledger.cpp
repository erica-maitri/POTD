#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, K;
    cin >> n >> K;

    vector<int> team(n);
    vector<int> rating(n);
    vector<int> wait(n, -1);

    // Input
    for (int i = 0; i < n; i++)
    {
        cin >> team[i] >> rating[i];
    }

    // Find next higher rating of the same team
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (team[i] == team[j] && rating[j] > rating[i])
            {
                wait[i] = j - i;
                break;
            }
        }
    }

    // Store positions with valid answers
    vector<int> positions;

    for (int i = 0; i < n; i++)
    {
        if (wait[i] != -1)
        {
            positions.push_back(i);
        }
    }

    // Larger wait first
    // If same wait, earlier position first
    sort(positions.begin(), positions.end(),
        [&](int a, int b)
        {
            if (wait[a] != wait[b])
                return wait[a] > wait[b];

            return a < b;
        });

    // Print waiting figures
    for (int i = 0; i < n; i++)
    {
        cout << wait[i];

        if (i != n - 1)
            cout << " ";
    }

    cout << endl;

    // Print leaderboard
    int limit = min(K, (int)positions.size());

    for (int i = 0; i < limit; i++)
    {
        cout << positions[i] + 1;

        if (i != limit - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}

/*
Time Complexity: O(n²)
Space Complexity: O(n)

Steps I did
Took the team and rating of every entry.
For each entry, checked the entries after it.
Considered only entries belonging to the same team.
Found the first entry having a higher rating.
Calculated the wait as next position - current position.
If no higher rating was found, stored -1.
Collected all entries having a valid wait.
Sorted them by largest wait first.
If two waits were equal, kept the earlier position first.
Printed the waiting values and then the first K positions.
*/