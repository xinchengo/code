#include <iostream>
using namespace std;
int n, m, o, x, y, a, b, c, d;
long long k;
long long _[1 << 12 | 1][1 << 12 | 1];
void add(int x, int y, long long k)
{
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= m; j += j & -j)
            _[i][j] += k;
}
long long ask(int x, int y)
{
    long long k = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            k += _[i][j];
    return k;
}
int main()
{
    cin >> n >> m;
    while (cin >> o)
    {
        if (o == 1)
            cin >> x >> y >> k, add(x, y, k);
        if (o == 2)
            cin >> a >> b >> c >> d, cout << ask(c, d) - ask(c, b - 1) - ask(a - 1, d) + ask(a - 1, b - 1) << endl;
    }
}
