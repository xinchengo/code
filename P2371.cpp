#include<bits/stdc++.h>
using namespace std;
long long n, l, r, mod;
long long a[13];
long long nxt[5000007], to[5000007], head[500007], w[5000007], cnt;
void add(long long u, long long v, long long wh)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	w[cnt] = wh;
}
priority_queue<pair<int,int> > q;
long long dis[500007], ans;
void dijkstra()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;
	q.push({0,0});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int i=head[u];~i;i=nxt[i])
		{
			int v=to[i];
			if(dis[v] > dis[u] + w[i])
			{
				dis[v] = dis[u] + w[i];
				q.push({-dis[v], v});
			}
		}
	}
}
int main()
{
	memset(nxt, -1, sizeof(nxt));
	memset(head, -1, sizeof(head));
	cin >> n >> l >> r;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==0)
			swap(a[i],a[n]), n--;
		else if(a[i]==1)
			cout<<r-l+1,exit(0);
	}
	sort(a+1,a+n+1);
	mod = a[1];
	for(int i=2;i<=n;i++)
		if(a[i]!=mod)
			for(int k=0;k<mod;k++)
				add(k,(k+a[i])%mod,a[i]);
	dijkstra();
	for(int i=0;i<mod;i++)
		if(dis[i]<=r)
			ans+=(r-dis[i])/mod+1;
	for(int i=0;i<mod;i++)
		if(dis[i]<l)
			ans-=(l-dis[i]-1)/mod+1;
	cout << ans << endl;
}