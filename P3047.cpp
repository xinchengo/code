#include <iostream>
#include <vector>
using namespace std;
int n, k, c[100001];
vector<int> t[100001];
int f[100001][21];
int g[100001][21];
int dfs1(int cur, int fa)
{
    f[cur][0] = c[cur];
    for (auto nxt : t[cur])
    {
        if (nxt != fa)
        {
            dfs1(nxt, cur);
            for (int i = k; i >= 1; i--)
            {
                f[cur][i] += f[nxt][i - 1];
            }
        }
    }
}
int dfs2(int cur, int fa)
{
    for (auto nxt : t[cur])
    {
        if (nxt != fa)
        {
            g[nxt][0] = f[nxt][0];
            g[nxt][1] = g[cur][0] + f[nxt][1];
            for (int i = 2; i <= k; i++)
            {
                g[nxt][i] = g[cur][i - 1] + f[nxt][i] - f[nxt][i - 2];
            }
            dfs2(nxt, cur);
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int _i = 1; _i < n; _i++)
    {
        int i, j;
        cin >> i >> j;
        t[i].push_back(j);
        t[j].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    dfs1(1, 0);
    for (int i = 0; i <= k; i++)
    {
        g[1][i] = f[1][i];
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= k; j++)
        {
            sum += g[i][j];
        }
        cout << sum << endl;
    }
}
