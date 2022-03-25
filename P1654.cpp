#include <iomanip>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 7;
int n;
double p[maxn], a[maxn], b[maxn], c[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
    {
        c[i] = (c[i - 1] + 1) * p[i];
        b[i] = (b[i - 1] + 2 * c[i - 1] + 1) * p[i];
        a[i] = a[i - 1] + (3 * b[i - 1] + 3 * c[i - 1] + 1) * p[i];
    }
    cout << fixed << setprecision(1) << a[n] << endl;
}