#include<iostream>
#include<cstring>
using namespace std;
int n, c, ans;
int _f, _l, _t;
struct ch
{
	int loc;
	int like;
	int fear;
}a[50007];
int f[10007][32];
bool satisfy(int S, int id)
{
	if(S & a[id].like)
		return 1;
	if(~S& a[id].fear)
		return 1;
	return 0;
}
int sat[10007][32];
int main()
{
	cin >> n >> c;
	for(int i=1;i<=c;i++)
	{
		cin >> a[i].loc;
		cin >> _f >> _l;
		for(int j=1;j<=_f;j++)
		{
			cin >> _t;
			a[i].fear |= (1 << ((_t-a[i].loc+n)%n));
		}
		for(int j=1;j<=_l;j++)
		{
			cin >> _t;
			a[i].like |= (1 << ((_t-a[i].loc+n)%n));
		}
		for(int S=0;S<32;S++)
		{
			if(satisfy(S,i))
			{
				sat[a[i].loc][S]++;
			}
		}
	}
	for(int S=0;S<32;S++)
	{
		memset(f[0], -128, sizeof(f[0]));
		f[0][S] = 0;
		for(int i=1;i<=n;i++)
		{
			for(int S=0;S<32;S++)
			{
				f[i][S] = max(f[i-1][(S&15)<<1], f[i-1][(S&15)<<1|1]) + sat[i][S];
			}
		}
		ans = max(ans, f[n][S]);
	}
	cout << ans << endl;
}
