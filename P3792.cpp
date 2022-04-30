#include<bits/stdc++.h>
using namespace std;
int n, m, ncnt, acnt;
struct query
{
    int opt, x, y;
} q[1000007];
struct num
{
    int val, id, ord;
} nums[1000007];
int a[1000007];
constexpr bool comp(num a, num b)
{
    return a.val < b.val;
}
unsigned long long c[1000007];
unsigned long long cx[1000007];
unsigned long long rv[1000007];
unsigned long long rx[1000007];
void add(int x, int k)
{
    for(; x<=n; x+=x&-x)
        c[x] += k;
}
unsigned long long ask(int x)
{
    unsigned long long k=0;
    for(; x; x-=x&-x)
        k += c[x];
    return k;
}
void addx(int x, unsigned long long k)
{
    for(; x<=n; x+=x&-x)
        cx[x] ^= k;
}
unsigned long long askx(int x)
{
    unsigned long long k=0;
    for(; x; x-=x&-x)
        k ^= cx[x];
    return k;
}
signed main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i], a[i]++;
    for(int i=1; i<=m; i++)
        cin >> q[i].opt >> q[i].x >> q[i].y, q[i].y += 2-q[i].opt;
    for(int i=1; i<=n; i++)
    {
        nums[i].val=a[i];
        nums[i].id=i;
    }
    ncnt=n;
    for(int i=1; i<=m; i++)
    {
        if(q[i].opt==1)
            nums[++ncnt].val=q[i].y,nums[ncnt].id=i+n;
    }
    sort(nums+1,nums+ncnt+1,comp);
    for(int i=1; i<=ncnt; i++)
    {
        if(nums[i].val == nums[i-1].val)
            nums[i].ord = acnt;
        else if(nums[i].val == nums[i-1].val + 1)
            nums[i].ord = ++acnt;
        else
            nums[i].ord = ++(++acnt);
    }

    for(int i=1; i<=ncnt; i++)
    {
        if(nums[i].id <= n)
            a[nums[i].id] = nums[i].ord;
        else
            q[nums[i].id-n].y = nums[i].ord;
    }
    for(int i=1; i<=n; i++)
    {
        c[i] += a[i];
        if((i+(i&-i))<=n)
            c[i+(i&-i)] += c[i];
    }
    unsigned long long rs=0xbadf1a4e5;
    for(int i=1; i<=acnt; i++)
    {
        rs=(rs*1919810114531)+1145141919827;
        rv[i]=rs;
        rx[i] = rx[i-1] ^ rs;
    }
    for(int i=1; i<=n; i++)
    {
        cx[i] ^= rv[a[i]];
        if((i+(i&-i))<=n)
            cx[i+(i&-i)] ^= cx[i];
    }
    for(int i=1; i<=m; i++)
    {
        if(q[i].opt == 1)
        {
            addx(q[i].x, a[q[i].x] ^ q[i].y);
            add(q[i].x, a[q[i].x] - q[i].y);
            a[q[i].x] = q[i].y;;
        }
        else
        {
            int mid=(ask(q[i].y)-ask(q[i].x-1))/(q[i].y-q[i].x+1);
            int l=mid-(q[i].y-q[i].x)/2;
            int r=mid+(q[i].y-q[i].x)/2+((q[i].y-q[i].x)&1);
            if(l<=0||r>acnt)
            {
                cout << "yuanxing\n";
            }
            else if((askx(q[i].y)^askx(q[i].x-1))==(rx[r]^rx[l-1]))
            {
                cout << "damushen\n";
            }
            else
                cout << "yuanxing\n";
        }
    }
}