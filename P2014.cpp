#include <cstdio>
#include <list>
using namespace std;
int n, m;
list<int> g[307];
int s[307], k;
int t[307];
int f[307][307];
void dfs(int cur)
{
    t[cur] = 1;
    for (int nxt : g[cur])
    {
        dfs(nxt);
        t[cur] += t[nxt];
        for (int i = t[cur]; i >= 0; i--)
            for (int j = 1; j < i; j++)
                f[cur][i] = max(f[cur][i], f[cur][i - j] + f[nxt][j]);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &k, &s[i]);
        g[k].push_back(i);
        f[i][1] = s[i];
    }
    dfs(0);
    printf("%d\n", f[0][m + 1]);
}
