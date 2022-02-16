#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
int a[200007];
int s[200007][18];
int slim;
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
int query(int l, int r)
{
	int qlim = (int)(log((double)(r-l+1))/log(2.0));
	return gcd(s[l][qlim], s[r-(1<<qlim)+1][qlim]);
}
int main()
{
	cin >> n;
	slim = (int)(log((double)n)/log(2.0));
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		s[i][0] = a[i];
	for(int j=1;j<=slim;j++)
		for(int i=1;i<=n;i++)
			if(i+(1<<(j-1))<=n)
				s[i][j] = gcd(s[i][j-1],s[i+(1<<(j-1))][j-1]);
	int l = 1, ans=0, pre=0;
	for(int r=1;r<=n;r++)
	{
		while(l < r && query(l,r) < r-l+1)
			l++;
		if(query(l,r) == r-l+1 && l > pre)
			pre = r, ans++;
		cout << ans << ' ';
	}
	cout << endl;
}