#include<iostream>
#include<algorithm>
using namespace std;
long long n, a[100007], cnt[20000007], f[20000007], mx, ans;
long long primes[20000007], vis[20000007], pnt=1;
void eratothenes(int n)
{
    primes[1] = 2;
    for(int i=3,j=3;i<=n;i+=2,j=i)
    {
        if(vis[i>>1])
            continue;
        primes[++pnt] = i;
        for(;j<=n;j+=(i<<1))
            vis[j>>1] = 1;
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i], cnt[a[i]]++, mx=max(mx,a[i]);
    eratothenes(mx);
    for(int i=1;i<=pnt;i++)
        for(int j=mx/primes[i];j>=1;j--)
            cnt[j] += cnt[j*primes[i]];
    for(int i=mx;i>=1;i--)
    {
        f[i] = cnt[i] * i;
        for(int j=1;i*primes[j]<=mx;j++)
            f[i] = max(f[i], f[i*primes[j]] + (cnt[i] - cnt[i*primes[j]]) * i);
    }
    for(int i=1;i<=mx;i++)
        ans = max(f[i], ans);
    cout << ans << endl;
}