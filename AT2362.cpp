#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5+7;
const int maxd = 1e1+7;
int n, m, q;
int a[maxn], b[maxn];
int f[maxd][maxn];
int v, d, c[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&a[i],&b[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&v,&d,&c[i]);
        f[d][v] = i;
    }
    for(int i=10;i>0;i--)
        for(int j=1;j<=m;j++)
        {
            f[i-1][b[j]] = max(f[i-1][b[j]], f[i][a[j]]);
            f[i-1][a[j]] = max(f[i-1][a[j]], f[i][b[j]]);
        }
    for(int i=10;i>0;i--)
        for(int j=1;j<=n;j++)
            f[i-1][j] = max(f[i-1][j], f[i][j]);
    for(int i=1;i<=n;i++)
    {
        printf("%d\n", c[f[0][i]]);
    }
}