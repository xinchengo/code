#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n;
int ni, nr, t;
vector<int> g[1507], g_[1507];
int f[1507][2];
void dfs(int cur)
{
    f[cur][1] = 1;
    f[cur][0] = 0;
    for(auto nxt:g[cur])
    {
        dfs(nxt);
        f[cur][1] += min(f[nxt][1], f[nxt][0]);
        f[cur][0] += f[nxt][1];
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            g[i].clear(), g_[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d:(%d)",&ni,&nr);
            for(int j=1;j<=nr;j++)
                scanf("%d",&t),
                g[ni].push_back(t), g_[t].push_back(ni);
        }
        for(int i=0;i<n;i++)
            if(g_[i].size()==0)
            {
                dfs(i), printf("%d\n",min(f[i][0], f[i][1]));
                break;
            }
    }
}
