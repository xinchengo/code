#include<iostream>
using namespace std;
const int maxn = 1e5+7;
int T;
int n, m, p;
int pmod[maxn], pinv[maxn];
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
int x, y;
int C(int n, int m)
{
	if(m>n)	return 0;
	return (1LL * ((1LL * pmod[n] * pinv[m]) % p) * pinv[n-m]) % p;
}
int Lucas(int n, int m, int p)
{
	if(m == 0)	return 1;
	else return 1LL * C(n%p, m%p) * Lucas(n/p, m/p, p) % p;
}
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> p;
		pmod[1] = 1;
		for(int i=2;i<p;i++)
			pmod[i] = 1LL * pmod[i-1] * i % p;
		exgcd(pmod[p-1], p, x, y);
		pinv[p-1] = (x%p+p)%p;
		for(int i=p-1;i>=1;i--)
			pinv[i-1] = 1LL * i * pinv[i] % p;
		cout << Lucas(n+m,m,p) << endl;
	}
}