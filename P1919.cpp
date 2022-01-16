#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
using namespace std;
using fl = double;
using cf = complex<fl>;
const int maxn = 0x200007;
const fl pi = acos(-1.0);
int rev[maxn], len;
void init(int n)
{
    len = 1;
    while (len <= n)
        len <<= 1;
    for (int i = 0; i < len; i++)
    {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1)
            rev[i] |= len >> 1;
    }
}
void change(cf *a)
{
    for (int i = 0; i < len; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
}
void fft(cf *a, int mode)
{
    change(a);
    for (int bs = 2; bs <= len; bs <<= 1)
    {
        cf wn(cos(2 * pi / bs), sin(2 * mode * pi / bs));
        for (int s = 0; s < len; s += bs)
        {
            cf w(1, 0);
            for (int i = s; i < s + bs / 2; i++)
            {
                cf g = a[i], h = w * a[i + bs / 2];
                a[i] = g + h, a[i + bs / 2] = g - h;
                w *= wn;
            }
        }
    }
    if (mode == -1)
        for (int i = 0; i < len; i++)
            a[i] /= len;
}
cf a[maxn], b[maxn];
char t;
int al, bl, ans[maxn], r;
int main()
{
    t = getc(stdin);
    while (t < '0' || t > '9')
        t = getc(stdin);
    while (t >= '0' && t <= '9')
    {
        a[al++].real(t - '0');
        t = getc(stdin);
    }
    while (t < '0' || t > '9')
        t = getc(stdin);
    while (t >= '0' && t <= '9')
    {
        b[bl++].real(t - '0');
        t = getc(stdin);
    }
    reverse(a, a + al);
    reverse(b, b + bl);
    init(al + bl);
    fft(a, 1);
    fft(b, 1);
    for (int i = 0; i < len; i++)
        a[i] *= b[i];
    fft(a, -1);
    for (int i = 0; i < len; i++)
        ans[i] = round(a[i].real());
    for (int i = 0; i < len; i++)
        if (ans[i] >= 10)
            ans[i + 1] += ans[i] / 10, ans[i] %= 10;
    r = maxn - 1;
    while (!ans[r] && r > 0)
        r--;
    for (int i = r; i >= 0; i--)
        putc(ans[i] + '0', stdout);
    putc('\n', stdout);
}