#include<iostream>
#include<queue>
using namespace std;
int t, a[500007], n;
deque<int> l, r;
int solve()
{
    int f=a[1], i;
    for(i=2;a[i]!=f;i++) l.push_back(a[i]);
    for(i++;i<=n*2;i++)  r.push_front(a[i]);

}
int main()
{
    cin >> t;
    while(t--)
    {
        for(int i=1;i<=n*2;i++)
            cin >> a[i];
    }
}