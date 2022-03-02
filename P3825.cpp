#include<iostream>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;
const int maxn = 5e4+7, maxm = 1e5+7;
char S[maxn];
int n, d, m;
int head[maxn*2], nxt[maxm*2], to[maxm*2], cnt;
struct sat
{
    int i, j;
    char hi, hj;
}q[maxm];
void add(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
int anti(int u)
{
    if(u > n)
        return u-n;
    else
        return u+n;
}
int id(int u, char c)
{
    if(c == ((S[u] == 'a') ? 'b' : 'a'))
        return u;
    return u + n;
}
int dfn[maxn*2], low[maxn*2], dcnt;
int s[maxn*2], belong[maxn*2], bcnt, scnt, ins[maxn*2];
void dfs(int u)
{
    dfn[u] = low[u] = ++dcnt;
    s[++scnt] = u;
    ins[u] = 1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        if(ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        ++bcnt;
        while(s[scnt] != u)
            ins[s[scnt]]=0, belong[s[scnt--]] = bcnt;
        ins[s[scnt]]=0, belong[s[scnt--]] = bcnt;
    }
}
int solve()
{
    cnt = 0, dcnt = 0, bcnt = 0, scnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(s, 0, sizeof(s));
    memset(belong, 0, sizeof(belong));
    memset(head, 0, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    for(int i=1;i<=m;i++)
    {
        if(q[i].i == q[i].j && q[i].hi == q[i].hj)
            continue;
        if(q[i].hi == S[q[i].i])
            continue;
        int id1 = id(q[i].i, q[i].hi), id2 = id(q[i].j, q[i].hj);
        if(q[i].hj == S[q[i].j])
            add(id1, anti(id1));
        else
            add(id1, id2), add(anti(id2), anti(id1));
    }
    for(int i=1;i<=n*2;i++)
        if(!dfn[i])
            dfs(i);
    for(int i=1;i<=n;i++)
    {
        if(belong[i] == belong[anti(i)])
            return 0;
    }
    return 1;
}
int xpos[9], xcnt;
bool flag;
int main()
{
    scanf("%d %d\n%s\n%d",&n,&d,S+1,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %c %d %c",&(q[i].i),&(q[i].hi),&(q[i].j),&(q[i].hj));
        q[i].hi += 32, q[i].hj += 32;
    }
    for(int i=1;i<=n;i++)
        if(S[i] == 'x')
            xpos[xcnt++] = i;
    for(int i=0;i<(1<<d);i++)
    {
        for(int j=0;j<d;j++)
            if(i&(1<<j))
                S[xpos[j]] = 'a';
            else
                S[xpos[j]] = 'b';
        flag = flag || solve();
        if(flag)
            break;
    }
    if(flag)
        for(int i=1;i<=n;i++)
            printf("%c",(belong[i]<belong[anti(i)])?((S[i]=='a')?'B':'A'):((S[i]=='c')?'B':'C'));
    else
        puts("-1\n");
}