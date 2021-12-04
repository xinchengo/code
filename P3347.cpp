#include <iostream>
using namespace std;
int n, m;
int a[500007];
int d[2000007];
int o, x, k, y;
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
void change(int x, int t, int cl, int cr, int k)
{
    if (cl == t && cr == t)
    {
        d[x] += k;
        return;
    }
    int cm = (cl + cr) >> 1;
    if (t <= cm)
        change(x << 1, t, cl, cm, k);
    else
        change(x << 1 | 1, t, cm + 1, cr, k);
    d[x] = d[x << 1] + d[x << 1 | 1];
}
int ask(int x, int cl, int cr, int l, int r)
{
    if (l <= cl && cr <= r)
        return d[x];
    int cm = (cl + cr) >> 1, ans = 0;
    if (l <= cm)
        ans += ask(x << 1, cl, cm, l, r);
    if (cm + 1 <= r)
        ans += ask(x << 1 | 1, cm + 1, cr, l, r);
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> o >> x >> y;
        if (o == 1)
            change(1, x, 1, n, y);
        else
            cout << ask(1, 1, n, x, y) << endl;
    }
}
