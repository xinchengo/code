#include <iostream>
using namespace std;
int t;
int n;
int a[107], u, ix;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        u = 1e9;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i1 = 0, v = 0; i1 <= 3; i1++)
            for (int i2 = 0; i2 <= 3; i2++, v = 0)
            {
                for (int k = 1, w = 1e9; k <= n; k++, w = 1e9)
                {
                    for (int j1 = 0; j1 <= i1; j1++)
                        for (int j2 = 0; j2 <= i2; j2++)
                            if (a[k] >= j1 + j2 * 2 && (a[k] - j1 - 2 * j2) % 3 == 0)
                                w = min(w, (a[k] - j1 - 2 * j2) / 3 + i1 + i2);
                    v = max(v, w);
                }
                u = min(u, v);
            }
        cout << u << endl;
    }
}
