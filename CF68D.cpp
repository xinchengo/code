#include<iostream>
#include<cmath>
#include<string>
#include<map>
using namespace std;
int h, q;
int v, e;
char op[8];
map<int, long long> s;
long long dfs(int cur, long long maxb)
{
    if(s[cur] <= maxb)
        return 1ll * ((1<<h)/(1<<(int)log2(cur))) * maxb;
    if((int)log2(cur) == h)
        return max(s[cur],maxb);
    else
        return dfs(cur<<1,max(s[cur]-s[cur<<1],maxb)) + dfs(cur<<1|1,max(s[cur]-s[cur<<1|1],maxb));
}
int main()
{
    cin >> h >> q;
    while(q--)
    {
        cin >> op;
        if(op[0] == 'a') // add
        {
            cin >> v >> e;
            while(v)
                s[v] += e, v >>= 1;
        }
        else // decay
            cout << ((double)dfs(1,0)/(double)(1<<h)) << endl;
    }
}
