#include<iostream>
#include<cstring>
using namespace std;
int n;
int f[125][125][125];
void add(int* c, int x, int k)
{
	x++;
	for(;x<=n+1;x+=x&-x)
		c[x] += k;
}
int ask(int *c, int x)
{
	x++;
	int k = 0;
	for(;x;x-=x&-x)
		k += c[x];
	return k;
}
int main()
{
	while(cin >> n)
	{
		memset(f,0,sizeof(f));
		add(f[0][0], 0, 1);
		for(int i=1;i<=n;i++)
		{
			for(int s=0;s<=n;s++) // sum
			{
				for(int x=0;x<=s;x++) // last
				{
					add(f[i][s], x, ask(f[i-1][s-x], x));
				}
			}
		}
		cout << ask(f[n][n], n) << endl;
	}
}
