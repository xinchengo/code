#include <algorithm>
#include <iostream>
using namespace std;
int t;
int n, m;
struct a_
{
    int val;
    int id;
    bool operator<(const a_ &b) const
    {
        return val < b.val;
    }
} a[10007];
int val, ans[10007];
int x[11], r[11];
char s[11][10007];
int main()
{
    cin >> t;
    while (t--)
    {
        val = -2147483648;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i <= n; i++)
            cin >> (s[i] + 1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                s[i][j] -= '0';
        for (int k = 0; k < 1 << n; k++)
        {
            int cnt = 0;
            for (int i = 1; i <= m; i++)
                a[i].val = 0, a[i].id = i;
            for (int i = 1; i <= n; r[i] = 0, i++)
                for (int j = 1; j <= m; j++)
                    a[j].val += ((k & (1 << (i - 1))) ? 1 : -1) * s[i][j];
            sort(a + 1, a + m + 1);
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                    if (s[j][a[i].id])
                        r[j] += i;
            for (int i = 1; i <= n; i++)
                cnt += abs(x[i] - r[i]);
            if (cnt > val)
            {
                val = cnt;
                for (int i = 1; i <= m; i++)
                    ans[a[i].id] = i;
            }
        }
        for (int i = 1; i <= m; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}