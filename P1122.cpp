#include<iostream>
#include<vector>
using namespace std;
int n;
int v[16007];
int f[16007];
vector<int> g[16007];
int ans = -2147483647;
int dfs(int cur, int fa)
{
	f[cur] = v[cur];
	for(auto nxt : g[cur])
	{
		if(nxt != fa)
		{
			dfs(nxt, cur);
			if(f[nxt] > 0)
			{
				f[cur] += f[nxt];
			}
		}
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> v[i];
	}
	for(int i=1;i<n;i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	for(int i=1;i<=n;i++)
	{
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
}
