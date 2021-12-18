#include <algorithm>
#include <iostream>
using namespace std;
int n;
pair<int, long long> a[1007];
long long p[1007], ans, sum;
void insert(pair<int, long long> x)
{
    long long v = x.second;
    for (int i = 60; i >= 0; i--)
        if (v >> i)
        {
            if (p[i] == 0)
            {
                p[i] = v;
                ans += x.first;
                break;
            }
            v ^= p[i];
        }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--)
        insert(a[i]);
    cout << ans << endl;
}