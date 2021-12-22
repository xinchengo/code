#include <iostream>
using namespace std;
int t, n, k;
long long x;
char s[2007];
int lim[2007], ac[2007], acnt;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> x;
        cin >> (s + 1);
        acnt = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] == '*' && s[i + 1] != '*')
            {
                acnt++;
                lim[acnt] = 1;
                ac[acnt] = 0;
                for (int j = i; s[j] == '*'; j--)
                    lim[acnt] += k;
            }
        int p = acnt;
        x--;
        while (x)
        {
            ac[p] = x % lim[p];
            x /= lim[p];
            p--;
        }
        p = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'a')
                cout << 'a';
            else if (s[i] == '*' && s[i + 1] != '*')
            {
                p++;
                for (int j = 1; j <= ac[p]; j++)
                    cout << 'b';
            }
        }
        cout << endl;
    }
}
