#include <iostream>
using namespace std;
const int maxk = 16;
const int maxn = 1e6;
int k, n;
int c[maxk + 7], a[maxn + 7];
int s[maxn + 7];
int sum(int l, int r)
{
    return s[r] - s[l - 1];
}
int main()
{
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        int r = 1;
        for (int l = 1; l <= n; k++)
        {
            while(sum(l,r)<=
        }
    }
}
