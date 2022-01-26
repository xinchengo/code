#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2e5;
class disjoint_set
{
private:
    int fa[maxn+7];
public:
    void init(int size)
    {
        for(int i=1;i<=size;i++)
            fa[i] = i;
    }
    int get_fa(int node)
    {
        if(node == fa[node])
            return node;
        return fa[node] = get_fa(fa[node]);
    }
    void merge(int node1, int node2)
    {
        int a = get_fa(node1);
        int b = get_fa(node2);
        if(a != b)
            fa[a] = b;
    }
}ds;
struct mine
{
    int x, y;
    int timer;
}a[maxn+7];
int t;
int n, k;
int ans;
map<int,vector<int> > mx, my;
map<int,int> mti;
int btm[maxn+7], bcnt;
bool compx(int i1, int i2)
{
    return a[i1].x < a[i2].x;
}
bool compy(int i1, int i2)
{
    return a[i1].y < a[i2].y;
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ds.init(n);
        for(int i=1;i<=n;i++)
            cin >> a[i].x >> a[i].y >> a[i].timer;
        mti.clear();
        mx.clear();
        my.clear();
        for(int i=1;i<=n;i++)
            mx[a[i].x].push_back(i);
        for(int i=1;i<=n;i++)
            my[a[i].y].push_back(i);
        for(auto &row:mx)
            sort(row.second.begin(),row.second.end(),compy);
        for(auto &col:my)
            sort(col.second.begin(),col.second.end(),compx);
        for(auto &row:mx)
            for(int i=1;i<row.second.size();i++)
                if(a[row.second[i]].y - a[row.second[i-1]].y <= k)
                    ds.merge(row.second[i], row.second[i-1]);
        for(auto &col:my)
            for(int i=1;i<col.second.size();i++)
                if(a[col.second[i]].x - a[col.second[i-1]].x <= k)
                    ds.merge(col.second[i], col.second[i-1]);
        for(int i=1;i<=n;i++)
        {
            int fa = ds.get_fa(i);
            if(mti.count(fa) == 0)
                mti[fa] = a[i].timer;
            else
                mti[fa] = min(mti[fa], a[i].timer);
        }
        bcnt = 0;
        for(auto &i:mti)
            btm[++bcnt] = i.second;
        sort(btm+1,btm+bcnt+1);
        ans = btm[bcnt];
        int time = 0;
        for(int i = bcnt-1; i >= 0;i--)
        {
            ans = min(ans, max(time, btm[i]));
            time++;
        }
        cout << ans << endl;
    }
}
