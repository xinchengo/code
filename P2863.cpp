// Fear cuts deeper than swords.

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, m;
int a, b;
vector<int> g[20007];
stack<int> s;
int dfn[20007], low[20007], q[20007];
int cnt, bcnt, bs[20007], ans;
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
        bcnt++;
        while (s.top() != cur)
        {
            bs[bcnt]++;
            q[s.top()] = 0;
            s.pop();
        }
        bs[bcnt]++;
        q[s.top()] = 0;
        s.pop();
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 1; i <= bcnt; i++)
        if (bs[i] > 1)
            ans++;
    cout << ans << endl;
}
