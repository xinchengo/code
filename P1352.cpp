#include<iostream>
#include<vector>
using namespace std;
int n, l, k;
vector<int> g[6007];
int r[6007], d[6007];
int f[6007][2];
void dfs(int cur)
{
	f[cur][0]=0, f[cur][1]=r[cur];
	for(auto nxt:g[cur])
		dfs(nxt),
		f[cur][0] += max(f[nxt][1], f[nxt][0]),
		f[cur][1] += f[nxt][0];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d",&l,&k), g[k].push_back(l), d[l]++;
	for(int i=1;i<=n;i++)
		if(d[i]==0)
			dfs(i),
			printf("%d\n",max(f[i][0],f[i][1])),
			exit(0);
}
