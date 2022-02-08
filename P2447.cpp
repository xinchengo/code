#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
int n, m, c, k, flag = 1;
string s;
bitset<1001> a[2000];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = (s[j] - '0');
        cin >> s;
        a[i][n] = (s[0] - '0');
    }
    for (int i = 0; i < n; i++)
    {
        c = i;
        while (c < m && a[c][i] == 0)
            c++;
        if (c == m)
        {
            flag = 0;
            break;
        }
        k = max(c + 1, k);
        swap(a[i], a[c]);
        for (int j = 0; j < m; j++)
            if (j != i && a[j][i])
                a[j] ^= a[i];
    }
    if (flag == 0)
        cout << "Cannot Determine" << endl;
    else
        for (cout << k << endl, flag = 0; flag < n; flag++)
            cout << (a[flag][n] ? "?y7M#" : "Earth") << endl;
}