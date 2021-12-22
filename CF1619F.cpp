#include<iostream>
using namespace std;
int t;
int n, m, k;
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		if(n % m != 0)
		{
			int a = n-(n/m)*m;
			int b = ((n+m-1)/m)*m-n;
			int sa = (n+m-1)/m;
			int sb = n/m;
			cerr << a << ' ' << b;
			int st = 0;
			for(int i=1;i<=k;i++)
			{
				int u = st;
				for(int j=1;j<=a;j++)
				{
					cout << sa << ' ';
					for(int k=1;k<=sa;k++)
						cout << (u%n)+1 << ' ', u++;	
					cout << endl;
				}
				st = u;
				for(int j=1;j<=b;j++)
				{
					cout << sb << ' ';
					for(int k=1;k<=sb;k++)
						cout << (u%n)+1 << ' ', u++;
					cout << endl;
				}
			}	
		}
		else
		{
			int st = 0;
			for(int i=1;i<=k;i++)
			{
				int u = st;
				for(int j=1;j<=m;j++)
				{
					cout << n/m << ' ';
					for(int k=1;k<=n/m;k++)
						cout << (u%n)+1 << ' ', u++;
					cout << endl;
				}
			}
		}
		cout << endl;
	}
}
