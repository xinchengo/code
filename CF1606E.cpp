#include <iostream>
using namespace std;
const int mod = 998244353;
int n, x, ans;
int c[507][507];
int f[507][507];
int quick_pow(int b, int p)
{
    int ans = 1;
    while (p)
    {
        if (p & 1)
            ans = 1LL * ans * b % mod;
        b = 1LL * b * b % mod;
        p >>= 1;
    }
    return ans;
}
int calc(int i, int j)
{
    if (f[i][j] != -1)
        1;
    else if (i > j)
        f[i][j] = ((quick_pow(j, i) - quick_pow(j - 1, i)) % mod + mod) % mod;
    else if (i <= j)
    {
        f[i][j] = 0;
        for (int k = 0; k < i; k++)
            f[i][j] = (f[i][j] + ((1LL * calc(i - k, j - i + 1) * quick_pow(i - 1, k)) % mod) * c[i][k] % mod) % mod;
    }
    return f[i][j];
}
int main()
{
    cin >> n >> x;
    c[0][0] = 1;
    for (int i = 1; i <= 500; i++)
        c[i][0] = 1;
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    for (int i = 0; i <= 500; i++)
        for (int j = 0; j <= 500; j++)
            f[i][j] = -1;
    for (int i = 1; i <= x; i++)
        ans += calc(n, i), ans %= mod;
    cout << ans << endl;
}