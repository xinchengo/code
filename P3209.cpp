#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 120007;
int t, n, m;
int _t1, _t2;

int head[maxn], nxt[maxn], to[maxn], cnt;
void add(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
int dfn[maxn], low[maxn], dcnt;
int s[maxn], ins[maxn], scnt;
int belong[maxn], bcnt;
void dfs(int u)
{
    dfn[u] = low[u] = ++cnt;
    s[++scnt] = u;
    ins[u] = 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        if (ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        bcnt++;
        while (s[scnt] != u)
            ins[s[scnt]] = 0, belong[s[scnt--]] = bcnt;
        ins[s[scnt]] = 0, belong[s[scnt--]] = bcnt;
    }
}
void init()
{
    cnt = 0, dcnt = 0, bcnt = 0;
    memset(head, 0, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
}

int l[maxn], r[maxn];
int hid[maxn];
int flag;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        if (m <= n * 3 - 6)
            flag = 1;
        else
            flag = 0;
        for (int i = 1; i <= m; i++)
            if (flag)
                scanf("%d%d", &l[i], &r[i]);
            else
                scanf("%d%d", &_t1, &_t2);
        for (int i = 1; i <= n; i++)
            scanf("%d", &_t1), hid[_t1] = i;
        if (!flag)
        {
            puts("NO");
            continue;
        }
        init();
        for (int i = 1; i < m; i++)
            for (int j = i + 1; j <= m; j++)
            {
                int a, b, c, d;
                a = l[i], b = r[i], c = l[j], d = r[j];
                a = hid[a], b = hid[b], c = hid[c], d = hid[d];
                if (b < a)
                    swap(a, b);
                if (d < c)
                    swap(c, d);
                if ((a < c && c < b && b < d) || (c < a && a < d && d < b))
                    add(i, j + m), add(i + m, j), add(j, i + m), add(j + m, i);
            }
        for (int i = 1; i <= m * 2; i++)
            if (!dfn[i])
                dfs(i);
        for (int i = 1; i <= m; i++)
            if (belong[i] == belong[i + m])
            {
                puts("NO"), flag = 0;
                break;
            }
        if (flag)
            puts("YES");
    }
}