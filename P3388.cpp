// Fear cuts deeper than swords.

#include <iostream>
#include <queue>
using namespace std;
int n, m, x, y;
bool isc[20007];
int dfn[20007], low[20007], cnt, q[20007], ans;
vector<int> g[20007];
void dfs(int cur, int root)
{
    dfn[cur] = ++cnt;
    low[cur] = dfn[cur];
    q[cur] = 1;
    int ch = 0;
    for (int nxt : g[cur])
    {
        if (!dfn[nxt])
        {
            dfs(nxt, root);
            ch++;
            low[cur] = min(low[cur], low[nxt]);
            if (low[nxt] >= dfn[cur] && cur != root)
                isc[cur] = true;
        }
        // if(q[nxt])
        {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    if (cur == root && ch >= 2)
        isc[cur] = true;
    q[cur] = 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i, i);
    for (int i = 1; i <= n; i++)
        if (isc[i])
            ans++;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (isc[i])
            cout << i << ' ';
    cout << endl;
}
