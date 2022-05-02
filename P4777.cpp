#include<iostream>
#include<cassert>
using namespace std;
int n;
long long a[100007], b[100007];
long long ra, rb;
long long mul(long long a, long long b, long long mod)
{
	long long ans = 0;
	while(b)
	{
		if(b & 1)
			ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}
long long x, y;
long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if(!b)
	{
		x=1, y=0;
		return a;
	}
	long long u = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return u;
}
long long regulate(long long x, long long p)
{
	return (x%p+p)%p;
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i] >> b[i];
	ra = a[1], rb = b[1];
	for(int i=2;i<=n;i++)
	{
		long long d = exgcd(ra, a[i], x, y), l = ra / d * a[i];
		assert((b[i]-rb) % d == 0);
		x = regulate(x, l);
		rb = regulate(rb + mul(mul((b[i]-rb)/d,x,l),ra,l), l);
		ra = l;
	}
	cout << rb << endl;
}