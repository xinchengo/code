// Fear cuts deeper than swords.

#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int m[105], n[105], s2[335][105], b[335], ans[105], len, b1[335], b2[335];
void clear(int x[])
{
    for(int i=0;i<=103;i++)
        x[i] = 0;
}
void read(int x[])
{
    static char t[105];
    scanf("%s",t);
    clear(x);
    int l=strlen(t);
    for(int i=0;i<l;++i)
        x[l-i-1]=t[i]-'0';
}
void print(int x[])
{
    int p=103;
    for(;p>=1;--p)
        if(x[p]!=0)
            break;
    for(;p>=0;--p)
        putchar(x[p]+'0');
}
void mul2(int to[], int a[])
{
    clear(to);
    for(int i=0;i<=103;i++)
    {
        to[i] += a[i] + a[i];
        if(to[i] >= 10)
            to[i+1]+=1, to[i]-=10;
    }
}
void add(int to[], int a[])
{
    static int b[105];
    clear(b);
    for(int i=0;i<=103;i++)
        b[i] = to[i];
    clear(to);
    for(int i=0;i<=103;i++)
    {
        to[i] += a[i] + b[i];
        if(to[i] >= 10)
            to[i+1]+=1, to[i]-=10;
    }
}
void div(int a[], int p)
{
    static int c[105];
    clear(c);
    for(int i=103,r=0;i>=0;i--)
        c[i]=(a[i]+r)/p, r=((a[i]+r)%p)*10;
    for(int i=103,r=0;i>=0;i--)
        a[i]=c[i];
}
bool gre(int a[], int b[])
{
    for(int i=0;i<=334;i++)
    {
        if(a[i] < b[i])
            return 0;
        if(a[i] > b[i])
            return 1;
    }
    return 1;
}
int main()
{
    s2[0][0] = 1;
    for(int i=1;i<=334;i++)
        mul2(s2[i],s2[i-1]);
    read(m);
    b[0]=(m[0]&1);
    for(int i=1;i<=334;i++)
        div(m,2),b[i]=(m[0]&1);
    len = 334;
    while(b[len]==0)len--;
    for(int i=0;i<len;i++)
        add(ans,s2[i/2]);
    for(int i=0;i<=len/2;i++)
        b2[len/2-i]=b[i];
    for(int i=(len+1)/2;i<=len;i++)
        b1[i-(len+1)/2]=b[i];
    if(gre(b2,b1))
    {
        add(ans,s2[0]);
    }
    int p = len;
    while(b1[p]==0)p--;
    for(int i=0;i<p;i++)
        if(b1[i])
            add(ans,s2[i]);
    print(ans);
}