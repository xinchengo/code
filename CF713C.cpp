#include<iostream>
#include<queue>
using namespace std;
int n;
int a[3007];
priority_queue<int> q;
long long ans; 
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i] -= i;
	}
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		if(a[i] < q.top())
		{
			ans += q.top() - a[i];
			q.pop();
			q.push(a[i]);
		}
	}
	cout << ans << endl;
}
