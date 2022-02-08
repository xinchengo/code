#include <iostream>
#define int long long
using namespace std;
int n;
int a[17], b[17], p = 1, ans;
void exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
        p *= a[i];
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        exgcd(p / a[i], a[i], x, y);
        ans = (ans + (b[i] * (p / a[i]) * x) % p) % p;
    }
    cout << (ans % p + p) % p << endl;
}
