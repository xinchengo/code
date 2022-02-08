#include <algorithm>
#include <iostream>
using namespace std;
int n;
long long k, s[17], ans;
long long f[65537][17];
bool v[65537];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[1 << (i - 1)][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int cur = 0; cur < (1 << n); cur++)
        {
            if (v[cur] == 0)
            {
                for (int c = 1; c <= n; c++)
                {
                    if (f[cur][c])
                    {
                        for (int x = 1; x <= n; x++)
                        {
                            if ((cur & (1 << (x - 1))) == 0 && abs(s[c] - s[x]) > k)
                            {
                                int nxt = cur | (1 << (x - 1));
                                f[nxt][x] += f[cur][c];
                            }
                        }
                        v[cur] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += f[(1 << n) - 1][i];
    }
    cout << ans << endl;
}
