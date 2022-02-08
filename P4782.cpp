#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, m, _i, a, _j, b;
vector<int> g[2000007];
int s[2000007], scnt;
int dfn[2000007], low[2000007], q[2000007];
int belong[2000007], bs[2000007], cnt, bcnt;
void dfs(int cur)
{
    low[cur] = dfn[cur] = ++cnt;
    q[cur] = 1;
    s[++scnt] = cur;
    for (int nxt : g[cur])
    {
        if (!dfn[nxt])
        {
            dfs(nxt);
            low[cur] = min(low[nxt], low[cur]);
        }
        if (q[nxt])
            low[cur] = min(dfn[nxt], low[cur]);
    }
    if (dfn[cur] == low[cur])
    {
        ++bcnt;
        while (s[scnt] != cur)
            belong[s[scnt]] = bcnt, bs[bcnt]++, q[s[scnt]] = 0, scnt--;
        belong[s[scnt]] = bcnt, bs[bcnt]++, q[s[scnt]] = 0, scnt--;
    }
}
int iv(int i, int v)
{
    return i + v * n;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> _i >> a >> _j >> b;
        g[_i + n * (a ^ 1)].push_back(_j + n * (b & 1));
        g[_j + n * (b ^ 1)].push_back(_i + n * (a & 1));
    }
    for (int i = 1; i <= n * 2; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        if (belong[i] == belong[i + n])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    cout << "POSSIBLE" << endl;
    for (int i = 1; i <= n; i++)
        cout << (belong[i] > belong[i + n]) << ' ';
    cout << endl;
}