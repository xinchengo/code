#include <iostream>
using namespace std;
const int mod = 998244353;
int n, k;
char a[5007];
int c[5007][5007];
int s[5007];
int ans = 1;
int count(int l, int r)
{
    return s[r] - s[l - 1];
}
int main()
{
    for (int i = 0; i <= 5001; i++)
        c[i][0] = 1, c[i][i] = 1;
    for (int i = 1; i <= 5001; i++)
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    cin >> n >> k;
    cin >> (a + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + (a[i] - '0');
    for (int l = 1; l <= n; l++)
        for (int r = l + 1; r <= n; r++)
            if (count(l, r) <= k && count(1, n) >= k)
            {
                int ones = count(l, r);
                ones -= (a[l] == '1' ? 0 : 1) + (a[r] == '1' ? 0 : 1);
                if (ones <= r - l - 1 && ones >= 0)
                    ans = (ans + c[r - l - 1][ones]) % mod;
            }
    cout << ans << endl;
}