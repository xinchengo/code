// Fear cuts deeper than swords.

#include<stdio.h>
#include<iostream>
using namespace std;
#define int long long
int a[103], n, m, anss[1000003], cnt;
const int p = 1e8+7;
char buf;
int read()
{
    int flag = 1;
    int res = 0;
    while(buf < '0' || buf > '9')
    {
        if(buf == '-')
            flag = -1;
        buf = getc(stdin);
    }
    while(buf >= '0' && buf <= '9')
    {
        res = ( (res * 10) + (buf - '0') ) % p;
        buf = getc(stdin);
    }
    return res * flag;
}
bool getv(int x)
{
    int val = 0;
    for(int i=n;i>=0;i--)
        val = ( (a[i] + val) * x ) % p;
    return !val;
}
signed main()
{
    n = read();
    m = read();
    buf = getc(stdin);
    for(int i=0;i<=n;i++)
    {
        a[i] = read();
    }
    for(int i=1;i<=m;i++)
    {
        if(getv(i))
            anss[++cnt] = i;
    }
    cout << cnt << endl;
    for(int i=1;i<=cnt;i++)
    {
        cout << anss[i] << endl;
    }
}