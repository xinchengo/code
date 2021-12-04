#include <iostream>
#include <vector>
using namespace std;
long long a, b;
long long f[14];
long long ten[14] = {1};
vector<long long> calc(long long x)
{
    vector<long long> ans(10, 0LL);
    vector<int> num;
    long long t = x;
    while (t)
        num.push_back(t % 10), t /= 10;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int k = 0; k < num[i]; k++)
            ans[k] += ten[i];
        for (int k = 0; k < 10; k++)
            ans[k] += num[i] * f[i];
        x -= num[i] * ten[i];
        ans[num[i]] += x + 1;
        ans[0] -= ten[i];
    }
    return ans;
}
int main()
{
    for (int i = 1; i <= 13; i++)
        ten[i] = ten[i - 1] * 10;
    for (int i = 1; i <= 13; i++)
        f[i] = f[i - 1] * 10 + ten[i - 1];
    cin >> a >> b;
    auto ansb = calc(b);
    auto ansa = calc(a - 1);
    for (int i = 0; i < 10; i++)
        cerr << ansb[i] << ' ';
    cerr << endl;
    for (int i = 0; i < 10; i++)
        cerr << ansa[i] << ' ';
    cerr << endl;
    for (int i = 0; i < 10; i++)
        cout << ansb[i] - ansa[i] << ' ';
    cout << endl;
}
