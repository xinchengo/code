#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n, s;
vector<pair<int, long long> > g[500007];
long long h[500007], ans;
int dfs1(int cur, int fa, long long dis)
{
	h[cur] = dis;
	for(auto nxt : g[cur])
	{
		if(nxt.first != fa)
		{
			dfs1(nxt.first, cur, dis + nxt.second);
			h[cur] = max(h[cur], h[nxt.first]);
		}
	}
}
int dfs2(int cur, int fa, long long exp)
{
	ans += h[s] - h[cur] - exp;
	for(auto nxt : g[cur])
	{
		if(nxt.first != fa)
		{
			dfs2(nxt.first, cur, h[s] - h[cur]);
		}
	}
}
int main()
{
	cin >> n;
	cin >> s;
	for(int i=1;i<n;i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		g[a].push_back({b,t});
		g[b].push_back({a,t});
	}
	dfs1(s, 0, 0);
	dfs2(s, 0, 0);
	cout << ans << endl;
}
