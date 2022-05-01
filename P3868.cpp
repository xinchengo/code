#include <iostream>
using namespace std;
int k;
long long a[17], b[17], prod = 1, ans;
long long qmul(long long a, long long b, long long p)
{
    long long ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ans;
}
void exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
long long x, y;
int main()
{
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    for (int i = 1; i <= k; i++)
        prod *= b[i];
    for (int i = 1; i <= k; i++)
    {
        long long m = prod / b[i];
        exgcd(m, b[i], x, y);
        x = (x % b[i] + b[i]) % b[i];
        ans = (ans + qmul(a[i], qmul(x, m, prod), prod)) % prod;
    }
    cout << ans << endl;
}