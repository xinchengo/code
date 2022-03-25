#include<iostream>
using namespace std;
long long s, t;
int main()
{
    cin >> s >> t;
    if(((s-t)&1) || s<t || (((s-t)/2)&t))
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        long long ans=0, flag = (s==t?-2:0);
        while(t)
        {
            if(t&1)
                ans++;
            t>>=1;
        }
        ans=1LL<<ans;
        cout << ans + flag << endl;
    }
}