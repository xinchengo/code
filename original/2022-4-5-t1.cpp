#include<iostream>
using namespace std;
const int maxn = 3e6+7;
unsigned n, K, X, v;
unsigned a[maxn], cnt, ans;
int main()
{
    scanf("%u %u %u",&n,&K,&X);
    a[1]=X;
    for(unsigned i=2;i<=n;i++)
        a[i] = (1145141U*a[i-1]+1919U*i+810U);
    K--;
    for(unsigned p=0;p<32;p++)
        if((1U<<p)&K)
            for(unsigned i=1;i<=n-(1U<<p);i++)
                a[i]^=a[i+(1U<<p)];
    for(unsigned i=1;i<=n-K;i++)
        ans+=i*(a[i]^i);
    printf("%u\n",ans);
}