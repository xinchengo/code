#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m;
int w, a[2007][2007], ds[2007][2007], de[2007][2007];
long long mins, mine;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> w;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j], ds[i][j] = -1, de[i][j] = -1;
	ds[1][1] = 0LL;
	de[n][m] = 0LL;
	queue<pair<int,int> > q;
	q.push({1,1});
	while(!q.empty())
	{
		int cx = q.front().first, cy=q.front().second, nx, ny;
		q.pop();
		for(int p=0;p<4;p++)
		{
			nx = cx + dx[p], ny = cy + dy[p];
			if(!nx||!ny||nx>n||ny>m)
				continue;
			if(a[nx][ny] == -1 || ds[nx][ny] != -1)
				continue;
			ds[nx][ny] = ds[cx][cy] + 1;
			q.push({nx,ny});
		}
	}
	q.push({n,m});
	while(!q.empty())
	{
		int cx = q.front().first, cy=q.front().second, nx, ny;
		q.pop();
		for(int p=0;p<4;p++)
		{
			nx = cx + dx[p], ny = cy + dy[p];
			if(!nx||!ny||nx>n||ny>m)
				continue;
			if(a[nx][ny] == -1 || de[nx][ny] != -1)
				continue;
			de[nx][ny] = de[cx][cy] + 1;
			q.push({nx,ny});
		}
	}
	mins = 0x1f1f1f1f1f1f1f1fLL;
	mine = 0x1f1f1f1f1f1f1f1fLL;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j] > 0LL && ds[i][j] != -1)
				mins = min(mins, (long long)a[i][j] + (long long)ds[i][j] * w);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j] > 0LL && de[i][j] != -1)
				mine = min(mine, (long long)a[i][j] + (long long)de[i][j] * w);
	long long ans;
	if(ds[n][m] != -1)
		ans = min(mins+mine, (long long)ds[n][m] * w);
	else
	 	ans = mins + mine;
	cout << (ans<0x1f1f1f1f1f1f1f1fLL?ans:-1) << endl;
}
