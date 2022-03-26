#include <algorithm>
#include <iostream>
using namespace std;
const int maxm = 5;
const int maxn = 2e5 + 7;
int m, n;
int a[maxm][maxn];
long long ans;
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
            ans += a[1][i] + a[2][i];
        ans *= 2LL * n;
        printf("%lld\n", ans);
    }
    else
    {
        int c1, c2;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                c1 = 0x7fffffff, c2 = 0;
                for (int k = 1; k <= m; k++)
                    c1 = min(c1, a[k][i] + a[k][j]), c2 = max(c2, a[k][i] + a[k][j]);
                ans += c1 + c2;
            }
        printf("%lld\n", ans);
    }
}
