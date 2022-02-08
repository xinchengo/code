#include <iostream>
#include <vector>
using namespace std;
int n, q;
vector<int> g[101];
int v[101][102];
int f[101][102];
int predfs(int cur, int fa)
{
    if (g[cur].size() == 1)
    {
        g[cur].clear();
    }
    if (fa != 0 && g[cur].size())
    {
        for (int i = 0; i < 3; i++)
        {
            if (g[cur][i] == fa)
            {
                swap(g[cur][i], g[cur][2]);
                g[cur].pop_back();
                break;
            }
        }
    }
    for (auto nxt : g[cur])
    {
        if (nxt != fa)
        {
            predfs(nxt, cur);
        }
    }
}
int dfs(int cur, int cnt, int fa)
{
    if (f[cur][cnt] != 0)
    {
        return f[cur][cnt];
    }
    else if (cnt == 0)
    {
        return 0;
    }
    else if (cnt == 1)
    {
        return f[cur][cnt] = v[cur][fa];
    }
    else if (g[cur].empty())
    {
        return 0;
    }
    else
    {
        for (int j = 0; j < cnt; j++)
        {
            f[cur][cnt] = max(f[cur][cnt], dfs(g[cur][0], j, cur) + dfs(g[cur][1], cnt - j - 1, cur) + v[cur][fa]);
        }
        return f[cur][cnt];
    }
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int a, b, val;
        cin >> a >> b >> val;
        v[a][b] = val;
        v[b][a] = val;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    predfs(1, 0);
    cout << dfs(1, q + 1, 0) << endl;
}
