#include <iostream>
using namespace std;
const int maxn = 5e4 + 7, maxm = 1e5 + 7, maxk = 5e2 + 7;
int head[maxn], nxt[maxm], to[maxm], ecnt;
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int n, k;
int f[maxn][maxk];
unsigned long long ans;
void dfs(int u, int fa)
{
    f[u][0] = 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != fa)
        {
            dfs(v, u);
            for (int x = 1; x <= k; x++)
                ans += f[v][x - 1] * f[u][k - x];
            for (int x = 1; x <= k; x++)
                f[u][x] += f[v][x - 1];
        }
    }
}
int main()
{
    cin >> n >> k;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, 0);
    cout << ans << endl;
}