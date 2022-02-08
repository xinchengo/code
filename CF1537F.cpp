#include <iostream>
#include <vector>
using namespace std;
int n, m, v[200007], t[200007], div_[200007], a, b, o;
vector<int> g[200007];
long long d;
void dfs(int cur, int col)
{
    div_[cur] = col;
    for (int nxt : g[cur])
    {
        if (div_[nxt] == col)
            o = 1;
        if (div_[nxt] == -1)
            dfs(nxt, !col);
    }
}
void solve()
{
    long long vsum = 0, tsum = 0;
    o = 0, d = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        div_[i] = -1, g[i].clear();
    for (int i = 1; i <= n; i++)
        cin >> v[i], d += v[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i], d -= t[i];
    for (int i = 1; i <= m; i++)
        cin >> a >> b, g[a].push_back(b), g[b].push_back(a);
    dfs(1, 1);
    if ((d + 0x1000000000000000) & 1)
        cout << "NO" << endl;
    else if (o)
        cout << "YES" << endl;
    else
    {
        long long cnt[2] = {0LL, 0LL};
        for (int i = 1; i <= n; i++)
            cnt[div_[i]] += (v[i] - t[i]);
        if (cnt[0] == cnt[1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
