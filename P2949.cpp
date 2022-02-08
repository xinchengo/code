#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e5 + 7;
struct job
{
    int d, p;
    bool operator<(const job &b) const
    {
        return d < b.d;
    }
} a[maxn];
priority_queue<int> q;
int n;
long long ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].d >> a[i].p;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].d > q.size())
        {
            q.push(-a[i].p);
            ans += a[i].p;
        }
        else
        {
            if (a[i].p > -q.top())
            {
                ans += q.top();
                q.pop();
                q.push(-a[i].p);
                ans += a[i].p;
            }
        }
    }
    cout << ans << endl;
}