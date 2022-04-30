#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
long long head[100007], nxt[200007], to[200007], w[200007], cnt;
long long h, x, y, z;
unsigned long long dis[100007];
long long ans;
void add(int u, int v, int weight)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	w[cnt] = weight;
}
priority_queue<pair<unsigned long long, int> > q;
void dijkstra()
{
	memset(dis, -1, sizeof(dis));
	dis[1] = 1;
	q.push({-1,1});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int i=head[u];~i;i=nxt[i])
		{
			if(dis[to[i]] > dis[u] + w[i])
			{
				dis[to[i]] = dis[u] + w[i];
				q.push({-dis[to[i]], to[i]});
			}
		}
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	memset(nxt, -1, sizeof(nxt));
	cin >> h;
	cin >> x >> y >> z;
	if(x==1||y==1||z==1)
	{
		cout << h << endl;
		return 0;
	}
	if(x > y)
		swap(x, y);
	if(x > z)
		swap(x, z);
	if(y > z)
		swap(y, z);
	for(int i=0;i<x;i++)
	{
		add(i, (i+y)%x, y);
		add(i, (i+z)%x, z);
	}
	dijkstra();
	for(int i=0;i<x;i++)
		if(dis[i] <= h)
			ans += (h-dis[i])/x+1;
	cout << ans << endl;
}