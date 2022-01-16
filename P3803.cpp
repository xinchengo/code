#include<iostream>
#include<cmath>
#include<complex>
#include<algorithm>
using namespace std;
using ld = long double;
using cl = complex<ld>;
const ld pi = acos(-1.0l);
const int maxn = 0x200000;
int len, rev[maxn+7];
void init(int n)
{
    len = 1;
    while(len <= n)
        len <<= 1;
    for(int i=0;i<len;i++)
    {
        rev[i] = rev[i>>1]>>1;
        if(i & 1)
            rev[i] |= len >> 1;
    }
}
void change(cl *a)
{
    for(int i=0;i<len;i++)
        if(i < rev[i])
            swap(a[i], a[rev[i]]);
}
void dft(cl *a)
{
    change(a);
    for(int bl = 2; bl <= len; bl<<=1)
    {
        cl wn(cos(2*pi/bl),sin(2*pi/bl));
        for(int s = 0; s < len; s += bl)
        {
            cl w(1,0);
            for(int i = s; i < s + bl / 2; i++)
            {
                cl g = a[i], t = w * a[i + bl/2];
                a[i] = g + t, a[i + bl/2] = g - t;
                w *= wn;
            }
        }
    }
}
void idft(cl *a)
{
    change(a);
    for(int bl = 2; bl <= len; bl<<=1)
    {
        cl wn(cos(2*pi/bl),sin(-2*pi/bl));
        for(int s = 0; s < len; s += bl)
        {
            cl w(1,0);
            for(int i = s; i < s + bl / 2; i++)
            {
                cl g = a[i], t = w * a[i + bl/2];
                a[i] = g + t, a[i + bl/2] = g - t;
                w *= wn;
            }
        }
    }
    for(int i=0;i<len;i++)
        a[i] /= len;
}
int n, m;
ld t;
cl f[maxn+7], g[maxn+7], ans[maxn+7];
int main()
{
    cin >> n >> m;
    init(n+m);
    for(int i=0;i<=n;i++)
        cin >> t, f[i].real(t);
    for(int i=0;i<=m;i++)
        cin >> t, g[i].real(t);
    dft(f);
    dft(g);
    for(int i=0;i<len;i++)
        ans[i] = f[i] * g[i];
    idft(ans);
    for(int i=0;i<=n+m;i++)
        cout << (int)round(ans[i].real()) << ' ';
    cout << endl;
}