#include <iostream>
using namespace std;
int n, k, flag;
int main()
{
    scanf("%d%d", &n, &k);
    if (k == 1)
    {
        printf("%c", '1');
        for (int i = 2; i <= n; i++)
            printf("%c", '0');
    }
    else if (k == 2)
    {
        int s=0,i=1;
        for(i=1;s<n;i++)
            s+=i;
        i--,s-=i;
        putc('1',stdout);
        for(int j=1;j<=i;j++)
            printf("%c", (i+1-n+s==j)+'0');
    }
    else if (k == 3)
    {
        int s=0,i=2;
        for(i=2;s<n;i++)
            s+=i*(i-1)/2;
        i--,s-=i*(i-1)/2;
        int nn=n-s,ns=0,j=1;
        for(j=1;ns<nn;j++)
            ns+=j;
        j--,ns-=j;
        putc('1',stdout);
        for(int k=1;k<=i-j-1;k++)
            printf("%c", '0');
        putc('1',stdout);
        for(int k=1;k<=j;k++)
            printf("%c", (j+1-nn+ns==k)+'0');
    }
    else
    {
        unsigned long long x = (1ULL << k) - 1ULL, t;
        for (int i = 2; i <= n; i++)
        {
            t = x + (x & -x);
            x = t | ((((t & -t) / (x & -x)) >> 1ULL) - 1ULL);
        }
        for (int i = 63; i >= 0; i--)
        {
            if (x & (1ULL << i))
                flag = 1;
            if (flag)
            {
                printf("%c", char(((x >> i) & 1ULL) + '0'));
            }
        }
        printf("\n");
    }
}