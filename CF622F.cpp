// Fear cuts deeper than swords.

#include<stdio.h>
const long long mod=1e9+7;
long long n,k,y[1000007],a,b,ans,p[1000007],n_[1000007],n__[1000007];
long long pow(long long b,long long k)
{
    long long ans=1LL;
    while(k)
    {
        if(k&1)
        {
            ans=ans*b%mod;
        }
        b=b*b%mod;
        k>>=1;
    }
    return ans;
}
long long inv(long long x)
{
    return pow(x,mod-2);
}
int main()
{
    scanf("%lld%lld",&n,&k);
    y[1]=1;
    for(long long i=2;i<=k+2;i++)
    {
        y[i]=(y[i-1]+pow(i,k))%mod;
    }
    if(n<=k+2)
    {
        printf("%lld\n",y[n]);
    }
    else
    {
        p[0]=1;
        for(int i=1;i<=k+1;i++)
        {
            p[i]=p[i-1]*i%mod;
        }
        n_[0]=1;
        for(int i=1;i<=k+1;i++)
        {
            n_[i]=n_[i-1]*(n-i)%mod;
        }
        n__[k+3]=1;
        for(int i=k+2;i>=1;i--)
        {
            n__[i]=n__[i+1]*(n-i)%mod;
        }
        for(long long i=1;i<=k+2;i++)
        {
            a=(((y[i]%mod)*n_[i-1]%mod)*n__[i+1])%mod,b=(((k-i+2)&1)?-1:1)*p[i-1]*p[k-i+2]%mod;
            ans+=a*inv(b)%mod;
        }
        printf("%lld\n",(ans%mod+mod)%mod);
    }
}