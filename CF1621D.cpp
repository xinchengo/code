nclude<iostream>
#include<algorithm>
using namespace std;
int t, n;
long long a[512][512], sum;
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		sum = 0;
		for(int i=1;i<=n*2;i++)
			for(int j=1;j<=n*2;j++)
				cin >> a[i][j];
		for(int i=n+1;i<=n*2;i++)
			for(int j=n+1;j<=n*2;j++)
				sum += a[i][j];
		cout << sum + min({a[1][n+1],a[1][n*2],a[n][n+1],a[n][n*2],a[n+1][1],a[n+1][n],a[n*2][1],a[n*2][n]}) << endl;
	}
}
