#include <iostream>
using namespace std;
long long p[51], cnt;
char s[55];
void insert(long long x)
{
    for (int i = 50; i >= 0; i--)
        if (x >> i)
        {
            if (p[i] == 0)
            {
                p[i] = x;
                break;
            }
            x ^= p[i];
        }
}
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        long long num = 0;
        for (int j = 0; j < n; j++)
            num += (s[j] == 'X' ? 1 : 0) * (1LL << j);
        insert(num);
    }
    for (int i = 0; i <= 50; i++)
        if (p[i])
            cnt++;
    cout << (1LL << cnt) % 2008 << endl;
}