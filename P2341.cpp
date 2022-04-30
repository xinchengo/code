#include<iostream>
#include<vector>
#include<cstring>
#define MAXN 10005
using namespace std;
int m, n, mmp, sum;
vector<int> g[MAXN]; // original graph
vector<int> gr[MAXN]; // reversed graph 
vector<int> f; // stack
int cmp[MAXN];
bool visited[MAXN];
int init()
{
	memset(visited, 0, sizeof(visited));
	return 0;
}
int add(int a, int b)
{
	g[a].push_back(b);
	gr[b].push_back(a);
	return 0;
}
int dfs1(int a)
{
	visited[a] = 1;
	for (unsigned int i=0;i<g[a].size();i++)
	{
		if (visited[g[a][i]] == 0)
		{
			dfs1(g[a][i]);
		}
	}
	f.push_back(a);
	return 0;
}
int dfs2(int a,int k)
{
	visited[a] = 1;
	cmp[a] = k;
	for (unsigned int i=0;i<gr[a].size();i++)
	{
		if (visited[gr[a][i]] == 0)
		{
			dfs2(gr[a][i],k);
		}
	}
	return 0;
}
int kosaraju()
{
	init();
	f.clear();
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			dfs1(i);
		}
	}
	init();
	int k = 0;
	for (int i = f.size() - 1; i >= 0; i--)
	{
		if (visited[f[i]] == 0)
		{
			dfs2(f[i],k++);
		}
	}
	return k;
}
int main()
{
	int t, u;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t >> u;
		add(t, u);
	}
	int ans = kosaraju();
	for (int i = 1; i <= n; i++)
	{
		if (cmp[i] == ans - 1) 
		{
			mmp = i;
			sum++;
		}
	}
	init();
	dfs2(mmp, 1);
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << sum << endl;
	return 0;
}
