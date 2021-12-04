// Fear cuts deeper than swords.

#include <algorithm>
#include <cmath>
#include <iostream>
#define int long long
using namespace std;
int n, m, bs, chance;
int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}
struct query
{
    int l;
    int r;
    int id;
    bool operator<(const query &b) const
    {
        if (l / bs != b.l / bs)
        {
            return l < b.l;
        }
        return ((l / bs) & 1) ? r < b.r : r > b.r;
    }
} q[50007];
struct ans
{
    int y;
    int x;
    void s()
    {
        if (x != 0)
        {
            int u = gcd(x, y);
            x = x / u;
            y = y / u;
            return;
        }
        else
        {
            return;
        }
    }
} a[50007];
int c[50007], v[50007];
void widen(int x)
{
    chance += v[x];
    v[x]++;
}
void narrow(int x)
{
    v[x]--;
    chance -= v[x];
}
signed main()
{
    cin >> n >> m;
    bs = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; i++)
    {
        if (q[i].l == q[i].r)
        {
            a[q[i].id] = ans{0, 1};
            continue;
        }
        while (l > q[i].l)
        {
            widen(c[--l]);
        }
        while (r < q[i].r)
        {
            widen(c[++r]);
        }
        while (l < q[i].l)
        {
            narrow(c[l++]);
        }
        while (r > q[i].r)
        {
            narrow(c[r--]);
        }
        a[q[i].id] = ans{chance, ((r - l + 1) * (r - l)) / 2};
    }
    for (int i = 1; i <= m; i++)
    {
        a[i].s();
        cout << a[i].y << '/' << a[i].x << endl;
    }
}
