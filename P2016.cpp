#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> g[1501];
int f[1501][2];
int dfs(int cur, int fa)
{
    f[cur][0] = 0;
    f[cur][1] = 1;
    for (auto nxt : g[cur])
    {
        if (nxt != fa)
        {
            dfs(nxt, cur);
            f[cur][0] += f[nxt][1];
            f[cur][1] += min(f[nxt][1], f[nxt][0]);
        }
    }
}
int main()
{
    cin >> n;
    for (int i, j = 1; j <= n; j++)
    {
        cin >> i >> k;
        g[i].resize(k);
        for (int l = 0; l < k; l++)
        {
            cin >> g[i][l];
        }
    }
    dfs(0, -1);
    cout << min(f[0][1], f[0][0]) << endl;
}
