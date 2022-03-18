#include <algorithm>
#include <iostream>
using namespace std;
unsigned long long t, n;
unsigned long long k;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%llu %llu", &n, &k);
        k--;
        if (n <= 60 && k >> n - 1)
        {
            puts("-1");
            continue;
        }
        for (unsigned long long l = 1, r = 1; l <= n && r <= n; r++, l = r)
        {
            while (r < n && n - r <= 60 && (k >> (n - r - 1)) & 1)
                r++;
            for (unsigned long long i = r; i >= l; i--)
                printf("%llu ", i);
        }
        printf("\n");
    }
}