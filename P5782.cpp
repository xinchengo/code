#include<stdio.h>
#include<string.h>
#define min(a,b) (((a)<(b))?(a):(b))
int n, m, a, b;
const int maxn = 8e3+7;
const int maxm = 2e4+7;
int head[maxn*2], nxt[maxm*4], to[maxm*4], cnt;
void add(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
int dfn[maxn*2], low[maxn*2], dcnt;
int s[maxn*2], ins[maxn*2], scnt;
int belong[maxn*2], bcnt;
void dfs(int u)
{
    dfn[u] = low[u] = ++dcnt;
    s[++scnt] = u;
    ins[u] = 1;
    for(int i=head[u];~i;i=nxt[i])
    {
        int v=to[i];
        if(!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        if(ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        bcnt++;
        while(s[scnt] != u)
            ins[s[scnt]] = 0, belong[s[scnt--]] = bcnt;
        ins[s[scnt]] = 0, belong[s[scnt--]] = bcnt;
    }
}
int main()
{
    bool flag = 1;
    memset(head,-1,sizeof(head));
    memset(to, -1, sizeof(to));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b),a--,b--;
        add(a,b^1),add(b,a^1);
    }
    for(int i=0;i<n*2;i++)
        if(!dfn[i])
            dfs(i);
    for(int i=0;i<n*2;i+=2)
        if(belong[i]==belong[i^1])
            flag = 0;
    if(flag)
    {
        for(int i=0;i<n*2;i+=2)
            if(belong[i]<belong[i^1])
                printf("%d\n",i+1);
            else
                printf("%d\n",(i^1)+1);
    }
    else
        puts("NIE");
}