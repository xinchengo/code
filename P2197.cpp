#include<iostream>
using namespace std;
int ans, t, n, tmp;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;
        for(int i=1;i<=n;i++)
            cin >> tmp, ans ^= tmp;
        cout << (!ans?"No":"Yes") << endl;
    }
}