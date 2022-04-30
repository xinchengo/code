#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[3007];
int a[3007];
int n, m, mod, ans=-1;
int gcd(int a, int b)
{
	if(a == 0)
		return b;
	return gcd(b, b%a);
}
int dis[3007];
priority_queue<pair<int,int> > q;
void dijkstra()
{
	memset(dis, 0x3f, sizeof(dis));
	q.push({0,0});
	dis[0]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(auto nxt:g[u])
		{
			int v=nxt.first, w=nxt.second;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({-dis[v], v});
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	mod = max(1,a[1]-m);
	if(mod == 1)
		cout << -1 << endl, exit(0);
	for(int i=1;i<=n;i++)
		for(int j=a[i];j>a[i-1]&&a[i]-j<=m;j--)
			if(j!=mod)
				for(int k=0;k<mod;k++)
					g[k].push_back({(k+j)%mod, j});
	dijkstra();
	for(int i=1;i<mod;i++)
	{
		if(dis[i]>1e9)cout << -1 << endl, exit(0);
		ans=max(ans,dis[i]-mod);
	}
	cout << ans << endl;
}