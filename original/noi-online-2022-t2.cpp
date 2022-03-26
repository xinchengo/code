#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2e6 + 7, maxm = 4e6 + 7;
int head[maxn], nxt[maxm], to[maxm], ecnt;
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int t, n;
int k[maxn];
int fa[maxn], siz[maxn];
int get_fa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = get_fa(fa[x]);
}
void merge(int a, int b)
{
    int f_a = get_fa(a), f_b = get_fa(b);
    if (f_a != f_b)
    {
        siz[f_a] += siz[f_b];
        fa[f_b] = f_a;
    }
}
int ord[maxn];
int mark[maxn];
bool comp(int a, int b)
{
    return k[a] < k[b];
}
int main()
{
    freopen("discuss.in", "r", stdin);
    freopen("discuss.out", "w", stdout);
    int _t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 1; i <= n; i++)
            head[i] = 0;
        scanf("%d", &n);
        bool flag = false;
        int ansa, ansb;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &k[i]);
            for (int j = 1; j <= k[i]; j++)
            {
                scanf("%d", &_t);
                add(i, n + _t);
            }
        }
        for (int i = 1; i <= n * 2 + 2; i++)
        {
            fa[i] = i;
            siz[i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            ord[i] = i;
            siz[i] = 0;
        }
        sort(ord + 1, ord + n + 1, comp);
        for (int i = 1; i <= n; i++)
        {
            int c = ord[i];
            for (int j = head[c]; j; j = nxt[j])
                merge(c, to[j]);
            if (siz[get_fa(c)] > k[c])
            {
                flag = true;
                ansa = c;
                for (int j = head[c]; j; j = nxt[j])
                    mark[to[j]] = (t + 1) << 1;
                for (int j = n + 1; j <= n * 2; j++)
                    if (get_fa(j) == get_fa(c) && mark[j] != ((t + 1) << 1))
                        mark[j] = ((t + 1) << 1) | 1;
                bool flaga = 0, flagb = 0;
                for (int j = 1; j <= n; j++)
                {
                    flaga = 0, flagb = 0;
                    if (get_fa(c) == get_fa(j))
                        for (int l = head[j]; l; l = nxt[l])
                            if (mark[to[l]] == ((t + 1) << 1))
                                flaga = 1;
                            else if (mark[to[l]] == (((t + 1) << 1) | 1))
                                flagb = 1;
                    if (flaga && flagb)
                    {
                        ansb = j;
                        break;
                    }
                }
                break;
            }
        }
        if (flag == false)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            printf("%d %d\n", ansa, ansb);
        }
    }
}
