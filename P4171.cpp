#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int k;
int n, m, id1, id2;
char t1, t2;
vector<int> g[207];
stack<int> s;
int dfn[207], low[207], belong[207], bs[207], q[207], cnt, bcnt;
void dfs(int cur)
{
    low[cur] = dfn[cur] = ++cnt;
    q[cur] = 1, s.push(cur);
    for (int nxt : g[cur])
    {
        if (!dfn[nxt])
        {
            dfs(nxt);
            low[cur] = min(low[nxt], low[cur]);
        }
        if (q[nxt])
            low[cur] = min(dfn[nxt], low[cur]);
    }
    if (dfn[cur] == low[cur])
    {
        ++bcnt;
        while (s.top() != cur)
            belong[s.top()] = bcnt, bs[bcnt]++, q[s.top()] = 0, s.pop();
        belong[s.top()] = bcnt, bs[bcnt]++, q[s.top()] = 0, s.pop();
    }
}
inline int iv(char t, int i)
{
    if (t == 'h' || t == 'l')
        return i;
    else
        return n + i;
}
int main()
{
    cin >> k;
    while (k--)
    {
        cin >> n >> m;
        bcnt = cnt = 0;
        for (; s.size(); s.pop())
            ;
        for (int i = 1; i <= n * 2; i++)
            g[i].clear(), q[i] = dfn[i] = low[i] = belong[i] = bs[i] = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> t1 >> id1 >> t2 >> id2;
            g[iv(t1 - 1, id1)].push_back(iv(t2, id2));
            g[iv(t2 - 1, id2)].push_back(iv(t1, id1));
        }
        for (int i = 1; i <= n * 2; i++)
            if (!dfn[i])
                dfs(i);
        for (int i = 1; i <= n; i++)
            if (belong[i] == belong[i + n])
            {
                cout << "BAD" << endl;
                goto flag;
            }
        cout << "GOOD" << endl;
    flag:;
    }
}