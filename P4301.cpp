#include<iostream>
#include<algorithm>
using namespace std;
int k, a[107], p[107];
long long ans;
void insert(int x)
{
    int ox = x;
    for(int i=30;i>=0;i--)
        if(x>>i)
        {
            if(p[i]==0)
            {
                p[i]=x;
                break;
            }
            x^=p[i];
        }
    if(x==0)
        ans += ox;
}
int main()
{
    cin >> k;
    for(int i=1;i<=k;i++)
        cin >> a[i];
    sort(a+1,a+k+1,std::greater<int>());
    for(int i=1;i<=k;i++)
        insert(a[i]);
    cout << ans << endl;
}