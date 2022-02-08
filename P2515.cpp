#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
// Old graph
int n_, m, w_[105], v_[105], d_[105];
vector<int> g_[105];
// Tarjan
stack<int> s;
int dfn[105], low[105], q[105], cnt;
int bcnt, belong[105], bs[105];
// New graph
int n, w[105], v[105];
set<int> g[105];
void dfs(int cur)
{
    dfn[cur] = low[cur] = ++cnt;
    q[cur] = 1;
    s.push(cur);
    for (int nxt : g_[cur])
    {
        if (!dfn[nxt])
        {
            dfs(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        if (q[nxt])
        {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    if (dfn[cur] == low[cur])
    {
        ++bcnt;
        while (s.top() != cur)
            belong[s.top()] = bcnt, bs[bcnt]++, q[s.top()] = 0, s.pop();
        belong[s.top()] = bcnt, bs[bcnt]++, q[s.top()] = 0, s.pop();
    }
}
// DP stuff
int f[107][50007], siz[107], deg[107];
int dfs1(int cur)
{
    for (int i = w[cur]; i <= m; i++)
    {
        f[cur][i] = v[cur];
    }
    siz[cur] = w[cur];
    for (int nxt : g[cur])
    {
        dfs1(nxt);
        siz[cur] += siz[nxt];
        for (int j = m - w[cur]; j >= 0; j--)
        {
            for (int k = 0; k <= j; k++)
            {
                f[cur][j + w[cur]] = max(f[cur][j + w[cur]], f[cur][j + w[cur] - k] + f[nxt][k]);
            }
        }
    }
}
int main()
{
    cin >> n_ >> m;
    for (int i = 1; i <= n_; i++)
    {
        cin >> w_[i];
    }
    for (int i = 1; i <= n_; i++)
    {
        cin >> v_[i];
    }
    for (int i = 1; i <= n_; i++)
    {
        cin >> d_[i];
        if (d_[i])
        {
            g_[d_[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n_; i++)
    {
        if (!dfn[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n_; i++)
    {
        w[belong[i]] += w_[i];
        v[belong[i]] += v_[i];
    }
    for (int i = 1; i <= n_; i++)
    {
        if (belong[i] != belong[d_[i]])
        {
            g[belong[d_[i]]].insert(belong[i]);
            deg[belong[i]]++;
        }
    }
    for (int i = 1; i <= bcnt; i++)
    {
        if (deg[i] == 0)
        {
            g[0].insert(i);
        }
    }
    dfs1(0);
    cout << f[0][m] << endl;
}
