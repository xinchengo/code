#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
ll n, m, a[41], p[1048577], q[1048577], pcnt=0, qcnt=0, mid, ans=0;
void dfs(int index,int range, ll lim, ll sum, ll* s, ll& cnt)
{
    if(sum > lim)
        return;
    if(index > range){
        s[++cnt]=sum;return;}
    dfs(index+1,range,lim,sum+a[index],s,cnt);
    dfs(index+1,range,lim,sum,s,cnt);
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    mid=(n+1)/2;
    dfs(1,mid,m,0,p,pcnt);
    dfs(mid+1,n,m,0,q,qcnt);
    sort(p+1,p+pcnt+1);
    sort(q+1,q+qcnt+1);
    int curp = pcnt;
    for(int curq = 1;curq <= qcnt;curq++)
    {
        while(q[curq] + p[curp] > m)
            curp--;
        if(q[curq] + p[curp] <= m)
            ans += curp;
    }
    cout << ans << endl;
}