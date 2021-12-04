#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n, a, b;
vector<int> g[500007];
int c[500007];
int f[500007];
int t[500007];
void predfs(int cur, int fa)
{
	for(auto &nxt:g[cur])
		if(nxt!=fa)
			predfs(nxt,cur);
		else
			nxt=g[cur].back(),
			g[cur].pop_back();
}
bool comp(int a, int b)
	{return f[a]-t[a]>f[b]-t[b];}
void dfs(int cur)
{
	f[cur] = cur==1?f[cur]:c[cur];
	for(auto &nxt:g[cur])
		dfs(nxt);
	sort(g[cur].begin(),g[cur].end(),comp);
	for(auto &nxt:g[cur])
		f[cur] = max(f[cur],f[nxt]+t[cur]+1), t[cur]+=t[nxt]+2;		
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
		scanf("%d %d",&a,&b),
		g[a].push_back(b),
		g[b].push_back(a);
	predfs(1,0);
	dfs(1);
	printf("%d\n",f[1]>(c[1]+t[1])?f[1]:(c[1]+t[1]));
}
