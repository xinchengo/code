// Fear cuts deeper than swords.

#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pos(x) lower_bound(all(nums),x)-nums.begin()
#define int long long
using namespace std;
int a[1000007], c[2][1000007], n, m, p, lim;
vector<int> nums;
struct query
{
    char type[3];
    int x, y;
}q[1000007];
void add(int i,int x, int k) {for(;x<=lim;x+=x&-x)c[i][x]+=k;}
int ask(int i,int x) {int k=0;for(;x;x-=x&-x)k+=c[i][x];return k;}
signed main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
        cin >> q[i].type >> q[i].x >> q[i].y,nums.push_back(q[i].y);
    sort(all(nums));
    nums.erase(unique(all(nums)),nums.end()),nums.insert(nums.begin(),{-1,0}),lim=nums.size();
    add(1,pos(0),n);
    for(int i=1;i<=m;i++)
        if(q[i].type[0]=='U')
            p=pos(a[q[i].x]),add(0,p,-a[q[i].x]),add(1,p,-1),a[q[i].x]=q[i].y,
            p=pos(a[q[i].x]),add(0,p,a[q[i].x]),add(1,p,1);
        else
            cout << ((ask(0,pos(q[i].y)-1)>=(q[i].x-n+ask(1,pos(q[i].y)-1))*q[i].y)?"TAK":"NIE") << endl;
}
