#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
using namespace std;
using ll = long long;
int n, d, ans = 0, v[1500007];
ll m[26], s;
pair<ll, int> l[1000007], r[1000007];
int lcnt, rcnt;
pair<ll, int> *c;
int *cnt;
void dfs(int i, int k, ll sum)
{
    if (i > d)
    {
        c[++(*cnt)].first = sum;
        c[*cnt].second = k;
        return;
    }
    dfs(i + 1, k, sum);
    dfs(i + 1, k | (1 << (i - 1)), sum + m[i]);
    dfs(i + 1, k | (1 << (i - 1)), sum - m[i]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(m + 1, m + n + 1, default_random_engine(seed));
    cnt = &lcnt, c = l, d = n / 2;
    dfs(1, 0, 0LL);
    cnt = &rcnt, c = r, d = n;
    dfs(n / 2 + 1, 0, 0LL);
    sort(l + 1, l + lcnt + 1);
    sort(r + 1, r + rcnt + 1);
    reverse(r + 1, r + rcnt + 1);
    int pl = 1, pr = 1;
    while (pl <= lcnt && pr <= rcnt)
    {
        while (pr <= rcnt && l[pl].first + r[pr].first > 0)
            pr++;
        int pc = pr;
        while (pr <= rcnt && l[pl].first + r[pr].first == 0)
        {
            if (!v[l[pl].second | r[pr].second])
                v[l[pl].second | r[pr].second] = 1, ans++;
            pr++;
        }
        if (l[pl + 1].first == l[pl].first)
            pr = pc;
        pl++;
    }
    cout << ans - 1 << endl;
}
