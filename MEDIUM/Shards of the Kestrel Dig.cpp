#include <iostream>
#include <string>
using namespace std;

struct Shard
{
    string code;
    int era;
};

int main()
{
    int Q;
    cin >> Q;

    Shard a[200005];
    int n = 0;

    while (Q--)
    {
        string type, code;
        int era;

        cin >> type >> code >> era;

        if (type == "ADD")
        {
            a[n].code = code;
            a[n].era = era;
            n++;
        }
        else
        {
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                if (a[i].era != era)
                    continue;

                if (a[i].code.substr(0, code.length()) == code)
                    count++;
            }

            cout << count << endl;
        }
    }

    return 0;
}

/*
Time Complexity
ADD: O(1)
QUERY: O(N × L)
N = number of added shards
L = length of prefix
Overall: O(Q × N × L) in the worst case
Space Complexity
O(N × L) — stores all added codes and their eras.
*/