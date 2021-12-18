#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;
long long a, b;
string a_s, b_s;
string to_binary(long long x)
{
    string ans;
    while (x)
    {
        ans.push_back((x & 1) + '0');
        x >>= 1;
    }
    return ans;
}
string op(string &s, int t)
{
    string ans;
    if (t == 0)
    {
        ans = "0" + s;
        reverse(ans.begin(), ans.end());
        while (ans.back() == '0')
            ans.pop_back();
    }
    else
    {
        ans = "1" + s;
        reverse(ans.begin(), ans.end());
    }
    return ans;
}
queue<string> q;
set<string> s;
int main()
{
    cin >> a >> b;
    a_s = to_binary(a);
    b_s = to_binary(b);
    q.push(a_s);
    s.insert(a_s);
    for (; q.size();)
    {
        string cur = q.front();
        q.pop();
        if (cur.size() >= 101)
            continue;
        for (int j = 0; j <= 1; j++)
        {
            string nxt = op(cur, j);
            if (s.count(nxt) == 0)
                q.push(nxt), s.insert(nxt);
        }
    }
    if (s.count(b_s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}