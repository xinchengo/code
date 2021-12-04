// Fear cuts deeper than swords.

#include <iostream>
using namespace std;
int n, x[0x922], y[0xb17], l, r;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    l = min(x[1], x[2]), r = max(x[1], x[2]), x[n+1] = x[1], y[n+1] = y[1];
    for (int i = 2; i <= n; i++)
    {
        while (r-l+1&&1LL*(0LL+x[i+1]-x[i])*(0LL+y[1]-y[i])-(0LL+y[i+1]-y[i])*(0LL+l-x[i])>0LL) l++;
        while (r-l+1&&1LL*(0LL+x[i+1]-x[i])*(0LL+y[1]-y[i])-(0LL+y[i+1]-y[i])*(0LL+r-x[i])>0LL) r--;
    }
    cout << r-l+1 << endl;
}
