#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int n;
int u, v;
vector<int> g[1000007];
int s[1000007];
long long f[1000007];
void predfs(int cur, int fa, int depth)
{
    f[1] += depth;
    s[cur] = 1;
    for (int &nxt : g[cur])
    {
        if (nxt != fa)
            predfs(nxt, cur, depth + 1), s[cur] += s[nxt];
        else
            nxt = g[cur].back(), g[cur].pop_back();
    }
}
void dfs(int cur)
{
    for (int &nxt : g[cur])
    {
        f[nxt] = f[cur] + n - 2 * s[nxt];
        dfs(nxt);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    predfs(1, 0, 0);
    dfs(1);
    long long mxp = n, mx = f[n];
    for (int i = n; i >= 1; i--)
    {
        if (f[i] >= mx)
            mx = f[i], mxp = i;
    }
    cout << mxp << endl;
    return 0;
}