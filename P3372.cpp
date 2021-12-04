// Fear cuts deeper than swords.

#include <iostream>
#define int long long
using namespace std;
const int MAXN = 1e5 + 1;
int n, m;
int a[MAXN];
int d[MAXN * 4], z[MAXN * 4];
int o, x, y, k;
void build(int x, int cl, int cr)
{
    if (cl == cr)
    {
        d[x] = a[cl];
        return;
    }
    int cm = (cl + cr) >> 1;
    build(x << 1, cl, cm);
    build(x << 1 | 1, cm + 1, cr);
    d[x] = d[x << 1] + d[x << 1 | 1];
}
void pushdown(int x, int cl, int cr)
{
    int cm = (cl + cr) >> 1;
    if (z[x] && cl != cr)
        d[x << 1] += z[x] * (cm - cl + 1), d[x << 1 | 1] += z[x] * (cr - cm), z[x << 1] += z[x], z[x << 1 | 1] += z[x],
            z[x] = 0;
}
void add(int x, int cl, int cr, int l, int r, int k)
{
    if (l <= cl && cr <= r)
    {
        d[x] += k * (cr - cl + 1), z[x] += k;
        return;
    }
    int cm = (cl + cr) >> 1;
    pushdown(x, cl, cr);
    if (l <= cm)
        add(x << 1, cl, cm, l, r, k);
    if (cm < r)
        add(x << 1 | 1, cm + 1, cr, l, r, k);
    d[x] = d[x << 1] + d[x << 1 | 1];
}
int ask(int x, int cl, int cr, int l, int r)
{
    if (l <= cl && cr <= r)
        return d[x];
    int cm = (cl + cr) >> 1, ans = 0;
    pushdown(x, cl, cr);
    if (l <= cm)
        ans += ask(x << 1, cl, cm, l, r);
    if (cm < r)
        ans += ask(x << 1 | 1, cm + 1, cr, l, r);
    return ans;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> o >> x >> y;
        if (o == 1)
            cin >> k, add(1, 1, n, x, y, k);
        else
            cout << ask(1, 1, n, x, y) << endl;
    }
}
