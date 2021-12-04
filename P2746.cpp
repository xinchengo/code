// Fear cuts deeper than swords.

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, t;
vector<int> g[107];
stack<int> s;
int dfn[107], low[107], belong[107], bs[107], cnt, bcnt, q[107];
int ind[107], oud[107], ans1, ans2;
void dfs(int cur)
{
    dfn[cur] = ++cnt;
    low[cur] = dfn[cur];
    q[cur] = 1;
    s.push(cur);
    for (int nxt : g[cur])
    {
        if (!dfn[nxt])
        {
            dfs(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        if (q[nxt])
            low[cur] = min(low[cur], dfn[nxt]);
    }
    if (low[cur] == dfn[cur])
    {
        bcnt++;
        while (s.top() != cur)
        {
            bs[bcnt]++;
            belong[s.top()] = bcnt;
            q[s.top()] = 0;
            s.pop();
        }
        bs[bcnt]++;
        belong[s.top()] = bcnt;
        q[s.top()] = 0;
        s.pop();
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        while (t != 0)
        {
            g[i].push_back(t);
            cin >> t;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        for (int j : g[i])
            if (belong[i] != belong[j])
                ind[belong[j]]++, oud[belong[i]]++;
    for (int i = 1; i <= bcnt; i++)
        if (ind[i] == 0)
            ans1++;
    for (int i = 1; i <= bcnt; i++)
        if (oud[i] == 0)
            ans2++;
    if (bcnt == 1)
        cout << 1 << '\n' << 0 << endl;
    else
    {
        ans2 = max(ans1, ans2);
        cout << ans1 << endl;
        cout << ans2 << endl;
    }
}
