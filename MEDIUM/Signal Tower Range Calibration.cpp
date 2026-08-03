/*
For every house:

House is at position X[i]
It needs signal at least Th[i]
Tower is at position C
Tower power is P

Signal received by a house is

P−∣X[i]−C∣

It should be at least Th[i].

So,

P−∣X[i]−C∣≥Th[i]

Move everything:

∣X[i]−C∣≤P−Th[i]

This means:

If we fix a power P,
then the tower must be within P-Th[i] distance from that house.

So the possible positions of the tower for this house are

[X[i]−(P−Th[i]),X[i]+(P−Th[i])]

Every house gives one interval.

If all intervals overlap, then we can place the tower in that common part.

Otherwise, this power P is impossible.

How to find minimum P?

Power can be very large, so try Binary Search.

Low = 0
High = 2e9

For every middle power:

Build interval for every house.
Find intersection of all intervals.
If intersection is non-empty → this power works.
Else increase power.

Binary search gives the minimum answer.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll P, vector<ll> &X, vector<ll> &Th, int N)
{
    ll L = LLONG_MIN;
    ll R = LLONG_MAX;

    for (int i = 0; i < N; i++)
    {
        if (P < Th[i])
            return false;

        ll d = P - Th[i];

        L = max(L, X[i] - d);
        R = min(R, X[i] + d);
    }

    return (L <= R);
}

int main()
{
    int N;
    cin >> N;

    vector<ll> X(N), Th(N);

    for (int i = 0; i < N; i++)
        cin >> X[i];

    for (int i = 0; i < N; i++)
        cin >> Th[i];

    ll low = 0;
    ll high = LLONG_MAX;

    while (low < high)
    {
        ll mid = low + (high - low) / 2;

        if (check(mid, X, Th, N))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << endl;

    return 0;
}

/*
Time Complexity (TC)

Let N be the number of houses.

The check() function scans all houses once:
O(N)
Binary search on P:
Since high = LLONG_MAX, a long long has at most 63 bits, so binary search takes about 63 iterations.
This is a constant.

Therefore,

Time Complexity=O(N×log(LLONG_MAX))=O(63N)=O(N)
	​


In competitive programming, it's usually written as:

TC = O(N log M)

where M is the search range for P.

Space Complexity (SC)

You store two arrays:

X → N elements
Th → N elements

Extra variables (L, R, low, high, etc.) use constant space.

So,

Space Complexity=O(N)
	​

*/