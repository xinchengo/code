#include <iostream>
#include <vector>
using namespace std;
int t, n;
int u, v;
vector<int> g[200007];
bool c[200007];
int cnt[2], ans[200007], vis[200007];
void dfs(int cur, int fa)
{
    c[cur] = !c[fa], cnt[c[cur]]++;
    for (auto nxt : g[cur])
        if (nxt != fa)
            dfs(nxt, cur);
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            g[i].clear(), ans[i] = 0, vis[i] = 0;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cnt[0] = cnt[1] = 0;
        dfs(1, 0);
        int p = 1, lptr = 0, target = 1;
        if (cnt[1] > cnt[0])
            target = 0;
        while (cnt[target])
        {
            if (cnt[target] & 1)
            {
                for (int i = p; i < (p << 1); i++)
                {
                    lptr++;
                    while (c[lptr] != target)
                        lptr++;
                    ans[lptr] = i;
                    vis[i] = 1;
                }
            }
            cnt[target] >>= 1;
            p <<= 1;
        }
        lptr = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0)
            {
                lptr++;
                while (vis[lptr])
                    lptr++;
                ans[i] = lptr;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}