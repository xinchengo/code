#include<iostream>
using namespace std;
int n, k;
long long f[17][100][517], ans;
int popcnt(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}
int main()
{
	cin >> n >> k;
	for(int i=0;i<(1<<n);i++)
	{
		if((i & (i>>1)) == 0)
		{
			f[1][popcnt(i)][i] = 1;
		}
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<(1<<n);i++)
		{
			if((i & (i>>1)) == 0)
			{
				for(int j=0;j<(1<<n);j++)
				{
					if((i & j) == 0 && ((i>>1) & j) == 0 && ((i<<1) & j) == 0) 
					{
						int base = popcnt(i) + popcnt(j);
						int icnt = popcnt(i);
						for(int c = base; c <= n * n; c++)
						{
							f[l][c][i] += f[l-1][c-icnt][j];
						}
					}
				}	
			}
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		ans += f[n][k][i];
	}
	cout << ans << endl;
}
