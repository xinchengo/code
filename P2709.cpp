// Fear cuts deeper than swords.

#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int n,m,bs,k,a[50007],ans[50007],v[50007],cur;
struct query
{
    int l,r,id;
    bool operator<(const query &b)const
    {
        if(l/bs!=b.l/bs)
            return l<b.l;
        return ((l/bs)&1)?r<b.r:r>b.r;
    }
}q[50007];
void widen(int x)
{
    cur-=v[x]*v[x];
    v[x]++;
    cur+=v[x]*v[x];
}
void narrow(int x)
{
    cur-=v[x]*v[x];
    v[x]--;
    cur+=v[x]*v[x];
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    bs=sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    for(int i=1,l=1,r=0;i<=m;i++)
    {
        while(l>q[i].l)widen(a[--l]);
        while(r<q[i].r)widen(a[++r]);
        while(l<q[i].l)narrow(a[l++]);
        while(r>q[i].r)narrow(a[r--]);
        ans[q[i].id]=cur;
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
}
