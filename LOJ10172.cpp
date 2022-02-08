#include <algorithm>
#include <iostream>
using namespace std;
const int mod = 1e6;
int n, m;
int k;
int ka, _t;
int p3[6];
bool va[243];
bool v[243][243];
bool r[243][243];
int id[49], cnt;
int f[10001][49];
int main()
{
    cin >> n >> m;
    p3[0] = 1;
    for (int i = 1; i <= 5; i++)
        p3[i] = p3[i - 1] * 3;
    for (int i = 0; i < p3[m]; i++)
    {
        va[i] = true;
        for (int b = 1; b < m; b++)
        {
            if ((i / p3[b - 1]) % 3 == (i / p3[b]) % 3)
            {
                va[i] = false;
                break;
            }
        }
    }
    for (int i = 0; i < p3[m]; i++)
    {
        if (va[i] == true)
        {
            id[++cnt] = i;
        }
    }
    cerr << cnt << endl;
    for (int i = 0; i < p3[m]; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (va[i] && va[j])
            {
                v[i][j] = v[j][i] = true;
                for (int b = 1; b <= m; b++)
                {
                    if ((i / p3[b - 1]) % 3 == (j / p3[b - 1]) % 3)
                    {
                        v[i][j] = v[j][i] = false;
                        break;
                    }
                }
            }
        }
    }
    cin >> k;
    ka = 0;
    for (int i = 1; i <= m; i++)
    {
        ka *= 3;
        cin >> _t;
        ka += (_t - 1);
    }
    if (va[ka] == false)
    {
        cout << 0 << endl;
        return 0;
    }
    int id_;
    for (id_ = 1; id_ <= cnt; id_++)
    {
        if (id[id_] == ka)
        {
            break;
        }
    }
    f[0][id_] = 1;
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            for (int p = 1; p <= cnt; p++)
            {
                if (v[id[j]][id[p]])
                {
                    f[i][j] = (f[i][j] + f[i - 1][p]) % mod;
                }
            }
        }
    }
    int x1 = k - 1, x2 = n - k;
    int a1 = 0, a2 = 0;
    for (int i = 1; i <= cnt; i++)
    {
        a1 = (a1 + f[x1][i]) % mod;
    }
    for (int i = 1; i <= cnt; i++)
    {
        a2 = (a2 + f[x2][i]) % mod;
    }
    cerr << a1 << ' ' << a2 << endl;
    cout << ((long long)a1 * a2) % mod << endl;
}
