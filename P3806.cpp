#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e4 + 7, maxm = 2e4 + 7, maxq = 1e2 + 7;

int n;
int head[maxn], nxt[maxm], to[maxm], w[maxm], cnt;
bool blocked[maxn];
void add(int u, int v, int a)
{
    nxt[++cnt] = head[u], head[u] = cnt;
    to[cnt] = v, w[cnt] = a;
}

int m;
int q[maxq], ans[maxq];

int root, siz[maxn], minch, tsiz;
void get_root(int u, int fa)
{
    siz[u] = 1;
    int maxch = 0;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != fa && !blocked[v])
        {
            get_root(v, u);
            siz[u] += siz[v];
            maxch = max(maxch, siz[v]);
        }
    }
    maxch = max(maxch, tsiz - siz[u]);
    if (maxch < minch)
        minch = maxch, root = u;
}

struct p
{
    int dis, id, belong;
    const bool operator<(const p &b) const
    {
        return dis < b.dis;
    }
} dis[maxn];
int dcnt, ust;
void get_dis(int u, int fa, int d)
{
    if (u == root)
        dcnt = 0, dis[++dcnt] = p{d, u, u};
    else
        dis[++dcnt] = p{d, u, ust};
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (u == root)
            ust = v;
        if (v != fa && !blocked[v])
            get_dis(v, u, d + w[i]);
    }
}
void calc(int u)
{
    get_dis(u, 0, 0);
    sort(dis + 1, dis + dcnt + 1);
    for (int i = 1; i <= m; i++)
    {
        if (!ans[i])
        {
            int l = 1, r = dcnt;
            while (l < r)
            {
                if (dis[l].dis + dis[r].dis > q[i])
                    r--;
                else if (dis[l].dis + dis[r].dis < q[i])
                    l++;
                else if (dis[l].belong == dis[r].belong)
                {
                    if (dis[r].dis == dis[r - 1].dis)
                        r--;
                    else
                        l++;
                }
                else
                {
                    ans[i] = 1;
                    break;
                }
            }
        }
    }
}
void solve(int u)
{
    blocked[u] = 1;
    calc(u);
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (!blocked[v])
        {
            minch = n, tsiz = siz[v];
            get_root(v, 0);
            solve(root);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &q[i]);
        if (q[i] == 0)
            ans[i] = 1;
    }

    minch = n, tsiz = n;
    get_root(1, 0);
    solve(root);

    for (int i = 1; i <= m; i++)
    {
        if (ans[i])
            puts("AYE");
        else
            puts("NAY");
    }
}