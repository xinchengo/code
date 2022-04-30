#include<iostream>
using namespace std;
long long a, b;
long long x, y;
long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	int u = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return u;
}
int main()
{
	cin >> a >> b;
	exgcd(a, b, x, y);
	x = (x%b+b)%b;
	cout << x << endl;
}