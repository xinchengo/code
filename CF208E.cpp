#include <iostream>
using namespace std;
const int maxn = 1e5 + 7, maxm = 2e5 + 7;
int n, m;
int head[maxn], nxt[maxm], to[maxm], ecnt;
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int qhead[maxn], qnxt[maxn], qto[maxn], qid[maxn], qcnt;
void qadd(int u, int v, int id)
{
    qnxt[++qcnt] = qhead[u];
    qhead[u] = qcnt;
    qto[qcnt] = v;
    qid[qcnt] = id;
}
int fa[maxn][19], rt[maxn], rcnt;
int cnt[maxn], ans[maxn];
int siz[maxn], heavy[maxn], dep[maxn];
void predfs(int u)
{
    dep[u] = dep[fa[u][0]] + 1;
    siz[u] = 1;
    for (int i = 1; i <= 18; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        predfs(v);
        siz[u] += siz[v];
        if (!heavy[u] || siz[heavy[u]] < siz[v])
            heavy[u] = v;
    }
}
bool inc[maxn];
void calc(int u, int k)
{
    cnt[dep[u]] += k;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (!inc[v])
            calc(v, k);
    }
}
void dfs(int u, bool keep)
{
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != heavy[u])
            dfs(v, false);
    }
    if (heavy[u])
    {
        dfs(heavy[u], true);
        inc[heavy[u]] = true;
    }
    calc(u, 1);
    for (int i = qhead[u]; i; i = qnxt[i])
        ans[qid[i]] = cnt[qto[i]] - 1;
    if (heavy[u])
        inc[heavy[u]] = false;
    if (keep == false)
        calc(u, -1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fa[i][0];
        if (fa[i][0])
            add(fa[i][0], i);
        else
            rt[++rcnt] = i;
    }
    for (int i = 1; i <= rcnt; i++)
        predfs(rt[i]);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int v, p;
        cin >> v >> p;
        int d = dep[v];
        for (int k = 0; (1 << k) <= p; k++)
            if (p & (1 << k))
                v = fa[v][k];
        qadd(v, d, i);
    }
    for (int i = 1; i <= rcnt; i++)
        dfs(rt[i], false);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
}