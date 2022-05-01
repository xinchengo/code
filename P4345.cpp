#include <iostream>
using namespace std;
const long long p = 2333;
long long pmod[p + 1], pinv[p + 1];
long long t;
long long n, k;
long long x, y;
long long f[p + 1][p + 1];
long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    long long u = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return u;
}
long long C(long long n, long long m)
{
    if (m > n)
        return 0;
    return (long long)pmod[n] * pinv[m] * pinv[n - m] % p;
}
long long Lucas(long long n, long long m)
{
    if (m == 0)
        return 1;
    else
        return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}
long long F(long long n, long long k)
{
    if (n < p && k < p)
        return f[n][k];
    return (f[n % p][p - 1] * F(n / p, k / p - 1) % p + Lucas(n / p, k / p) * f[n % p][k % p] % p) % p;
}
int main()
{
    cin >> t;
    // preprocess
    pmod[0] = 1;
    for (long long i = 1; i < p; i++)
        pmod[i] = i * pmod[i - 1] % p;
    exgcd(pmod[p - 1], p, x, y);
    pinv[p - 1] = (x % p + p) % p;
    for (long long i = p - 1; i >= 1; i--)
        pinv[i - 1] = i * pinv[i] % p;
    for (long long x = 0; x < p; x++)
        f[x][0] = 1;
    for (long long x = 0; x < p; x++)
        for (long long i = 1; i < p; i++)
            f[x][i] = (C(x, i) + f[x][i - 1]) % p;
    while (t--)
    {
        cin >> n >> k;
        cout << F(n, k) << endl;
    }
}