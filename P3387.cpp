// Fear cuts deeper than swords.

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int n, m;
vector<int> g[10007];
vector<int> h[10007];
vector<int> k[10007];
vector<int> t;
stack<int> s;
int a[10007], b[10007];
int dfn[10007], low[10007], q[10007];
int cnt, bcnt, belong[10007], bs[10007], f[10007];
int ind[10007], ans;
void dfs(int cur)
{
    dfn[cur] = ++cnt;
    low[cur] = dfn[cur];
    q[cur] = 1;
    s.push(cur);
    for (int nxt : g[cur])
    {
        if (!dfn[nxt])
        {
            dfs(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        if (q[nxt])
            low[cur] = min(low[cur], dfn[nxt]);
    }
    if (dfn[cur] == low[cur])
    {
        ++bcnt;
        while (s.top() != cur)
            belong[s.top()] = bcnt, bs[bcnt]++, q[s.top()] = 0, s.pop();
        belong[s.top()] = bcnt, bs[bcnt]++, q[s.top()] = 0, s.pop();
    }
}
void topo()
{
    queue<int> q;
    for (int i = 1; i <= bcnt; i++)
        if (ind[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        t.push_back(cur);
        for (int nxt : h[cur])
        {
            ind[nxt]--;
            if (ind[nxt] == 0)
                q.push(nxt);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        b[belong[i]] += a[i];
    for (int i = 1; i <= n; i++)
        for (int j : g[i])
            if (belong[i] != belong[j])
                h[belong[i]].push_back(belong[j]), k[belong[j]].push_back(belong[i]), ind[belong[j]]++;
    topo();
    for (int i = 0; i < bcnt; i++)
    {
        f[t[i]] = b[t[i]];
        for (int pre : k[t[i]])
            f[t[i]] = max(f[t[i]], f[pre] + b[t[i]]);
    }
    for (int i = 1; i <= bcnt; i++)
        ans = max(f[i], ans);
    cout << ans << endl;
}
