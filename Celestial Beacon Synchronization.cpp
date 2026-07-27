#include <bits/stdc++.h>
using namespace std;

struct Query{
    int l, r, idx;
};

int block;
long long ans = 0;

vector<int> a;
vector<int> freq(1000001);

bool cmp(Query x, Query y)
{
    if(x.l / block != y.l / block)
        return x.l < y.l;
    return x.r < y.r;
}

void add(int pos)
{
    int x = a[pos];

    ans -= 1LL * freq[x] * freq[x];
    freq[x]++;
    ans += 1LL * freq[x] * freq[x];
}

void removee(int pos)
{
    int x = a[pos];

    ans -= 1LL * freq[x] * freq[x];
    freq[x]--;
    ans += 1LL * freq[x] * freq[x];
}

int main()
{
    int n, q;
    cin >> n >> q;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<Query> queries(q);

    for(int i = 0; i < q; i++)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    block = sqrt(n);

    sort(queries.begin(), queries.end(), cmp);

    vector<long long> result(q);

    int L = 1, R = 0;

    for(Query cur : queries)
    {
        while(L > cur.l)
            add(--L);

        while(R < cur.r)
            add(++R);

        while(L < cur.l)
            removee(L++);

        while(R > cur.r)
            removee(R--);

        result[cur.idx] = ans;
    }

    for(long long x : result)
        cout << x << "\n";
}