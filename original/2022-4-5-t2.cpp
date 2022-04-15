#include<iostream>
using namespace std;
const int maxn = 1e5+7;
const int mod = 998244353;
int head[maxn], nxt[maxn<<1], to[maxn<<1], ecnt;
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int n, pow2[maxn];
int siz[maxn], ans[maxn];
void dfs(int u, int fa)
{
    siz[u] = 1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v!=fa)
        {
            dfs(v, u);
            ans[u] = (0LL + ans[u] + (1LL * (pow2[siz[v]]-1) * (pow2[siz[u]-1]-1)) % mod) % mod;
            siz[u] += siz[v];
        }
    }
    ans[u] = (ans[u] + pow2[siz[u]-1]) % mod;
}
int main()
{
    scanf("%d",&n);
    int u, v;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    pow2[0]=1;
    for(int i=1;i<=n;i++)
        pow2[i]=(1LL*pow2[i-1]*2)%mod;
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
}