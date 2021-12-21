#include<iostream>
#include<vector>
using namespace std;
int q;
int op, x, y;
vector<int> val[(int)5e5+1];
int a[(int)5e5+1], cnt;
int ans[(int)5e5+1];
int main()
{
	cin >> q;
	while(q--)
	{
		cin >> op;
		if(op == 1)
			cin >> x, a[++cnt] = x, val[x].push_back(cnt);
		else
		{
			cin >> x >> y;
			if(x == y)
				continue;
			if(val[x].size() > val[y].size())
				swap(val[x], val[y]);
			for(auto &i:val[x])
				val[y].push_back(i);
			val[x].clear();
		}
	}
	for(int i=1;i<=(int)5e5;i++)
		for(auto j:val[i])
			ans[j]=i;
	for(int i=1;i<=cnt;i++)
		cout << ans[i] << ' ';
	cout << endl;
}
