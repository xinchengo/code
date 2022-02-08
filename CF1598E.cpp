#include <iostream>
using namespace std;
int n, m, q;
int fcnt;
int ans;
int f1[1007][1007];
int f2[1007][1007];
bool c[1007][1007];
int x, y;
void update(int x, int y)
{
    if (1 <= x && x <= n && 1 <= y && y <= m)
    {
        ans -= f1[x][y] + f2[x][y];
        f1[x][y] = c[x][y] ? 0 : (f2[x + 1][y] + 1);
        f2[x][y] = c[x][y] ? 0 : (f1[x][y + 1] + 1);
        ans += f1[x][y] + f2[x][y];
    }
}
int main()
{
    cin >> n >> m >> q;
    fcnt = n * m;
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            update(i, j);
    while (q--)
    {
        cin >> x >> y;
        fcnt -= !c[x][y], c[x][y] = !c[x][y], fcnt += !c[x][y];
        for (; x && y; x--, y--)
            update(x, y), update(x - 1, y), update(x, y - 1);
        cout << ans - fcnt << endl;
    }
}