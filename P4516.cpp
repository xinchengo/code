#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n, k;
int u, v;
vector<int> g[100007];
int f[100007][105][2][2];
int f2[105][2][2];
int t[100007];
int add(int a, int b)
    {return ((long long)a + (long long)b)%1000000007;}
int mul(int a, int b)
    {return ((long long)a * (long long)b)%1000000007;}
void predfs(int cur, int fa)
{
    for(auto &nxt:g[cur])
    {
        if(nxt != fa)
            predfs(nxt, cur);
        else
            nxt=g[cur].back(), g[cur].pop_back();
    }
}
void dfs(int cur)
{
    t[cur] = 1;
    f[cur][1][1][0] = 1, f[cur][0][0][0] = 1;
    for(auto nxt:g[cur])
    {
        dfs(nxt);
        for(int i=0;i<=min(t[cur],k);i++)
            f2[i][0][0]=f[cur][i][0][0],f2[i][0][1]=f[cur][i][0][1],f2[i][1][0]=f[cur][i][1][0],f2[i][1][1]=f[cur][i][1][1];
        for(int i=0;i<=min(t[cur],k);i++)
            f[cur][i][0][0]=0,f[cur][i][0][1]=0,f[cur][i][1][0]=0,f[cur][i][1][1]=0;
        for(int i=0;i<=min(t[cur],k);i++)
            for(int j=0;j<=min(t[nxt],k-i);j++)
        {
            f[cur][i+j][0][0] = add(f[cur][i+j][0][0], mul(f2[i][0][0], f[nxt][j][0][1]));
            f[cur][i+j][0][1] = add(f[cur][i+j][0][1], add( mul(f2[i][0][0], f[nxt][j][1][1]),
                                                        mul(f2[i][0][1], add(f[nxt][j][0][1], f[nxt][j][1][1]))));
            f[cur][i+j][1][0] = add(f[cur][i+j][1][0], mul(f2[i][1][0], add(f[nxt][j][0][0], f[nxt][j][0][1])));
            f[cur][i+j][1][1] = add(f[cur][i+j][1][1], add( mul(f2[i][1][0], add(f[nxt][j][1][0], f[nxt][j][1][1])),
                                                        mul(f2[i][1][1], add(add(f[nxt][j][0][0], f[nxt][j][0][1]),
                                                                                   add(f[nxt][j][1][0], f[nxt][j][1][1])))));
        }
        t[cur] += t[nxt];
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    predfs(1, -1);
    dfs(1);
    printf("%d\n",f[1][k][0][1]+f[1][k][1][1]);
}
