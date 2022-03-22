#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 7;
int n;
int head[maxn], nxt[maxn], to[maxn], w[maxn], ecnt;
void add(int u, int v, char letter)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
    w[ecnt] = 1 << (letter - 'a');
}
int fa[maxn];
int sta[maxn], dep[maxn], siz[maxn], heavy[maxn];
void predfs(int u)
{
    dep[u] = dep[fa[u]] + 1;
    siz[u] = 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        sta[v] = sta[u] ^ w[i];
        predfs(v);
        siz[u] += siz[v];
        if (!heavy[u] || siz[v] > siz[heavy[u]])
            heavy[u] = v;
    }
}
int f[1 << 22], ans[maxn];
void calc(int u, int top)
{
    if (f[sta[u]])
        ans[top] = max(ans[top], dep[u] + f[sta[u]] - 2 * dep[top]);
    for (int i = 0; i < 22; i++)
        if (f[sta[u] ^ (1 << i)])
            ans[top] = max(ans[top], dep[u] + f[sta[u] ^ (1 << i)] - 2 * dep[top]);
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        calc(v, top);
    }
}
void add(int u)
{
    f[sta[u]] = max(f[sta[u]], dep[u]);
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        add(v);
    }
}
void del(int u)
{
    f[sta[u]] = 0;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        del(v);
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
        dfs(heavy[u], true);
    if (f[sta[u]])
        ans[u] = max(ans[u], f[sta[u]] - dep[u]);
    for (int i = 0; i < 22; i++)
        if (f[sta[u] ^ (1 << i)])
            ans[u] = max(ans[u], f[sta[u] ^ (1 << i)] - dep[u]);
    f[sta[u]] = max(f[sta[u]], dep[u]);
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != heavy[u])
        {
            calc(v, u);
            add(v);
        }
    }
    if (keep == false)
        del(u);
}
void postdfs(int u)
{
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        postdfs(v);
        ans[u] = max(ans[u], ans[v]);
    }
}
int main()
{
    scanf("%d", &n);
    char _c[10];
    for (int i = 2; i <= n; i++)
    {
        scanf("%d%s", &fa[i], _c);
        add(fa[i], i, _c[0]);
    }
    predfs(1);
    dfs(1, true);
    postdfs(1);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
}