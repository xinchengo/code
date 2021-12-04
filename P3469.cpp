// Fear cuts deeper than swords.

#include<algorithm>
#include<iostream>
#include<vector>
#define int long long
using namespace std;
int n, m;
int a, b;
vector<int> g[100007];
int dfn[100007], low[100007], q[100007], cnt, siz[100007], ans[100007], isc[100007];
void dfs(int cur)
{
    dfn[cur] = ++cnt;
    low[cur] = dfn[cur];
    siz[cur] = 1;
    q[cur] = 1;
    int ch = 0, s = 0;
    for(auto nxt : g[cur])
    {
        if(!dfn[nxt])
        {
            dfs(nxt);
            siz[cur] += siz[nxt];
            low[cur] = min(low[cur], low[nxt]);
            if(low[nxt] >= dfn[cur])
            {
                ans[cur] += siz[nxt] * (n-siz[nxt]);
                ch++;
                s+=siz[nxt];
                isc[cur] = isc[cur] || (ch>=2||cur!=1);
            }
        }
        if(q[nxt])
            low[cur] = min(low[cur], dfn[nxt]);
    }
    ans[cur] = (isc[cur]?(ans[cur]+(s+1)*(n-s-1)+(n-1)):(2*n-2));
    q[cur] = 0;
}
signed main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        cout << ans[i] << endl;
    return 0;
}
