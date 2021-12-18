#include<iostream>
using namespace std;
int n;
long long a[51], p[51], ans;
void insert(long long x)
{
    for(int i=50;i>=0;i--)
        if(x>>i)
        {
            if(p[i]==0)
            {
                p[i]=x;
                break;
            }
            x=x^p[i];
        }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        insert(a[i]);
    for(int i=50;i>=0;i--)
        if((ans ^ p[i]) > ans)
            ans = ans ^ p[i];
    cout << ans << endl;
}