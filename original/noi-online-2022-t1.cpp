#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
const int maxn = 5e5 + 7;
int n, m;
int a[maxn], b[maxn];
int s[maxn], scnt;
pair<int, int> pre[maxn];
int c[maxn];
pair<pair<int, int>, int> q[maxn];
int ans[maxn];
void add(int x, int k)
{
    for (; x <= n; x += x & -x)
        c[x] += k;
}
int ask(int x)
{
    int k = 0;
    for (; x; x -= x & -x)
        k += c[x];
    return k;
}
int main()
{
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    s[++scnt] = 0, b[0] = 1e7;
    for (int i = 1; i <= n; i++)
    {
        while (a[s[scnt]] == a[i] || b[s[scnt]] <= b[i])
            scnt--;
        pre[i] = make_pair(s[scnt], i);
        s[++scnt] = i;
    }
    sort(pre + 1, pre + n + 1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].first.first, &q[i].first.second);
        q[i].second = i;
    }
    sort(q + 1, q + m + 1);
    int p = 1;
    for (int i = 1; i <= m; i++)
    {
        while (p <= n && pre[p].first < q[i].first.first)
            add(pre[p].second, 1), p++;
        ans[q[i].second] = ask(q[i].first.second) - ask(q[i].first.first - 1);
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
}
