#include <iostream>
#include <vector>
using namespace std;
vector<int> g[400007];
int t, n, m, a, b, q[400007], v[400007], v2[400007], vi[400007];
int dfs1(int cur)
{
    v[cur] = 1, q[cur] = 1;
    for (auto nxt : g[cur])
    {
        if (!v[nxt])
            dfs1(nxt);
        else if (v[nxt] && q[nxt])
            v2[nxt] = 1, vi[nxt] = 1;
        else if (v[nxt] && !q[nxt])
            v2[nxt] = 1;
    }
    q[cur] = 0;
    return 0;
}
int dfs2(int cur)
{
    v2[cur] = 1;
    for (auto nxt : g[cur])
        if (!v2[nxt])
            dfs2(nxt);
    return 0;
}
int dfs3(int cur)
{
    vi[cur] = 1;
    for (auto nxt : g[cur])
        if (!vi[nxt])
            dfs3(nxt);
    return 0;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            v[i] = 0, v2[i] = 0, vi[i] = 0, g[i].clear();
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
        }
        dfs1(1);
        for (int i = 1; i <= n; i++)
            if (v2[i])
                dfs2(i);
        for (int i = 1; i <= n; i++)
            if (vi[i])
                dfs3(i);
        for (int i = 1; i <= n; i++)
        {
            if (!v[i])
                cout << 0 << ' ';
            else if (vi[i])
                cout << -1 << ' ';
            else if (v2[i])
                cout << 2 << ' ';
            else
                cout << 1 << ' ';
        }
        cout << endl;
    }
}
