#include <iostream>
using namespace std;
int f[11][10];
bool check(int a, int b)
{
    if (a - b == 1 || a == b || a - b == -1)
        return 0;
    else
        return 1;
}
int a, b, t1, t2;
int calc(int x)
{
    int num[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cnt = 0, t = x;
    int ans = 0;
    while (t)
        num[++cnt] = t % 10, t /= 10;
    // shorter
    for (int l = cnt - 1; l >= 1; l--)
        for (int h = 1; h < 10; h++)
            ans += f[l][h];
    // smaller on each digit
    for (int h = 1; h < num[cnt]; h++)
        ans += f[cnt][h];
    for (int l = cnt; l >= 2; l--)
    {
        for (int h = 0; h < num[l - 1]; h++)
            if (check(num[l], h))
                ans += f[l - 1][h];
        if (!check(num[l], num[l - 1]))
            break;
    }
    return ans;
}
int main()
{
    for (int h = 0; h < 10; h++)
        f[1][h] = 1;
    for (int l = 2; l <= 10; l++)
        for (int h = 0; h < 10; h++)
            for (int p = 0; p < 10; p++)
                if (check(h, p))
                    f[l][h] += f[l - 1][p];
    cin >> t1 >> t2;
    a = min(t1, t2), b = max(t1, t2);
    cout << calc(b + 1) - calc(a) << endl;
}
