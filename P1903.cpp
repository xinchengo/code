// Fear cuts deeper than swords.

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, m, c[150001], t[150001], v[1000001], a[150001], ans, bs, qnt, rnt;
char o[5];
struct query
{
    int l, r, p, i;
    bool operator<(const query b) const
    {
        if (l / bs == b.l / bs)
        {
            if (r / bs == b.r / bs)
                return p < b.p;
            return r < b.r;
        }
        return l < b.l;
    }
} q[150001];
struct change
{
    int p, c, l;
} r[150001];
void add(int x)
{
    if (!v[x])
        ans++;
    v[x]++;
}
void del(int x)
{
    v[x]--;
    if (!v[x])
        ans--;
}
int main()
{
    cin >> n >> m;
    bs = pow(n, 2.0 / 3.0);
    for (int i = 1; i <= n; i++)
        cin >> c[i], t[i] = c[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> o;
        if (o[0] == 'Q')
        {
            qnt++;
            cin >> q[qnt].l >> q[qnt].r;
            q[qnt].p = rnt;
            q[qnt].i = qnt;
        }
        else
        {
            rnt++;
            cin >> r[rnt].p >> r[rnt].c;
            r[rnt].l = t[r[rnt].p];
            t[r[rnt].p] = r[rnt].c;
        }
    }
    sort(q + 1, q + qnt + 1);
    for (int i = 1, pl = 1, pr = 0, p = 0; i <= qnt; i++)
    {
        while (p < q[i].p)
        {
            if (pl <= r[p + 1].p && r[p + 1].p <= pr)
                del(r[p + 1].l), add(r[p + 1].c);
            c[r[p + 1].p] = r[p + 1].c;
            p++;
        }
        while (p > q[i].p)
        {
            if (pl <= r[p].p && r[p].p <= pr)
                del(r[p].c), add(r[p].l);
            c[r[p].p] = r[p].l;
            p--;
        }
        while (pl > q[i].l)
            add(c[--pl]);
        while (pr < q[i].r)
            add(c[++pr]);
        while (pl < q[i].l)
            del(c[pl++]);
        while (pr > q[i].r)
            del(c[pr--]);
        a[q[i].i] = ans;
    }
    for (int i = 1; i <= qnt; i++)
    {
        cout << a[i] << endl;
    }
}
