#pragma GCC optimize(3)
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int t;
int n, m;
char a[10010007], v[10010007];
int outlet(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx && ny && nx <= n && ny <= m)
            cnt += (a[nx * m + ny] == '.');
    }
    return cnt;
}
pair<int, int> q[10000007];
int ql, qr;
int main()
{
    cin >> t;
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(a, 0, (m + 1) * (n + 1) + 1);
        memset(v, 0, (m + 1) * (n + 1) + 1);
        for (int i = 1; i <= n; i++)
            scanf("%s", &a[i * m + 1]);
        ql = 1, qr = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i * m + j] == 'L')
                    q[++qr] = {i, j}, v[i * m + j] = 1;
        while (qr - ql + 1)
        {
            pair<int, int> cur = q[ql++];
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx && ny && nx <= n && ny <= m)
                    if (v[nx * m + ny] == 0 && a[nx * m + ny] != '#')
                        if (outlet(nx, ny) < 2)
                            q[++qr] = {nx, ny}, a[nx * m + ny] = '+', v[nx * m + ny] = 1;
            }
        }
        for (int i = 1; i <= n; i++, putc('\n', stdout))
            for (int j = 1; j <= m; j++)
                putc(a[i * m + j], stdout);
    }
}