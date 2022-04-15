#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2e5;
int head[maxn], to[maxn<<1], nxt[maxn<<1], ecnt;
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int n, m;
int col[maxn], val[maxn];
int mcol[maxn], mval[maxn], pl[maxn], pr[maxn];
int siz[maxn], heavy[maxn];
int predfs(int u, int fa)
{
    siz[u] = 1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(v != fa)
        {
            predfs(v, u);
            siz[u] += siz[v];
            if(!heavy[u] || siz[v] > siz[heavy[u]])
                heavy[u] = v;
        }
    }
}
int mapped[maxn], mcnt, belong[maxn], bcnt, rl[maxn], rr[maxn];
int bf[maxn];
int dfs(int u, int fa)
{
    mapped[u] = ++mcnt;
    if(heavy[fa] != u)
    {
        rl[++bcnt]=mcnt;
        bf[bcnt] = mapped[fa];
    }
    belong[mcnt] = bcnt;
    rr[bcnt]=mcnt;
    if(heavy[u])
        dfs(heavy[u], u);
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(v != fa && v != heavy[u])
            dfs(v,u);
    }
}
struct node
{
    int val, lr, rr;
    int lzadd, lzl, lzr;
}d[maxn<<2];
void build(int id, int rl, int rr)
{
    if(rl == rr)
    {
        d[id].val = mval[rl];
        d[id].lr = pl[rl];
        d[id].rr = pr[rl];
        d[id].lzl = -1;
        d[id].lzr = -1;
        return;
    }
    int rm = (rl + rr) >> 1;
    build(id<<1,rl,rm);
    build((id<<1)|1,rm+1,rr);
    d[id].val = max(d[id<<1].val, d[(id<<1)|1].val);
}
void add(int id, int rl, int rr, int l, int r, int k)
{
    if(l <= rl && rr <= r)
    {
        d[id].val += k;
        d[id].lzadd += k;
        return;
    }
    int rm = (rl + rr) >> 1;
    if(d[id].lzadd)
    {
        d[id<<1].lzadd += d[id].lzadd;
        d[id<<1].val += d[id].lzadd;
        d[(id<<1)|1].lzadd += d[id].lzadd;
        d[(id<<1)|1].val += d[id].lzadd;
        d[id].lzadd = 0;
    }
    if(l <= rm) add(id<<1, rl, rm, l, r, k);
    if(rm < r) add(id<<1|1,rm+1,rr,l, r, k);
    d[id].val = max(d[id<<1].val, d[id<<1|1].val);
}
void setl(int id, int rl, int rr, int l, int r, int k)
{
    if(l <= rl && rr <= r)
    {
        d[id].lr = k;
        d[id].lzl = k;
        return;
    }
    int rm = (rl + rr) >> 1;
    if(~d[id].lzl)
    {
        d[id<<1].lzl = d[id].lzl;
        d[id<<1].lr = d[id].lzl;
        d[id<<1|1].lzl = d[id].lzl;
        d[id<<1|1].lr = d[id].lzl;
        d[id].lzl = -1;
    }
    if(l <= rm) setl(id<<1,rl,rm,l,r,k);
    if(rm < r) setl(id<<1|1,rm+1,rr,l,r,k);
}
void setr(int id, int rl, int rr, int l, int r, int k)
{
    if(l <= rl && rr <= r)
    {
        d[id].rr = k;
        d[id].lzl = k;
        return;
    }
    int rm = (rl + rr) >> 1;
    if(~d[id].lzr)
    {
        d[id<<1].lzr = d[id].lzr;
        d[id<<1].rr = d[id].lzr;
        d[id<<1|1].lzr = d[id].lzr;
        d[id<<1|1].rr = d[id].lzr;
        d[id].lzr = -1;
    }
    if(l <= rm) setl(id<<1,rl,rm,l,r,k);
    if(rm < r) setl(id<<1|1,rm+1,rr,l,r,k);
}
int askmax(int id, int rl, int rr, int l, int r)
{
    if(l <= rl && rr <= r)
        return d[id].val;
    int rm = (rl + rr) >> 1;
    if(d[id].lzadd)
    {
        d[id<<1].lzadd += d[id].lzadd;
        d[id<<1].val += d[id].lzadd;
        d[(id<<1)|1].lzadd += d[id].lzadd;
        d[(id<<1)|1].val += d[id].lzadd;
        d[id].lzadd = 0;
    }
    int ans = 0;
    if(l <= rm) ans = max(ans, askmax(id<<1,rl,rm,l,r));
    if(rm < r) ans = max(ans, askmax(id<<1|1,rm+1,rr,l,r));
    return ans;
}
int askl(int id, int rl, int rr, int x)
{
    if(rl == rr)
        return d[id].lr;
    int rm = (rl + rr) >> 1;
    if(~d[id].lzl)
    {
        d[id<<1].lzl = d[id].lzl;
        d[id<<1].lr = d[id].lzl;
        d[id<<1|1].lzl = d[id].lzl;
        d[id<<1|1].lr = d[id].lzl;
        d[id].lzl = -1;
    }
    if(x <= rm) return askl(id<<1,rl,rm,x);
    else    return askl(id<<1|1,rm+1,rr,x);
}
int askr(int id, int rl, int rr, int x)
{
    if(rl == rr)
        return d[id].rr;
    int rm = (rl + rr) >> 1;
    if(~d[id].lzr)
    {
        d[id<<1].lzr = d[id].lzr;
        d[id<<1].rr = d[id].lzr;
        d[id<<1|1].lzr = d[id].lzr;
        d[id<<1|1].rr = d[id].lzr;
        d[id].lzr = -1;
    }
    if(x <= rm) return askr(id<<1,rl,rm,x);
    else    return askr(id<<1|1,rm+1,rr,x);
}
int main()
{
    scanf("%d%d",&n,&m);
    int u, v;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&col[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    predfs(1,0);
    dfs(1,0);
    for(int i=1;i<=n;i++)
        mcol[mapped[i]] = col[i];
    for(int i=1;i<=n;i++)
        mval[mapped[i]] = val[i];
    for(int i=1;i<=bcnt;i++)
    {
        pl[rl[i]]=rl[i];
        for(int j=rl[i]+1;j<=rr[i];j++)
        {
            if(mcol[j] == mcol[j-1])
                pl[j] = pl[j-1];
            else
                pl[j] = j;
        }
        pr[rr[i]]=rr[i];
        for(int j=rr[i]-1;j>=rl[i];j--)
        {
            if(mcol[j] == mcol[j+1])
                pr[j] = pr[j+1];
            else
                pr[j] = j;
        }
    }
    build(1,1,n);
    int oper, c;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&oper);
        if(oper == 1)
        {
            scanf("%d",&c);
            int mc = mapped[c], lm = mapped[c], rm=mapped[c];
            if(mc != rl[belong[mc]])
                lm = askl(1,1,n,mc-1);
            if(mc != rr[belong[mc]])
                rm = askr(1,1,n,mc+1);
            setl(1,1,n,lm,rm,lm);
            setr(1,1,n,lm,rm,rm);
        }
        else if(oper == 2)
        {

        }
    }
}