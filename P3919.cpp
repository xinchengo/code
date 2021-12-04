#include<iostream>
using namespace std;
int a[1000007], r[1000007], n, m, cnt, v, o, l, k, rcnt;
struct node
{
    int l, r, v;
}t[25000001];
void build(int n, int l, int r)
{
    if(l==r){t[n].v=a[l];return;}
    t[n].l=++cnt, t[n].r=++cnt;
    int m=(l+r)>>1;
    build(t[n].l,l,m), build(t[n].r,m+1,r);
}
int change(int n, int x, int l, int r, int k)
{
    int nd=++cnt;
    t[nd]=t[n];
    if(l==r){t[nd].v=k;return nd;}
    int m=(l+r)>>1;
    if(x<=m) t[nd].l = change(t[nd].l,x,l,m,k);
    else     t[nd].r = change(t[nd].r,x,m+1,r,k);
    return nd;
}
int ask(int n, int x, int l, int r)
{
    if(l==r)return t[n].v;
    int m=(l+r)>>1;
    if(x<=m) return ask(t[n].l,x,l,m);
    else     return ask(t[n].r,x,m+1,r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    build(0,1,n);
    for(int i=1;i<=m;i++)
    {
        cin >> v >> o >> l;
        if(o==2)
        {
            r[++rcnt] = r[v];
            cout << ask(r[v],l,1,n) << '\n';
        }
        else
        {
            cin >> k;
            r[++rcnt] = change(r[v],l,1,n,k);
        }
    }
}
