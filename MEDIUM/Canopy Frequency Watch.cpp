#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Species
{
    string name;
    int count;
};

int main()
{
    int n, C;
    cin >> n >> C;

    map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        char type;
        cin >> type;

        if (type == 'S')
        {
            string name;
            cin >> name;

            mp[name]++;
        }
        else
        {
            // Put all species into a list
            vector<Species> v;

            for (auto x : mp)
            {
                Species s;
                s.name = x.first;
                s.count = x.second;
                v.push_back(s);
            }

            // Sort by count (higher first)
            // If count is same, alphabetical order
            sort(v.begin(), v.end(),
                [](Species a, Species b)
                {
                    if (a.count != b.count)
                        return a.count > b.count;

                    return a.name < b.name;
                });

            // Print top C species
            int limit = min(C, (int)v.size());

            for (int j = 0; j < limit; j++)
            {
                cout << v[j].name;

                if (j != limit - 1)
                    cout << " ";
            }

            cout << endl;
        }
    }

    return 0;
}
/*
Simple idea
map stores species → number of sightings.
For S, increase that species' count.
For R, put all species into a list.
Sort the list:
Higher count first.
Alphabetical order if counts are equal.
Print the first C species.

Time Complexity: O(n × m log m) in the worst case, where m is the number of distinct species.
Space Complexity: O(m)
*/