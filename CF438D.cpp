// Fear cuts deeper than swords.

#include <math.h>
#include <stdio.h>
using namespace std;
int n, m, k, l;
long long r, x;
long long a[100007];
struct node
{
    long long sum;
    long long max;
} d[400007];
long long max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void build(int c, int cl, int cr)
{
    if (cl == cr)
    {
        d[c].sum = a[cl];
        d[c].max = a[cl];
        return;
    }
    int cm = (cl + cr) >> 1;
    build(c << 1, cl, cm);
    build((c << 1) | 1, cm + 1, cr);
    d[c].sum = d[c << 1].sum + d[(c << 1) | 1].sum;
    d[c].max = max(d[c << 1].max, d[(c << 1) | 1].max);
}
long long asksum(int c, int l, int r, int cl, int cr)
{
    if (l <= cl && cr <= r)
    {
        return d[c].sum;
    }
    int cm = (cl + cr) >> 1;
    long long s = 0;
    if (l <= cm)
    {
        s += asksum(c << 1, l, r, cl, cm);
    }
    if (cm < r)
    {
        s += asksum((c << 1) | 1, l, r, cm + 1, cr);
    }
    return s;
}
void rmod(int c, int l, int r, int cl, int cr, long long x)
{
    if (d[c].max < x)
    {
        return;
    }
    if (cl == cr)
    {
        d[c].sum = d[c].sum % x;
        d[c].max = d[c].sum;
        return;
    }
    int cm = (cl + cr) >> 1;
    if (l <= cm)
    {
        rmod(c << 1, l, r, cl, cm, x);
    }
    if (cm < r)
    {
        rmod((c << 1) | 1, l, r, cm + 1, cr, x);
    }
    d[c].sum = d[c << 1].sum + d[(c << 1) | 1].sum;
    d[c].max = max(d[c << 1].max, d[(c << 1) | 1].max);
}
void change(int c, int k, int cl, int cr, long long x)
{
    if (cl == cr)
    {
        d[c].sum = x;
        d[c].max = d[c].sum;
        return;
    }
    int cm = (cl + cr) >> 1;
    if (k <= cm)
    {
        change(c << 1, k, cl, cm, x);
    }
    else
    {
        change((c << 1) | 1, k, cm + 1, cr, x);
    }
    d[c].sum = d[c << 1].sum + d[(c << 1) | 1].sum;
    d[c].max = max(d[c << 1].max, d[(c << 1) | 1].max);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &k);
        if (k == 1)
        {
            scanf("%d%lld", &l, &r);
            printf("%lld\n", asksum(1, l, r, 1, n));
        }
        else if (k == 2)
        {
            scanf("%d%lld%lld", &l, &r, &x);
            rmod(1, l, r, 1, n, x);
        }
        else
        {
            scanf("%d%lld", &l, &r);
            change(1, l, 1, n, r);
        }
    }
}