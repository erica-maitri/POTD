#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    set<string> registered;
    long long total = 0;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        // Check if exact string already exists
        if (registered.count(s))
        {
            cout << -1 << endl;
            continue;
        }

        int longest = 0;

        // Check all prefixes of s
        for (int j = 1; j <= s.length(); j++)
        {
            string prefix = s.substr(0, j);

            if (registered.count(prefix))
            {
                longest = j;
            }
        }

        // Novelty score
        int score = s.length() - longest;

        cout << score << endl;

        total += score;

        // Add new call sign
        registered.insert(s);
    }

    cout << "Total: " << total << endl;

    return 0;
}