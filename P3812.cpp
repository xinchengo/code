#include <iostream>
using namespace std;
int n;
long long a[51], p[51], ans;
void insert1(long long x)
{
    for (int i = 50; i >= 0; i--)
        if (x >> i)
        {
            if (p[i] == 0)
            {
                p[i] = x;
                break;
            }
            x = x ^ p[i];
        }
}
void insert2(long long x)
{
    for (int i = 50; i >= 0; i--)
        if (x >> i)
        {
            if (p[i] == 0)
            {
                p[i] = x;
                for (int j = i - 1; j >= 0; j--)
                    if (p[j] && (p[i] >> j & 1))
                        p[i] ^= p[j];
                for (int j = i + 1; j <= 50; j++)
                    if (p[j] >> i & 1)
                        p[j] ^= p[i];
            }
        }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x = rand() % 2;
    if (x)
    {
        for (int i = 1; i <= n; i++)
            insert1(a[i]);
        for (int i = 50; i >= 0; i--)
            if ((ans ^ p[i]) > ans)
                ans = ans ^ p[i];
    }
    else
    {
        for (int i = 1; i <= n; i++)
            insert2(a[i]);
        for (int i = 50; i >= 0; i--)
            ans = ans ^ p[i];
    }
    cout << ans << endl;
}