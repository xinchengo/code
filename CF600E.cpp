#include<iostream>
using namespace std;
const int maxn = 1e5+7, maxm = 2e5+7;
int n;
int c[maxn];
int head[maxn], nxt[maxm], to[maxm], ecnt;
int cnt[maxn];
void add(int u, int v)
{
    nxt[++ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
}
int siz[maxn], heavy[maxn];
void predfs(int u, int fa)
{
    siz[u] = 1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
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
long long ans[maxn], cs, dcnt;
void calc(int u, int fa, int k)
{
    cnt[c[u]] += k;
    if(k == 1 && cnt[c[u]] >= dcnt)
    {
        if(cnt[c[u]] > dcnt)
        {
            cs = 0;
            dcnt = cnt[c[u]];
        }
        cs += c[u];
    }
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(v != fa && !inc[v])
            calc(v, u, k);
    }
}
void dfs(int u, int fa, bool keep)
{
    for(int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if(v != fa && v != heavy[u])
        {
            dfs(v, u, false);
        }
    }
    if(heavy[u])
    {
        dfs(heavy[u], u, true);
        inc[heavy[u]] = true;
    }
    calc(u, fa, 1), ans[u] = cs;
    if(heavy[u])
        inc[heavy[u]] = false;
    if(keep == false)
        calc(u, fa, -1), cs=0, dcnt=0;

}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> c[i];
    int x, y;
    for(int i=1;i<n;i++)
    {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    predfs(1,0);
    dfs(1,0,1);
    for(int i=1;i<=n;i++)
        cout << ans[i] << ' ';
    cout << endl;
}