#include <iostream>
using namespace std;
const int maxn = 5e5 + 7;
int n, m;
int head[maxn], nxt[maxn], to[maxn], ecnt;
char val[maxn];
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
namespace q
{
int head[maxn], nxt[maxn], d[maxn], id[maxn], ecnt;
void add(int u, int dep, int qid)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    d[ecnt] = dep;
    id[ecnt] = qid;
}
}; // namespace q
bool ans[maxn];
int fa[maxn];
int heavy[maxn], siz[maxn], dep[maxn];
void predfs(int u)
{
    dep[u] = dep[fa[u]] + 1;
    siz[u] = 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        predfs(v);
        siz[u] += siz[v];
        if (!heavy[u] || siz[v] > siz[heavy[u]])
            heavy[u] = v;
    }
}
bool dis[maxn][26];
bool inc[maxn];
void calc(int u)
{
    dis[dep[u]][val[u] - 'a'] ^= 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (!inc[v])
            calc(v);
    }
}
void dfs(int u, bool keep)
{
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != heavy[u])
            dfs(v, false), ans[u] = max(ans[u], ans[v]);
    }
    if (heavy[u])
    {
        dfs(heavy[u], true);
        inc[heavy[u]] = true;
    }
    calc(u);
    for (int i = q::head[u]; i; i = q::nxt[i])
    {
        int cnt = 0;
        for (int j = 0; j < 26; j++)
            cnt += dis[q::d[i]][j];
        ans[q::id[i]] = (cnt <= 1);
    }
    if (heavy[u])
        inc[heavy[u]] = false;
    if (keep == false)
        calc(u);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        add(fa[i], i);
    }
    predfs(1);
    scanf("%s", val + 1);
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        q::add(a, b, i);
    }
    dfs(1, true);
    for (int i = 1; i <= m; i++)
        printf("%s\n", (ans[i] ? "Yes" : "No"));
}