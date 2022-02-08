#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1.5e5 + 7;
struct job
{
    int l, t;
    bool operator<(const job &b) const
    {
        return l < b.l;
    }
} a[maxn];
int n;
int ans, t;
priority_queue<int> q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].t >> a[i].l;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (t + a[i].t <= a[i].l)
        {
            q.push(a[i].t);
            t += a[i].t;
            ans++;
        }
        else
        {
            if (a[i].t < q.top())
            {
                t -= q.top();
                q.pop();
                q.push(a[i].t);
                t += a[i].t;
            }
        }
    }
    cout << ans << endl;
}