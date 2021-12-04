#include<bits/stdc++.h>
using namespace std;
int n, p;
int a[3000007] = {1,1};
int v[3000007] = {1};
int quick_pow(int x, int k)
{
	int ans = 1;
	while(k)
	{
		if(k & 1)
			ans = (long long)ans * x % p;
		x = (long long) x * x % p;
		k >>= 1;
	}
	return ans;
}
int main()
{
	cin >> n >> p;
	for(int i=2;i<=n;i++)
		a[i] = (long long) a[i-1] * i % p;
	v[n] = quick_pow(a[n], p-2);
	for(int i=n-1;i>=1;i--)
		v[i] = (long long) v[i+1] * (i+1) % p;
	for(int i=1;i<=n;i++)
		cout << ((long long) a[i-1] * v[i] % p) << '\n';
	return 0;
}
