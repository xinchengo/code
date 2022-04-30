#include<bits/stdc++.h>
using namespace std;
int k;
bool v[100007];
deque<pair<int,int> > q;
int main()
{
	cin >> k;
	q.push_back({1,1});
	while(!q.empty())
	{
		int u=q.front().first, d=q.front().second;
		v[u] = true, q.pop_front();
		if(u==0)
			cout << d << endl, exit(0);
		if(!v[(u+1)%k])
			q.push_back({(u+1)%k,d+1});
		if(!v[u*10%k])
			q.push_front({u*10%k,d});
	}
}