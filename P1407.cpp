// Fear cuts deeper than swords.

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;
int n, m;
string a, b;
map<string,int> name;
vector<int> g[8007];
stack<int> s;
int cnt, dfn[8007], low[8007], q[8007];
int bcnt, belong[8007], bs[8007];
void tarjan(int cur)
{
    dfn[cur] = ++cnt;
    low[cur] = dfn[cur];
    q[cur] = 1;
    s.push(cur);
    for(int nxt : g[cur])
    {
        if(!dfn[nxt])
        {
            tarjan(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        if(q[nxt])
            low[cur] = min(low[cur], dfn[nxt]);
    }
    if(low[cur] == dfn[cur])
    {
        bcnt++;
        while(s.top() != cur)
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
    for(int i=1;i<=n;i++)
    {
        cin >> a >> b;
        name[a] = i*2-1;
        name[b] = i*2;
        g[i*2-1].push_back(i*2);
    }
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a >> b;
        g[name[b]].push_back(name[a]);
    }
    for(int i=1;i<=n*2;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=n;i++)
        if(belong[i*2-1] == belong[i*2])
            cout << "Unsafe" << endl;
        else
            cout << "Safe" << endl;
}
