#include <iostream>
#pragma GCC optimize(3)
using namespace std;
int n, fa[10000007], t, cnt;
long long a, b, c;
int get_fa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = get_fa(fa[x]);
}
void merge(int a, int b)
{
    int _a = get_fa(a), _b = get_fa(b);
    if (_a != _b)
        fa[_a] = _b, cnt--;
}
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
int main()
{
    cin >> n, cnt = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        fa[t] = t;
    }
    for (int x = 1; x <= 1e7; x++)
    {
        for (int y = x + 1; 2LL * x * y <= 1e7 && 1LL * y * y - 1LL * x * x <= 1e7; y++)
        {
            a = 2LL * x * y, b = 1LL * y * y - 1LL * x * x, c = 1LL * y * y + 1LL * x * x;
            if (gcd(a, b) == 1)
            {
                if (fa[a] && fa[b])
                    merge(a, b);
                if (c <= 1e7 && fa[b] && fa[c])
                    merge(b, c);
                if (c <= 1e7 && fa[a] && fa[c])
                    merge(a, c);
            }
        }
    }
    cout << cnt << endl;
}