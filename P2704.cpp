#include <iostream>
using namespace std;
int n, m;
int f[102][101][101];
int l[101], cnt;
int b[101], p[101];
char _t[103];
int ans;
int popcnt(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}
int main()
{
    cin >> n >> m;
    for (int S = 0; S < (1 << m); S++)
    {
        if ((S & (S >> 1)) == 0 && (S & (S >> 2)) == 0)
        {
            l[++cnt] = S;
            p[cnt] = popcnt(S);
        }
    }
    if (n == 1)
    {
        cout << (m + 1) / 2 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> _t;
        for (int j = 0; j < m; j++)
        {
            if (toupper(_t[j]) == 'H')
            {
                b[i] |= (1 << j);
            }
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (l[i] & b[1])
        {
            continue;
        }
        f[1][i][0] = p[i];
    }
    if (n > 1)
        for (int i = 1; i <= cnt; i++)
        {
            if (l[i] & b[2])
            {
                continue;
            }
            for (int j = 1; j <= cnt; j++)
            {
                if ((l[i] & l[j]) || (l[j] & b[1]))
                {
                    continue;
                }
                f[2][i][j] = p[i] + p[j];
            }
        }
    if (n > 2)
        for (int r = 3; r <= n; r++)
        {
            for (int i = 1; i <= cnt; i++)
            {
                int S1 = l[i];
                if (S1 & b[r])
                {
                    continue;
                }
                for (int j = 1; j <= cnt; j++)
                {
                    int S2 = l[j];
                    if (S1 & S2)
                    {
                        continue;
                    }
                    for (int k = 1; k <= cnt; k++)
                    {
                        int S3 = l[k];
                        if ((S1 & S3) || (S2 & S3))
                        {
                            continue;
                        }
                        f[r][i][j] = max(f[r][i][j], f[r - 1][j][k] + p[i]);
                    }
                }
            }
        }
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++)
            ans = max(ans, f[n][i][j]);
    cout << ans << endl;
}
