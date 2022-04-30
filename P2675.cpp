#include<iostream>
using namespace std;
const int mod = 10007;
int pmod[mod], pinv[mod];
int n;
int x, y;
int ans;
int exgcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x=1, y=0;
		return a;
	}
	int u = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return u;
}
int C(int n, int m)
{
	if(m > n) return 0;
	return 1LL * (1LL * pmod[n] * pinv[m] % mod) * pinv[n-m] % mod;
}
int Lucas(int n, int m)
{
	if(m == 0) return 1;
	else return 1LL * C(n%mod, m%mod) * Lucas(n/mod, m/mod) % mod;
}
int main()
{
	cin >> n;
	pmod[1] = 1;
	for(int i=2;i<mod;i++)
		pmod[i] = 1LL * i * pmod[i-1] % mod;
	exgcd(pmod[mod-1], mod, x, y);
	pinv[mod-1] = (x%mod+mod)%mod;
	for(int i=mod-1;i>=1;i--)
		pinv[i-1] = 1LL * i * pinv[i] % mod;
	for(int i=0;i<n/2;i++)
		ans = (0LL + ans + 1LL * (i*4+3) * Lucas(n-1, i)) % mod;
	if(n & 1)
		ans = (0LL + ans + 1LL * n * Lucas(n-1, n/2)) % mod;
	cout << ans << endl;
}