
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
    long long id;
    int count;
    int firstPosition;
};

int main()
{
    int N, K;
    cin >> N >> K;

    map<long long, int> count;
    map<long long, int> firstPosition;

    for (int i = 1; i <= N; i++)
    {
        char type;
        long long id;

        cin >> type >> id;

        if (type == '+')
        {
            count[id]++;

            // Store only the first + position
            if (firstPosition.find(id) == firstPosition.end())
            {
                firstPosition[id] = i;
            }
        }
        else
        {
            count[id]--;
        }
    }

    vector<Person> people;

    // Take only IDs with positive count
    for (auto x : count)
    {
        long long id = x.first;
        int c = x.second;

        if (c > 0)
        {
            people.push_back({id, c, firstPosition[id]});
        }
    }

    // Sort according to the required ranking
    sort(people.begin(), people.end(),
        [](Person a, Person b)
        {
            if (a.count != b.count)
                return a.count > b.count;

            return a.firstPosition < b.firstPosition;
        });

    // Print at most K people
    int limit = min(K, (int)people.size());

    for (int i = 0; i < limit; i++)
    {
        cout << people[i].id << " " << people[i].count << endl;
    }

    return 0;
}

/*
Time Complexity: O(N log N)
Space Complexity: O(N)
*/