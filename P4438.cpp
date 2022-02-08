#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct city
{
	int l, r;
}g[20007];
struct country
{
	int a, b, c;
}h[20007];
long long f[20007][41][41];
long long dfs(int cur, int x, int y)
{
	if(cur < 0)
	{
		cur = -cur;
		return (long long)h[cur].c * (h[cur].a + x) * (h[cur].b + y);
	}
	else
	{
		if(f[cur][x][y])
		{
			return f[cur][x][y];
		}
		return f[cur][x][y] = min(dfs(g[cur].l, x+1, y) + dfs(g[cur].r, x, y),
							  	dfs(g[cur].l, x, y) + dfs(g[cur].r, x, y+1));
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<n;i++)
	{
		cin >> g[i].l >> g[i].r;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> h[i].a >> h[i].b >> h[i].c;
	}
	cout << dfs(1,0,0) << endl;
}
