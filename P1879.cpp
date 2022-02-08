#include <iostream>
using namespace std;
int m, n, _t;
int row[13];
long long f[13][4097], ans, cnt;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> _t;
            if (_t)
            {
                row[i] |= (1 << (j - 1));
            }
        }
    }
    for (int k = 0; k < (1 << n); k++)
    {
        if ((k & (k >> 1)) == 0 && ((~row[1]) & k) == 0)
        {
            f[1][k] = 1;
        }
    }
    for (int i = 2; i <= m; i++)
    {
        for (int k = 0; k < (1 << n); k++)
        {
            if ((k & (k >> 1)) == 0 && ((~row[i]) & k) == 0)
            {
                for (int k_ = 0; k_ < (1 << n); k_++)
                    if ((k_ & k) == 0)
                        f[i][k] = (f[i][k] + f[i - 1][k_]) % 100000000;
            }
        }
    }
    for (int k = 0; k < (1 << n); k++)
    {
        ans = (ans + f[m][k]) % 100000000;
    }
    cout << ans << endl;
}
