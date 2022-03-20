#include<iostream>
using namespace std;
const int maxn = 5e4+7, maxm = 1e5+7, maxk = 5e2+7;
int n, k;
int head[maxn], nxt[maxm], to[maxm], ecnt;
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int siz[maxn], heavy[maxn], dep[maxn];
void predfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v != fa)
        {
            predfs(v, u);
            siz[u] += siz[v];
            if(!heavy[u] || siz[heavy[u]] < siz[v])
                heavy[u] = v;
        }
    }
}
bool inc[maxn];
int dis[maxn];
unsigned long long ans;
void calc(int u, int fa, int top, int add)
{
    if(add == 1 || add == -1)
        dis[dep[u]]+=add;
    else if(k - dep[u] + 2*dep[top] >= 0)
        ans += dis[k - dep[u] + 2*dep[top]];
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(!inc[v] && v != fa)
            calc(v, u, top, add);
    }   
}
void dfs(int u, int fa, bool keep)
{
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v != heavy[u] && v != fa)
            dfs(v, u, false);
    }
    if(heavy[u])
    {
        dfs(heavy[u], u, true);
        inc[heavy[u]] = true;
    }
    ans += dis[k + dep[u]];
    dis[dep[u]]++;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v != heavy[u] && v != fa)
            calc(v,u,u,0), calc(v, u,u, 1);
    }
    if(heavy[u])
        inc[heavy[u]] = false;
    if(keep == false)
        calc(u, fa,u, -1);
}
int main()
{
    cin >> n >> k;
    int a, b;
    for(int i=1;i<n;i++)
    {
        cin >> a >> b;
        add(a,b), add(b,a);
    }
    predfs(1,0);
    dfs(1,0,false);
    cout << ans << endl;
}