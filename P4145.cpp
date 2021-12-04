// Fear cuts deeper than swords.

#include<stdio.h>
#include<math.h>
using namespace std;
int n,m,k,l,r,t;
long long a[100007];
struct node
{
    long long sum;
}d[400007];
void build(int c,int cl,int cr)
{
    if(cl==cr)
    {
        d[c].sum=a[cl];
        return;
    }
    int cm=(cl+cr)>>1;
    build(c<<1,cl,cm);
    build((c<<1)|1,cm+1,cr);
    d[c].sum=d[c<<1].sum+d[(c<<1)|1].sum;
}
long long asksum(int c,int l,int r,int cl,int cr)
{
    if(l<=cl&&cr<=r)
    {
        return d[c].sum;
    }
    int cm=(cl+cr)>>1;
    long long s=0;
    if(l<=cm)
    {
        s+=asksum(c<<1,l,r,cl,cm);
    }
    if(cm<r)
    {
        s+=asksum((c<<1)|1,l,r,cm+1,cr);
    }
    return s;
}
void rsqrt(int c,int l,int r,int cl,int cr)
{
    if(cl==cr)
    {
        d[c].sum=(int)sqrt(d[c].sum);
        return;
    }
    if(d[c].sum==cr-cl+1)
    {
        return;
    }
    int cm=(cl+cr)>>1;
    if(l<=cm)
    {
        rsqrt(c<<1,l,r,cl,cm);
    }
    if(cm<r)
    {
        rsqrt((c<<1)|1,l,r,cm+1,cr);
    }
    d[c].sum=d[c<<1].sum+d[(c<<1)|1].sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&k,&l,&r);
        if(l>r)
        {
            t=l,l=r,r=t;
        }
        if(k==0)
        {
            rsqrt(1,l,r,1,n);
        }
        else
        {
            printf("%lld\n",asksum(1,l,r,1,n));
        }
    }
}