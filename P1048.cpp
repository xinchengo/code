#include<iostream>
using namespace std;
int t, m;
int a[107], v[107], ans;
int f[107][1007];
int askdfs(int cur, int remain);
int dfs(int cur, int remain);
int askdfs(int cur, int remain)
{
	if(f[cur][remain] == -1)
		f[cur][remain] = dfs(cur, remain);
	return f[cur][remain];
}
int dfs(int cur, int remain)
{
	int ans = 0;
	if(cur == m+1)return 0;
	ans = max(ans, askdfs(cur+1,remain       ));
	if(a[cur] <= remain)
	ans = max(ans, askdfs(cur+1,remain-a[cur]) + v[cur]);
	return ans;
}
int main()
{
	cin >> t >> m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=t;j++)
			f[i][j] = -1;
	for(int i=1;i<=m;i++)
		cin >> a[i] >> v[i];
	cout << dfs(1,t) << endl;
} 
