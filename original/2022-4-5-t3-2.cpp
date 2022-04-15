#include<iostream>
using namespace std;
const int maxn = 200000;
int head[maxn], nxt[maxn<<1], to[maxn<<1], ecnt;
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int m, n;
int col[maxn], val[maxn];
int fa[maxn], dep[maxn];
void predfs(int u)
{
    dep[u] = dep[fa[u]] + 1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(v != fa[u])
        {
            fa[v] = u;
            predfs(v);
        }
    }
}
int ask(int u, int fa)
{
    int maxv = val[u];
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(col[v] == col[u] && v != fa)
            maxv = max(maxv, ask(v, u));
    }
    return maxv;
}
void add(int u, int fa, int k)
{
    val[u]+=k;
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(col[v] == col[u] && v != fa)
            add(v,u,k);
    }
}
void addc(int u, int v, int k)
{
    if(dep[v] < dep[u])
        swap(u, v);
    while(dep[v] > dep[u])
    {
        val[v] += k;
        v = fa[v];
    }
    while(u != v)
    {
        val[u] += k, val[v] += k;
        u=fa[u], v=fa[v];
    }
    val[u]+=k;
}
void adds(int u, int k)
{
    val[u]+=k;
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(v != fa[u])
            adds(v,k);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int u, v, k;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&col[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    predfs(1);
    //if(n <= 1000 && m <= 1000)
    //{
        int oper;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&oper);
            if(oper == 1)
            {
                scanf("%d",&u);
                col[u] = !col[u];
            }
            else if(oper == 2)
            {
                scanf("%d%d",&u,&v);
                add(u,0,v);
            }
            else if(oper == 3)
            {
                scanf("%d",&u);
                printf("%d\n",ask(u,0));
            }
            else if(oper == 4)
            {
                scanf("%d%d%d",&u,&v,&k);
                addc(u, v, k);
            }
            else
            {
                scanf("%d%d",&u,&v);
                adds(u, v);
            }
        }
    //}
}